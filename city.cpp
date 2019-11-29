//
// Created by Patrick on 2019-11-12.
//

#include "city.hpp"

/**
 * Name getter
 * @return name
 *      City name
 */
string city::getName() {
    return name;
}

/**
 * Latitude getter
 * @return x
 *      Latitude
 */
int city::getX() {
    return x;
}

/**
 * Longitude getter
 * @return y
 *      Longitude
 */
int city::getY() {
    return y;
}

/**
 * Returns a description of the city, which includes the name, latitude, and longitude
 * @return result;
 *      Description of the city
 */
string city::toString() const {
    string result;
    result = name + " (" + to_string(x) + "," + to_string(y) + ") ";
    return result;
}

/**
 * Insertion operator
 * @param os
 *      ostream reference
 * @param obj
 *      city reference
 * @return os
 *      ostream reference
 */
ostream& operator<<(ostream& os, const city& obj)
{
    os << obj.toString();
    return os;
}

/**
 * Copy assignment operator
 * @param rhs
 *      A city
 * @return *this
 *      Copied city
 */
city city::operator=(city rhs) {
    mySwap(*this, rhs);
    return *this;
}

/*
 * Swaps between two city references
 * @param first
 *      City reference
 * @param second
 *      City reference
 */
void city::mySwap(city& first, city& second)
{
    using std::swap;
    swap(first.name, second.name);
    swap(first.x, second.x);
    swap(first.y, second.y);
}