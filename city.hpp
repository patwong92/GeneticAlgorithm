//
// Created by Patrick on 2019-11-12.
//

#ifndef GENETICALGORITHM_CITY_HPP
#define GENETICALGORITHM_CITY_HPP

#include <string>
#include <stdexcept>
#include "constants.hpp"

using namespace std;

class city {
private:
    string name;
    int x;
    int y;
public:
    city(string name, int x, int y): name(name), x(x), y(y) {
        if (x > MAP_BOUNDARY || x < 0 || y > MAP_BOUNDARY || y < 0)
            throw invalid_argument("Invalid coordinates!");
    }

    void mySwap(city& first, city& second);city operator=(city rhs);

    string getName();
    int getX();
    int getY();
    friend ostream& operator<<(ostream& os, const city& obj);
    string toString() const;
};


#endif //GENETICALGORITHM_CITY_HPP
