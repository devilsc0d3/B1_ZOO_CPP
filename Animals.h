//
// Created by Utilisateur on 08/03/2023.
//

#ifndef B1_CPP_ZOO_ANIMALS_H
#define B1_CPP_ZOO_ANIMALS_H
#include <iostream>

using namespace  std;

class Animals {
    string name;
    int age;
    int genre;
    string food;
    int quantityFood;
    int maturity;
    int dayBeforeHunger;
    int beginReproduction;
    int endReproduction;
    int life;
    string fidelity;
public:
    Animals(string m_name):name(m_name) {
    }

    string GetName() {
        return name;
    }

};


#endif //B1_CPP_ZOO_ANIMALS_H
