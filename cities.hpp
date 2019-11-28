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

class cities {
private:
    vector<city*> map;
    string replaceCharacters(string, char, char);
public:
    cities(string filename) {
        ifstream f{filename};
        string line;

        if(!f) {
            cerr << "Unable to open file" << endl;
            exit(1);
        }

        while(getline(f, line)) {
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
        }
    }

    vector<city*> getList();
    void print();
};


#endif //GENETICALGORITHM_CITIES_HPP
