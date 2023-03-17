//
// Created by faure on 14/03/2023.
//

#ifndef B1_CPP_ZOO_TIGER_H
#define B1_CPP_ZOO_TIGER_H
#include "Animals.h"
#include <tuple>


class Tiger: public Animals {
public:
    Tiger(string m_name, int m_genre,std::tuple<int, int>  m_age,int m_food = 1,int m_quantity = 12): Animals(m_name,m_genre, m_age, m_food, m_quantity){

    }
};



#endif //B1_CPP_ZOO_TIGER_H
