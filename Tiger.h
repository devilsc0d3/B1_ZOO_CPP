#ifndef B1_CPP_ZOO_TIGER_H
#define B1_CPP_ZOO_TIGER_H
#include "Animals.h"
#include <tuple>
#include <utility>


class Tiger: public Animals {
public:
    Tiger(string m_name, int m_genre,std::tuple<int, int>  m_age,int m_food = 1,int m_quantity = 12): Animals(std::move(m_name),m_genre, m_age, m_food, m_quantity){

    }

    string roar() {
        return "RRRRooaaahh";
    };

    double FeedMe(double meat) {
        if (meat >= 12) {
            return -12;
        } else {
            //pop
            cout << roar() << endl;
            return 0;
        }
    }
};



#endif //B1_CPP_ZOO_TIGER_H
