#ifndef B1_CPP_ZOO_ZOO_H
#define B1_CPP_ZOO_ZOO_H
#include <vector>
#include <iostream>
#include "Habitat.h"

using namespace  std;

class Zoo {
    string name;
    int money;
    int nbrMaxVisitor;
    int nbrPet;
    int nbrHabitat;
    vector <Habitat> arrayHabitat;

public:
    Zoo(string m_name, int m_money):name(m_name), money(m_money) {
        nbrMaxVisitor = 200;
        nbrMaxVisitor = 0;
        nbrPet = 0;
        nbrHabitat = 0;
    }

    void Stats() {
        cout << "\n=---------- STATS -----------=" << endl;
        cout << "name : " << name << endl;
        cout << "money : " << money << endl;
        cout << "number of pets : " << nbrPet << endl;
        cout << "number of habitat : " << nbrHabitat << endl;
        cout << "number maximum of people : " << nbrMaxVisitor << endl;
        cout << "=----------------------------=\n" << endl;

    }

    int getMoney() {
        return money;
    }
};


#endif //B;1_CPP_ZOO_ZOO_H
