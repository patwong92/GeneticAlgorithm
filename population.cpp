//
// Created by Patrick on 2019-11-27.
//

#include <iomanip>
#include "population.hpp"

using namespace std;

/**
 * Swaps two tours
 * @param a
 *      Tour reference
 * @param b
 *      Tour reference
 */
void population::mySwap(tour& a, tour &b)
{
    tour tmp = a;
    a = b;
    b = tmp;
}

/**
 * Generates a random number between two numbers inclusive
 * @param a
 *      An integer
 * @param b
 *      Another integer
 * @return c
 *      A random integer
 */
int population::generateRandomNumber(int a, int b)
{
    random_device rd; // a random number generator
    mt19937 generator(rd()); // calls operator()
    uniform_int_distribution<> distribution(a, b);
    int c = distribution(generator);

    return c;
}

/**
 * Generates two random sets of tours of size PARENT_POOL_SIZE each
 */
void population::generateTwoRandomSets()
{
    vector<int> number;

    clearSets();

    while (number.size() < PARENT_POOL_SIZE*2) {
        bool unique = true;
        int random_index = generateRandomNumber(1, pSize - 1);

        for (unsigned int i = 0; i < number.size(); i++) {
            if (random_index == number[i]) {
                unique = false;
                break;
            }
        }

        if (unique) {
            number.push_back(random_index);
        }
    }

    for (unsigned int i = 0; i < number.size(); i++) {
        int n1 = number[i];
        set1.push_back(p[n1]);
        int n2 = number[++i];
        set2.push_back(p[n2]);
    }
}

/**
 * Removes all entries from the 2 sets
 */
void population::clearSets()
{
    set1.clear();
    set2.clear();
}

/**
 * Select the best tour from each subset and randomly combines the order of cities into a single tour
 */
void population::crossTour()
{
    generateTwoRandomSets();
    tour* elite_tour_set1 = set1[0];
    tour* elite_tour_set2 = set2[0];
    double elite_fitness_set1 = elite_tour_set1->getFitness();
    double elite_fitness_set2 = elite_tour_set2->getFitness();

    for (int i = 0; i < 5; i++) {
        if (set1[i]->getFitness() > elite_fitness_set1) {
            elite_tour_set1 = set1[i];
            elite_fitness_set1 = elite_tour_set1->getFitness();
        }

        if (set2[i]->getFitness() > elite_fitness_set2) {
            elite_tour_set2 = set2[i];
            elite_fitness_set2 = elite_tour_set2->getFitness();
        }
    }

    int random_index = generateRandomNumber(0, master_list.size() - 1);

    tour* t = new tour();

    for (int i = 0; i < random_index; i++) {
        city* unvisited_city = elite_tour_set1->getCity(i);
        t->addCity(unvisited_city);
    }

    int numOfCities = elite_tour_set2->getCities();

    for (int i = 0; i < numOfCities; i++) {
        bool unique = true;

        city* c = elite_tour_set2->getCity(i);
        string city_name = c->getName();

        for (int j = 0; j < t->getCities(); j++) {
            string visited_city = t->getCity(j)->getName();
            if (city_name == visited_city) {
                unique = false;
                break;
            }
        }

        if (unique) {
            t->addCity(elite_tour_set2->getCity(i));
        }
    }
    nextp.push_back(t);
}

/**
 * Prints the final result of the genetic algorithm
 */
void population::printResults() {
    cout << "=====================================================" << endl;
    cout << "\t\t\t\t\tFINAL RESULT" << endl;
    cout << "=====================================================" << endl;
    cout << "Number of iterations: " << iteration << endl;
    cout << "Base distance: " << (SCALAR_CONSTANT/base_fitness) << endl;
    cout << "Best distance: " <<  (SCALAR_CONSTANT/elite_fitness) << endl;
    string improvement = fitness_ratio > IMPROVEMENT_FACTOR? "yes" : "no";
    cout << "Improvement factor of at least " << IMPROVEMENT_FACTOR*100 << "% achieved? " << improvement  << endl;
    cout << "Base route:" << setw(30) << "Best route:" << endl;
    for (int i = 0; i < CITIES_IN_TOUR; i++) {
        cout << left << setw(30) << *base_tour->getCity(i) << setfill(' ')
        << setw(30) << *elite_tour->getCity(i) << endl;
    }
}

