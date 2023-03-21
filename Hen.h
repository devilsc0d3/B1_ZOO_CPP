#ifndef B1_CPP_ZOO_HEN_H
#define B1_CPP_ZOO_HEN_H
#include "Animals.h"
#include <tuple>
#include <utility>

class Hen: public Animals {
public:
    Hen(string m_name, int m_genre,std::tuple<int, int>  m_age,int m_food = 1,int m_quantity = 12): Animals(std::move(m_name),m_genre, m_age, m_food, m_quantity){
    }

    string cocot() {
        return "cocococooooooot";
    }

    double FeedMe(double seed) {
        if (seed >= 0.15){
            return -0.15;
        } else {
            //pop
            seed -= 1;
            cout << cocot() << endl;
            return 0;
        }
    }
};


#endif //B1_CPP_ZOO_HEN_H
