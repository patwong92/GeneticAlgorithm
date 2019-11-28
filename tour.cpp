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


void tour::shuffle_cities() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(travel.begin(), travel.end(), std::default_random_engine(seed));
}

double tour::calculate_distance(city* a, city* b) {
    double delta_x = abs(a->getX() - b->getX());
    double delta_y = abs(a->getY() - b->getY());

    double distance = sqrt(pow(delta_x, 2) + pow(delta_y, 2));
    return distance;
}

double tour::calculate_fitness() {
    double total_distance = 0;

    for (int i = 0; i < (travel.size() - 1); i++) {
        total_distance += calculate_distance(travel[i], travel[i+1]);
    }

    total_distance += calculate_distance(travel[0], travel[travel.size()-1]);

    return total_distance;
}

double tour::getFitness() {
    return fitness;
}

void tour::print() const
{
    for (int i = 0; i < travel.size(); i++) {
        cout << *travel[i] << endl;
    }
}

void tour::addCity(city* c) {
    travel.push_back(c);

    if (travel.size() > 1) {
        fitness = calculate_fitness();
    }
}

void tour::mySwap(tour& first, tour& second)
{
    using std::swap;
    swap(first.travel, second.travel);
    swap(first.fitness, second.fitness);
}

tour tour::operator=(tour rhs) {
    mySwap(*this, rhs);
    return *this;
}

city* tour::getCity(int index) {
    return travel[index];
}

int tour::getCities() {
    return travel.size();
}
