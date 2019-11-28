#include <iostream>
#include <random>
#include <algorithm>
#include "tour.hpp"
#include "population.hpp"

using namespace std;

int main() {
    cities k{"cities.txt"};
    population pop{k, POPULATION_SIZE};

    return 0;
}