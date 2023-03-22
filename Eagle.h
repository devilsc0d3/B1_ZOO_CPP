#ifndef B1_CPP_ZOO_EAGLE_H
#define B1_CPP_ZOO_EAGLE_H
#include "Animals.h"
#include <tuple>
#include <utility>

class Eagle: public Animals {
    int max_age = 25;
    string fidelity;
    int gestation_time = 45;

public:
    Eagle(string m_name, int m_genre,std::tuple<int, int>  m_age,int m_food = 1,int m_quantity = 12): Animals(std::move(m_name),m_genre, m_age, m_food, m_quantity){}

    void coupling(string name){
        fidelity = std::move(name);
    }

    void gestation() {
        gestation_time--;
        if (gestation_time == 0) {
            cout << "a new animal !"<< endl;
        }
    }

    string bigcocot() {
        return "Yyyaaaaahhh";
    }

    double FeedMe(double meat) {
        if (meat >= 5) {
            return -5;
        } else {
            //pop
            cout << bigcocot() << endl;
            return 0;
        }
    }

    void theDead() {
        if (this->GetYears() >= max_age) {
            cout << "mort" << endl;
        }
    }
};


#endif //B1_CPP_ZOO_EAGLE_H
