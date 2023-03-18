
#ifndef B1_CPP_ZOO_HABITAT_H
#define B1_CPP_ZOO_HABITAT_H
#include <vector>
#include <iostream>
#include "Animals.h"
#include "Tiger.h"
#include "Eagle.h"
#include "Hen.h"

using namespace  std;

class Habitat {
    int capacity;
    int probabilityOfDisease;
    vector<Animals*> animals;

public:
    Habitat( int m_capacity, int m_probabilityOfDisease):capacity(m_capacity), probabilityOfDisease(m_probabilityOfDisease) {}

    void addEagle(string nickname){
        animals.push_back(new Eagle(nickname,1,std::make_tuple(0, 0)));
    }

    void addHen(string nickname){
        animals.push_back(new Hen(nickname,1,std::make_tuple(0, 0)));
    }

    void addTiger(string nickname){
        animals.push_back(new Tiger(nickname,1,std::make_tuple(0, 0)));
    }

    int GetNbr() {
        return animals.size();
    };

    void SetCapacity(int nbr) {
        capacity += nbr;
        cout << "capacity : " << capacity << endl;
    }

    int GetCapacity() {
        return capacity;
    };

    string SetAName() {
        string nickname;
        cout << "choose a nickname for the tiger: " << endl;
        cin >> nickname;
        return nickname;
    }

    void removeLast(){
        if (!animals.empty()) {
           delete animals.back();
            animals.pop_back();
        }
    }

    void AgeOfAnimals() {
        for (int i = 0 ; i < GetNbr(); i++) {
            cout << "years : "<< animals[i]->GetYears() << "month :" << animals[i]->GetMonth() << "test" << endl;
        }
    }

    void NameOfAnimals(string type) {
        for (int i = 0 ; i < GetNbr(); i++) {
            cout << type << i << " :" << animals[i]->GetName() << endl;
        }
    }

};


#endif //B1_CPP_ZOO_HABITAT_H
