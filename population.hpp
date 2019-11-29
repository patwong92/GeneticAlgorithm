//
// Created by Patrick on 2019-11-27.
//

#ifndef GENETICALGORITHM_POPULATION_HPP
#define GENETICALGORITHM_POPULATION_HPP


#include <vector>
#include "tour.hpp"

/**
 * Population class that contains a select number of tours
 * @author Patrick W
 */
class population {
private:
    //Master list of cities
    vector<city*> master_list;
    //Population size
    int pSize;

    //Tour with the lowest distance
    tour* elite_tour;
    //Initial tour
    tour* base_tour;

    //Quality of the base tour
    double base_fitness;
    //Quality of the elite tour
    double elite_fitness;
    //Ratio between the elite_fitness and the base fitness
    double fitness_ratio;

    //Number of times the genetic algorithm is performed
    int iteration;

    //Current generation
    vector<tour*> p;
    //Next generation
    vector<tour*> nextp;
    //A set of random tours
    vector<tour*> set1;
    //Another set of random tours
    vector<tour*> set2;

public:
    /**
     * Population class
     * @param s
     *      Cities
     * @param pSize
     *      Size of the population
     */
    population(cities s, int pSize): pSize(pSize), iteration(0) {

        //Assign original cities to the master list
        master_list = s.getList();

        //Initialize a set of random tours of POPULATION_SIZE
        for (int i = 0; i < pSize; i++) {
            tour* c = new tour(s);
            p.push_back(c);
        }

        //Find the elite tour
        evaluateFitness();

        base_tour = elite_tour;
        base_fitness = elite_fitness;

        fitness_ratio = elite_fitness/base_fitness;

        //Run genetic algorithm
        while (fitness_ratio < IMPROVEMENT_FACTOR || iteration < ITERATIONS) {
            if (iteration >= ITERATIONS) {
                break;
            }

            if (fitness_ratio > IMPROVEMENT_FACTOR) {
                break;
            }

            iteration++;

            if (iteration > 1) {
                p = nextp;
                nextp.clear();
                clearSets();
            }

            //Swap elite_tour and the first index of the population of tours
            mySwap(*elite_tour, *p[0]);
            //Add to the next generation.
            nextp.push_back(p[0]);

            //Do cross tour POPULATION_SIZE - 1 times
            while (nextp.size() < pSize) {
                crossTour();
            }

            //Generate number and index of tours to mutate
            vector<int> tours_to_mutate = generateRandomTourSelection(pSize, 0.25);
            mutateSelectedTours(tours_to_mutate);

            tour* current_elite = elite_tour;
            evaluateFitness();
            tour* new_elite = elite_tour;

            fitness_ratio = elite_fitness/base_fitness;

            printIterationResult(iteration, current_elite, new_elite, fitness_ratio);
        }

    }

    /*
     * Destructor
     */
    ~population(){
        for (int i = 0; i < p.size(); i++) {
            delete p[i];
        }
    }

    //Function prototypes
    int generateRandomNumber(int, int);
    vector<int> generateRandomTourSelection(int, double);
    void mySwap(tour&, tour&);
    void clearSets();
    void crossTour();
    void evaluateFitness();
    void generateTwoRandomSets();
    void printResults();
    void printIterationResult(int, tour*, tour*, double);
    void mutateSelectedTours(vector<int>);
    void mutateTour(tour*, double);
};


#endif //GENETICALGORITHM_POPULATION_HPP
