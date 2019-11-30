//
// Created by Patrick on 2019-11-12.
//

#ifndef GENETICALGORITHM_CITY_HPP
#define GENETICALGORITHM_CITY_HPP

#include <string>
#include <stdexcept>
#include "constants.hpp"

using namespace std;

/**
 * City class
 */
class city {
private:
    //Name of the city
    string name;
    //Latitude
    int x;
    //Longitude
    int y;
public:
    /**
     * City constructor
     * @param name
     *      Name of the city
     * @param x
     *      Latitude
     * @param y
     *      Longitude
     */
    city(string name, int x, int y): name(name), x(x), y(y) {
        if (x > MAP_BOUNDARY || x < 0 || y > MAP_BOUNDARY || y < 0)
            throw invalid_argument("Invalid coordinates!");
    }

    //Function prototypes
    void mySwap(city&, city&);
    city operator=(city);
    string getName();
    int getX();
    int getY();
    friend ostream& operator<<(ostream&, const city&);
    string toString() const;
    friend bool operator==(const city&, const city&);
    friend bool operator!=(const city&, const city&);
};



#endif //GENETICALGORITHM_CITY_HPP
