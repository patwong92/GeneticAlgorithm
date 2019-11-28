//
// Created by Patrick on 2019-11-27.
//

#ifndef GENETICALGORITHM_POPULATION_HPP
#define GENETICALGORITHM_POPULATION_HPP


#include <vector>
#include "tour.hpp"

class population {
private:
    vector<city*> master_list;
    int pSize;
    double elite_fitness;
    vector<tour*> p;

    vector<tour*> nextp;
    vector<tour*> set1;
    vector<tour*> set2;

public:
    population(cities s, int pSize): pSize(pSize) {
        master_list = s.getList();

        for (int i = 0; i < pSize; i++) {
            tour* c = new tour(s);
            p.push_back(c);
        }
    }

    int generateRandomNumber(int, int);
    void swap(tour&, tour&);
    void clearSets();
    void crossTour();
    void findEliteTour();
    double getEliteFitness();
    void generateTwoRandomSets();
    void printFirstTour();
    void print();
};


#endif //GENETICALGORITHM_POPULATION_HPP
