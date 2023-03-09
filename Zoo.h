#ifndef B1_CPP_ZOO_ZOO_H
#define B1_CPP_ZOO_ZOO_H
#include <vector>
#include <iostream>
#include "Habitat.h"

using namespace  std;

class Zoo{
    string name;
    int money;
    int nbrMaxVisitor;
    int nbrPet;
    int nbrHabitat;
    Habitat* hen = new Habitat(10,4);
    Habitat* eagle = new Habitat(4,1);
    Habitat* tiger = new Habitat(2,1);

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

    void AddHabitatEagle() {
        int price = 2000;
        if (money > price) {
            money -= price;
            eagle->SetCapacity(4);
            cout << "you got a good deal !" << endl;
        } else {
        cout << "NO Money, You're too poor !!!" << endl;
        }

        cout << "\n     --test aigle --" << endl;
        cout << money << endl;
    };

    void AddHabitatPoule() {
        int price = 2000;
        if (money > price) {
            money -= price;
            hen->SetCapacity(10);
            cout << "you got a good deal !" << endl;
        } else {
        cout << "NO Money, You're too poor !!!" << endl;
        }

        cout << "\n     --test Poule --" << endl;
        cout << money << endl;
    };

    void AddHabitatTiger() {
        int price = 2000;
        if (money > price) {
            money -= price;
            tiger->SetCapacity(2);
            cout << "you got a good deal !" << endl;
        } else {
        cout << "NO Money, You're too poor !!!" << endl;
        }

        cout << "\n     --test tiger -- " << endl;
        cout << money << endl;
    };
};


#endif //B;1_CPP_ZOO_ZOO_H
