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
    int nbrMaxVisitor, nbrVisitor;
    int nbrPet;
    int nbrEnclosure;
    int time;

public:
    Zoo(string m_name, int m_money):name(m_name), money(m_money) {
        nbrMaxVisitor = 200;
        nbrVisitor = 0;
        nbrPet = 0;
        nbrEnclosure = 0;
    }

    void Stats() {
        cout << "name : " << name << endl;
        cout << "money : " << money << endl;
        cout << "number of pets : " << nbrPet << endl;
        cout << "number maximum of people : " << nbrVisitor << endl;
    }
};


#endif //B;1_CPP_ZOO_ZOO_H
