//
// Created by Patrick on 2019-11-27.
//

#include "cities.hpp"

/**
 * Gets a vector with a list of cities
 * @return map
 *      A vector of city pointers
 */
vector<city*> cities::getList() {
    return map;
}

/**
 * Prints all the cities
 */
void cities::print() {
    for (int i = 0; i < map.size(); i++) {
        cout << *map[i] << endl;
    }
}

/**
 * Replace a selected character with another character in a string
 * @param str
 *      Initial string
 * @param ch1
 *      Character to replace
 * @param ch2
 *      Replace character with this character
 * @return str
 *      A transformed string
 */
string cities::replaceCharacters(string str, char ch1, char ch2) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ch1)
            str[i] = ch2;
    }

    return str;
}