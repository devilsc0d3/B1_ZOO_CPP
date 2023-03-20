#ifndef B1_CPP_ZOO_ANIMALS_H
#define B1_CPP_ZOO_ANIMALS_H
#include <iostream>
#include <tuple>
#include "time.h"

using namespace  std;

class Animals {
    string name;
    tuple <int,int> age;
    int genre;
    int food;
    int quantityFood;
    int powerSex;
    int dayBeforeHunger;
    int beginReproduction;
    int endReproduction;
public:
    Animals(string m_name,int m_genre,std::tuple<int, int>  m_age, int m_food, int m_quantity) : name(m_name), age(m_age), food(m_food), genre(m_genre), quantityFood(m_quantity){
    }

    string GetName() {
        return name;
    }

    int GetYears() {
        return get<0>(age);
    }

    int GetMonth() {
        return get<1>(age);
    }

    int GetGenre() {
        return genre;
    }

    void TheTime() {
        if (get<1>(age) % 12 == 0) {
            get<0>(age) += 1;
            get<1>(age) = 0;
        }
        get<1>(age) += 1;

        if (get<0>(age) == 25) {
            cout << "mort" << endl;
            this->~Animals();
        }

    }

    ~Animals() {}
};


#endif //B1_CPP_ZOO_ANIMALS_H
