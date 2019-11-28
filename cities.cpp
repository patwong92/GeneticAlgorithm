//
// Created by Patrick on 2019-11-27.
//

#include "cities.hpp"

vector<city*> cities::getList() {
    return map;
}

void cities::print() {
    for (int i = 0; i < map.size(); i++) {
        cout << *map[i] << endl;
    }
}

string cities::replaceCharacters(string str, char ch1, char ch2) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ch1)
            str[i] = ch2;
    }

    return str;
}