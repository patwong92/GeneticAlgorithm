#include <iostream>
#include <random>
#include <algorithm>
#include "tour.hpp"
#include "population.hpp"

using namespace std;

/**
 * Driver to approximate the solution of the travelling salesman problem
 * @author Patrick W
 */
int main() {
    //Reads a file containing a list of cities and stores them in an object
    cities k{"cities.txt", CITIES_IN_TOUR};

    //Constructor will run the genetic algorithm to find the local minimum total distance among cities
    population pop{k, POPULATION_SIZE};
    //Runs the genetic algorithm to approximate the shortest total distance among cities
    pop.runGeneticAlgorithm();
    //Print the results after using the genetic algorithm
    pop.printResults();

    return 0;
}