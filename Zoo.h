//
// Created by faure on 21/02/2023.
//

#ifndef B1_CPP_ZOO_ZOO_H
#define B1_CPP_ZOO_ZOO_H
#include <iostream>

using namespace  std;



class Zoo {
    string name;
    int money;
    int seed, meat;
    int nbrMaxVisitor, nbrVisitor;
    int nbrPet;
    int nbrEnclosure;
    int time;

public:
    Zoo() {
        name = "ZoOdyssey";
        money = 80000;
        seed = 0; meat = 0;
        nbrMaxVisitor = 200;
        nbrVisitor = 0;
        nbrPet = 0;
        nbrEnclosure = 0;
        time = 0;
    }
};


#endif //B1_CPP_ZOO_ZOO_H
