//
// Created by Patrick on 2019-11-27.
//

#ifndef GENETICALGORITHM_CITIES_HPP
#define GENETICALGORITHM_CITIES_HPP

#include <random>
#include <iostream>
#include <fstream>
#include <sstream>
#include "city.hpp"

/**
 * Cities class
 * @author Patrick W
 */
class cities {
private:
    vector<city*> map;
    string replaceCharacters(string, char, char);
public:
    /**
     * Cities constructor
     * @param filename
     *      A string representing the file name
     * @param num_of_cities
     *      Number of cities to read from file
     */
    cities(string filename, int num_of_cities) {
        ifstream f{filename};
        string line;

        if(!f) {
            cerr << "Unable to open file" << endl;
            exit(1);
        }

        int n = 0;

        while(getline(f, line) && n < num_of_cities) {
            line.pop_back(); //Erases the '/r' character
            istringstream iss{line};
            string a_city;
            int latitude;
            int longitude;

            iss >> a_city;
            a_city = replaceCharacters(a_city, '_', ' ');

            iss >> latitude;
            iss >> longitude;

            city* c = new city(a_city, latitude, longitude);
            map.push_back(c);
            n++;
        }
    }

    //Function prototypes
    vector<city*> getList();
    void print();
};


#endif //GENETICALGORITHM_CITIES_HPP
