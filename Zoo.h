#ifndef B1_CPP_ZOO_ZOO_H
#define B1_CPP_ZOO_ZOO_H
#include <vector>
#include <iostream>
#include "Habitat.h"

using namespace  std;

class Zoo{
    string name;
    float money;
    int nbrMaxVisitor;
    int nbrVisitor;
    int nbrPet;
    int nbrHabitat;
    float seed;
    float meal;
    Habitat* hen = new Habitat(10,4);
    Habitat* eagle = new Habitat(4,1);
    Habitat* tiger = new Habitat(2,1);

public:
    Zoo(string m_name, float m_money):name(m_name), money(m_money) {
        nbrMaxVisitor = 200;
        nbrVisitor = 0;
        seed = 0;
        meal = 0;
        nbrPet = 0;
        nbrHabitat = 0;
    }

    void Stats() {
        cout << "\n=---------- STATS -----------=" << endl;
        cout << "name : " << name << endl;
        cout << "money : " << money << endl;
        cout << "seed in kg : " << seed << endl;
        cout << "meal in kg : " << meal << endl;
        cout << "number of pets : " << nbrPet << endl;
        cout << "number of habitat : " << nbrHabitat << endl;
        cout << "number maximum of people : " << nbrMaxVisitor << endl;
        cout << "number of people in the month : " << nbrVisitor << endl;
        cout << "=----------------------------=\n" << endl;
    }

    void AddHabitatEagle() {
        float price = 2000;
        if (money > price) {
            money -= price;
            nbrHabitat++;
            eagle->SetCapacity(4);
            cout << "you got a good deal !" << endl;
        } else {
        cout << "NO Money, You're too poor !!!" << endl;
        }
    };

    void AddHabitatHen() {
        float price = 2000;
        if (money > price) {
            money -= price;
            nbrHabitat++;
            hen->SetCapacity(10);
            cout << "you got a good deal !" << endl;
        } else {
        cout << "NO Money, You're too poor !!!" << endl;
        }
    };

    void AddHabitatTiger() {
        float price = 2000;
        if (money > price) {
            money -= price;
            nbrHabitat++;
            tiger->SetCapacity(2);
            cout << "you got a good deal !" << endl;
        } else {
        cout << "NO Money, You're too poor !!!" << endl;
        }
    };

    void addSeed() {
        float kilos;
        float price = 2.5;
        cout << "How many kilos do you want sir ?" << endl;
        cin >> kilos;
        if (kilos * price < money) {
            money -= kilos * price;
            seed += kilos;
        } else {
            cout << "NO Money, You're too poor !!!" << endl;
        }

    }
    void addMeal() {
        float kilos;
        float price = 5;
        cout << "How many kilos do you want sir ?" << endl;
        cin >> kilos;
        if (kilos * price < money) {
            money -= kilos * price;
            meal += kilos;
        } else {
            cout << "NO Money, You're too poor !!!" << endl;
        }
    }

    void SellHabitatTiger() {
        if (tiger->GetCapacity() > 1 || (tiger->GetCapacity() >= 2 && tiger->GetNbrAnimals() == 0)) {
            money += 500;
            tiger->SetCapacity(-2);
            cout << "you got a good deal !" << endl;
        }  else if (eagle->GetCapacity() == 0) {
            cout << "Crii crii crii, there is no more habitat" << endl;
        } else {
        cout << "NO, NO to animals on the street !!!" << endl;
        }
    };

    void SellHabitatEagle() {
        if (eagle->GetCapacity() > 4 || (eagle->GetCapacity() >= 4 && eagle->GetNbrAnimals() == 0)) {
            money += 500;
            eagle->SetCapacity(-4);
            cout << "you got a good deal !" << endl;
        } else if (eagle->GetCapacity() == 0) {
            cout << "Crii crii crii, there is no more habitat" << endl;
        } else {
        cout << "NO, NO to animals on the street !!!" << endl;
        }
    };

    void SellHabitatHen() {
        cout << "argent : " << money << endl;
        if (hen->GetCapacity() > 1 || (hen->GetCapacity() >= 10 && hen->GetNbrAnimals() == 0)) {
            money += 50;
            hen->SetCapacity(-10);
            cout << "you got a good deal !" << endl;
        }  else if (eagle->GetCapacity() == 0) {
            cout << "Crii crii crii, there is no more habitat" << endl;
        } else {
        cout << "NO, NO to animals on the street !!!" << endl;
        }

        cout << "argent : " << money << endl;
    };
};


#endif //B;1_CPP_ZOO_ZOO_H
