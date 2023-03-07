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
    vector <Habitat> arrayAigle;
    vector <Habitat> arrayTiger;
    vector <Habitat> arrayPoule;

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

    void AddHabitatAigle() {
        int price = 2000;
        if (money > price) {
            money -= price;
            Habitat newHabitat;
            arrayAigle.push_back(newHabitat);
            cout << "you got a good deal !" << endl;
        } else {
        cout << "NO Money, You're too poor !!!" << endl;
        }

        cout << "\n     --test aigle --" << endl;
        cout << money << endl;
        cout << arrayAigle.size() << endl;
    };

    void AddHabitatPoule() {
        int price = 2000;
        if (money > price) {
            money -= price;
            Habitat newHabitat;
            arrayPoule.push_back(newHabitat);
            cout << "you got a good deal !" << endl;
        } else {
        cout << "NO Money, You're too poor !!!" << endl;
        }

        cout << "\n     --test Poule --" << endl;
        cout << money << endl;
        cout << arrayPoule.size() << endl;
    };

    void AddHabitatTiger() {
        int price = 2000;
        if (money > price) {
            money -= price;
            Habitat newHabitat;
            arrayTiger.push_back(newHabitat);
            cout << "you got a good deal !" << endl;
        } else {
        cout << "NO Money, You're too poor !!!" << endl;
        }

        cout << "\n     --test tiger -- " << endl;
        cout << money << endl;
        cout << arrayTiger.size() << endl;
    };
};


#endif //B;1_CPP_ZOO_ZOO_H
