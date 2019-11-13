//
// Created by Patrick on 2019-11-12.
//

#include "city.hpp"

string city::getName() {
    return name;
}

int city::getX() {
    return x;
}

int city::getY() {
    return y;
}

string city::toString() const {
    string result;
    result = name + " (" + to_string(x) + "," + to_string(y) + ") ";
    return result;
}

ostream& operator<<(ostream& os, const city& obj)
{
    os << obj.toString();
    return os;
}
