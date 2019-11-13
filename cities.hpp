//
// Created by Patrick on 2019-11-12.
//

#ifndef GENETICALGORITHM_CITIES_HPP
#define GENETICALGORITHM_CITIES_HPP

#include <vector>
#include "city.hpp"

class cities {
private:
    vector<city> listOfCities;
public:
    cities(string filename);
    void print();
    void addCity(string c, int x, int y);
};


#endif //GENETICALGORITHM_CITIES_HPP
