//
// Created by Patrick on 2019-11-27.
//

#include "population.hpp"

void population::swap(tour& a, tour &b) {
    tour tmp = a;
    a = b;
    b = tmp;
}

int generateRandomNumber(int a, int b) {
    random_device rd; // a random number generator
    mt19937 generator(rd()); // calls operator()
    uniform_int_distribution<> distribution(a, b);
    int c = distribution(generator);

    return c;
}

void population::generateTwoRandomSets() {
    vector<int> number;

    clearSets();

    while (number.size() < 10) {
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

void population::clearSets() {
    set1.clear();
    set2.clear();
}

void population::crossTour() {
    generateTwoRandomSets();
    tour* elite_tour_set1 = set1[0];
    tour* elite_tour_set2 = set2[0];
    double elite_fitness_set1 = elite_tour_set1->getFitness();
    double elite_fitness_set2 = elite_tour_set2->getFitness();

    for (int i = 0; i < 5; i++) {
        if (set1[i]->getFitness() < elite_fitness_set1) {
            elite_tour_set1 = set1[i];
            elite_fitness_set1 = elite_tour_set1->getFitness();
        }

        if (set2[i]->getFitness() < elite_fitness_set2) {
            elite_tour_set2 = set2[i];
            elite_fitness_set2 = elite_tour_set2->getFitness();
        }
    }

    int random_index = generateRandomNumber(0, master_list.size() - 1);

    tour* t = new tour();

    for (int i = 0; i < random_index; i++) {
        t->addCity(elite_tour_set1->getCity(i));
    }

    for (int i = 0; i < elite_tour_set2->getCities(); i++) {
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
            t->addCity(elite_tour_set1->getCity(i));
        }
    }
    nextp.push_back(t);
}



void population::print() {
    for (unsigned int i = 0; i < p.size(); i++) {
        cout << (*p[i]).getFitness()  << endl;
    }
}

void population::printFirstTour() {
    cout << (*p[0]).getFitness() << endl;
}

void population::findEliteTour() {
    tour* elite_tour = p[0];
    elite_fitness = elite_tour->getFitness();

    for (unsigned int i = 0; i < p.size(); i++) {
        if (p[i]->getFitness() < elite_fitness) {
            elite_tour = p[i];
            elite_fitness = elite_tour->getFitness();
        }
    }

    swap(*elite_tour, *p[0]);

    nextp.push_back(elite_tour);
}

double population::getEliteFitness() {
    return elite_fitness;
}