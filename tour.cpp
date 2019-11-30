//
// Created by Patrick on 2019-11-12.
//

#include <chrono>
#include <random>
#include <algorithm>
#include <iostream>
#include <fstream>
#include "tour.hpp"

using namespace std;

/**
 * Shuffles the cities in a tour
 */
void tour::shuffleCities()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(travel.begin(), travel.end(), std::default_random_engine(seed));
}

/**
 * Calculates the distance between two cities using the distance formula
 * @param a
 *      A pointer to a city
 * @param b
 *      A pointer to another city
 * @return distance
 *      Distance between two cities
 */
double tour::calculateDistance(city* a, city* b)
{
    double delta_x = abs(a->getX() - b->getX());
    double delta_y = abs(a->getY() - b->getY());

    double distance = sqrt(pow(delta_x, 2) + pow(delta_y, 2));
    return distance;
}

/**
 * Calculates the total distance in a tour and returns the value
 * @return total_distance
 *      Total distance in a tour
 */
double tour::getTotalDistance()
{
    total_distance = 0;

    if (travel.size() > 1) {
        for (int i = 0; i < (travel.size() - 1); i++) {
            total_distance += calculateDistance(travel[i], travel[i+1]);
        }

        //Adds the distance between the first and last cities in a tour to complete the tour
        total_distance += calculateDistance(travel[travel.size()-1] , travel[0]);
    }

    return total_distance;
}

/**
 * Getter for the total distance
 * @return total_distance
 *      Total distance in a tour
 */
double tour::getTheTotalDistance() {
    return total_distance;
}

/**
 * Adds the city to a tour
 * @param c
 *      A pointer to a city
 */
void tour::addCity(city* c)
{
    travel.push_back(c);

    if (travel.size() > 1) {
        getTotalDistance();
        getFitness();
    }
}

/**
 * Swaps two tours
 * @param first
 *      Tour reference
 * @param second
 *      Another tour reference
 */
void tour::mySwap(tour& first, tour& second)
{
    using std::swap;
    swap(first.travel, second.travel);
    swap(first.total_distance, second.total_distance);
    swap(first.fitness, second.fitness);
}

/**
 * Copy assignment operator
 * @param rhs
 *      A tour
 * @return *this
 *      A copy of the tour
 */
tour tour::operator=(tour rhs) {
    mySwap(*this, rhs);
    return *this;
}

/**
 * Returns the city at a given index in a tour
 * @param index
 *      Index of a tour
 * @return travel[index]
 *      A pointer to the city at a given index
 */
city* tour::getCity(int index) {
    return travel[index];
}

/**
 * Gets the number of cities in the tour
 * @return travel.size()
 *      Number of cities
 */
int tour::getCities() {
    return travel.size();
}

/**
 * Gets the fitness of a tour
 * @return fitness
 *      Quality of the tour
 */
double tour::getFitness() {
    if (total_distance > 0) {
        fitness = (double) SCALAR_CONSTANT / total_distance;
    }

    return fitness;
}
