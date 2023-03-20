#ifndef B1_CPP_ZOO_TIME_H
#define B1_CPP_ZOO_TIME_H

#include <iostream>
#include <string>

using namespace std;

class Time {
    int year;
    int month;
    int day;

public:
    Time() : year(0), month(1), day(1) {}

    void skip() {
        day = (day % 31) + 1;
        if (day == 1) {
            month += 1;
        }
        if (month -12 == 1) {
            month = 1;
            year += 1;
        }
    }

    string toString() const {
        static const string months[] = {"January", "February", "March", "April", "May", "June", "July",
                                        "August", "September", "October", "November", "December"};
        return months[month - 1] + " " + to_string(year);
    }

    int getDay() {
        return day;
    }

    int getMonth() {
        return month;
    }

    int getYears() {
        return year;
    }
};


#endif //B1_CPP_ZOO_TIME_H
