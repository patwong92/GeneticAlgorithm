//
// Created by Patrick on 2019-11-12.
//

#ifndef GENETICALGORITHM_TOUR_HPP
#define GENETICALGORITHM_TOUR_HPP

#include "cities.hpp"

/**
 * Tour class
 * @author Patrick W
 */
class tour {
private:
    vector<city*> travel;
    double total_distance;
    double fitness;

public:
    /**
     * Default constructor
     */
    tour() : total_distance(0) {}

    /**
     * Overloaded constructor
     * @param cities c
     *      Class that contains all the cities
     */
    tour(cities c) {
        travel = c.getList();
        shuffleCities();
        getTotalDistance();
        getFitness();
    }

    /**
     * Destructor
     */
    ~tour() {}

    //Function prototypes
    void shuffleCities();
    double calculateDistance(city*, city*);
    double getTotalDistance();
    double getTheTotalDistance();
    void mySwap(tour& first, tour& second);
    tour operator=(tour rhs);
    double getFitness();
    int getCities();
    void addCity(city*);
    city* getCity(int);
};


#endif //GENETICALGORITHM_TOUR_HPP
