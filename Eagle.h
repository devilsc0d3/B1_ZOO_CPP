#ifndef B1_CPP_ZOO_EAGLE_H
#define B1_CPP_ZOO_EAGLE_H
#include "Animals.h"
#include <tuple>
#include <utility>

class Eagle: public Animals {
    string fidelity;
public:
    Eagle(string m_name, int m_genre,std::tuple<int, int>  m_age,int m_food = 1,int m_quantity = 12): Animals(std::move(m_name),m_genre, m_age, m_food, m_quantity){}

    void coupling(string name){
        fidelity = std::move(name);
    }
};


#endif //B1_CPP_ZOO_EAGLE_H
