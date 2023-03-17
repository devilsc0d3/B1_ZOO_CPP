//
// Created by Utilisateur on 27/02/2023.
//

#ifndef B1_CPP_ZOO_TIME_H
#define B1_CPP_ZOO_TIME_H

#include <iostream>
#include <string>

using namespace std;

class Time {
    int year;
    int month;

public:
    Time() : year(0), month(1) {}

    void skip() {
        month = (month % 12) + 1;
        if (month == 1) {
            year += 1;
        }
    }

    string toString() const {
        static const string months[] = {"January", "February", "March", "April", "May", "June", "July",
                                        "August", "September", "October", "November", "December"};
        return months[month - 1] + " " + to_string(year);
    }

    int getMonth() {
        return month;
    }
};


#endif //B1_CPP_ZOO_TIME_H
