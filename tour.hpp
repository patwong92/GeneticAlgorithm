//
// Created by Patrick on 2019-11-12.
//

#ifndef GENETICALGORITHM_TOUR_HPP
#define GENETICALGORITHM_TOUR_HPP

#include "cities.hpp"

class tour {
private:
    vector<city*> travel;
    double fitness;

    void shuffle_cities();
    double calculate_distance(city*, city*);
    double calculate_fitness();

public:
    tour() : fitness(0) {}

    tour(cities c) {
        travel = c.getList();

        shuffle_cities();
        fitness = calculate_fitness();
    }

    ~tour() {
        for (vector<city*>::iterator i = travel.begin(); i != travel.end(); i++) {
            delete *i;
        }
    }
    double getFitness();
    int getCities();
    void print() const;
    void addCity(city*);
    city* getCity(int);
};


#endif //GENETICALGORITHM_TOUR_HPP