/**
 * Searches the elite tour in a population and swaps it to the first index
 */
void population::evaluateFitness()
{
    elite_tour = p[0];
    elite_fitness = elite_tour->getFitness();

    for (unsigned int i = 0; i < p.size(); i++) {
        if (p[i]->getFitness() > elite_fitness) {
            elite_tour = p[i];
            elite_fitness = elite_tour->getFitness();
        }
    }
}

/**
 * Given a mutation rate, a select number of tours in a population will be mutated
 * @param num_of_tours
 *      Number of tours in the population.
 * @param tour_mutation_rate
 *      A decimal between 0 and 1 to represent the rate of mutation in a population
 * @return mutation_selection
 *      A vector containing integers of random numbers
 */
vector<int> population::generateRandomTourSelection(int num_of_tours, double tour_mutation_rate)
{
    vector<int> mutation_selection;

    int tours_to_mutate = tour_mutation_rate*(num_of_tours);

    while (mutation_selection.size() < tours_to_mutate) {
        bool unique = true;
        //Elite tour is excluded from the selection; in other words, index 0 is excluded
        int random_num = generateRandomNumber(1, num_of_tours - 1);

        //Exclude index 0, which is the elite tour index
        for (unsigned int i = 0; i < mutation_selection.size(); i++) {
            if (random_num == mutation_selection[i]) {
                unique = false;
                break;
            }
        }

        if (unique) {
            mutation_selection.push_back(random_num);
        }
    }

    int n = mutation_selection.size();
    //Sort the array using Bubble sort
    for (int i = 0; i < (n - 1); i++) {
        for (int j = 0; j < (n - 1 - i); j++) {
            if (mutation_selection[j] > mutation_selection[j+1])
                swap(mutation_selection[j],mutation_selection[j+1]);
        }
    }

    return mutation_selection;
}

/**
 * Mutate all tours given from the mutation_selection vector
 * @param v
 *      Vector of integers
 */
void population::mutateSelectedTours(vector<int> v)
{
    for (int i = 0; i < v.size(); i++) {
        int index = v[i];

        mutateTour(nextp[index], MUTATION_RATE);
    }
}

/**
 * Mutate the tour
 * @param mutate_tour
 *      pointer to a tour
 * @param mutation_rate
 *      A double representing the mutation rate
 */
void population::mutateTour(tour* mutate_tour, double mutation_rate)
{
    for (int i = 0; i < mutate_tour->getCities(); i++) {
        double random_value = (double) generateRandomNumber(0, 100)/100;

        if (random_value < mutation_rate) {
            int swap_direction = generateRandomNumber(0, 1);

            if (swap_direction == 1) {
                if (i < mutate_tour->getCities() - 1) {
                    swap(*mutate_tour->getCity(i), *mutate_tour->getCity(i+1));
                } else {
                    swap(*mutate_tour->getCity(i), *mutate_tour->getCity(i-1));
                }
            } else {
                if (i > 0) {
                    swap(*mutate_tour->getCity(i), *mutate_tour->getCity(i-1));
                } else {
                    swap(*mutate_tour->getCity(i), *mutate_tour->getCity(i+1));
                }
            }
        }
    }

    //Calculate fitness of mutated tour
    mutate_tour->getTotalDistance();
    mutate_tour->getFitness();
}

/**
 * Print the result of each iteration
 * @param i
 *      Iteration number
 * @param current_elite
 *      Initial elite tour in the iteration
 * @param new_elite
 *      Final elite tour in the iteration
 * @param f
 *      Fitness ratio
 */
void population::printIterationResult(int i, tour* current_elite, tour* new_elite, double f) {
    cout << "Iteration number: " << i << endl;
    cout << "Best iteration distance: " << current_elite->getTheTotalDistance() << endl;
    cout << "Best distance: " << new_elite->getTheTotalDistance() << endl;
    string improvement = new_elite->getFitness() > current_elite->getFitness()? "yes" : "no";
    cout << "Is there improvement? " << improvement << endl;
    cout << "Improvement over base ratio: " << f << endl;
}