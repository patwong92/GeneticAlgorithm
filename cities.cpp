//
// Created by Patrick on 2019-11-12.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include <random>
#include "cities.hpp"

cities::cities(string filename) {
    ifstream f{filename};
    string line;


    if(!f) {
        cerr << "Unable to open file" << endl;
        exit(1);
    }

    while(getline(f, line)) {
        line.pop_back(); //Erases the '/r' character
        string a_city;
        a_city = line;

        random_device rdx;
        mt19937 generator_x(rdx());
        uniform_int_distribution<> distribution_x(0, 1000);
        int latitude = distribution_x(generator_x);

        random_device rdy;
        mt19937 generator_y(rdy());
        uniform_int_distribution<> distribution_y(0, 1000);
        int longitude = distribution_y(generator_y);

        addCity(a_city, latitude, longitude);
    }
}

void cities::addCity(string a_city, int x, int y) {

    bool unique = false;

    vector<city>::iterator itBegin = listOfCities.begin();
    vector<city>::iterator itEnd = listOfCities.end();

    while (!unique) {
        unique = true;

        for (itBegin; itBegin != itEnd; itBegin++) {
            if (x == itBegin->getX() && y == itEnd->getY()) {
                unique = false;
                break;
            }
        }

        if (!unique) {
            random_device rdx;
            mt19937 generator_x(rdx());
            uniform_int_distribution<> distribution_x(0, 1000);
            x = distribution_x(generator_x);

            random_device rdy;
            mt19937 generator_y(rdy());
            uniform_int_distribution<> distribution_y(0, 1000);
            y = distribution_y(generator_y);
        }
    }

    city c{a_city, x, y};
    listOfCities.push_back(c);
}

void cities::print()
{
    vector<city>::iterator itBegin = listOfCities.begin();
    vector<city>::iterator itEnd = listOfCities.end();

    for (itBegin; itBegin != itEnd; itBegin++) {
        cout << *itBegin << endl;
    }
}