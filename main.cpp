#include <iostream>
#include <random>
#include "cities.hpp"

using namespace std;

int main() {

    cities c{"cities.txt"};
    c.print();

    return 0;
}