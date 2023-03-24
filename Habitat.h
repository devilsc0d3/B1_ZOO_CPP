
#ifndef B1_CPP_ZOO_HABITAT_H
#define B1_CPP_ZOO_HABITAT_H
#include <utility>
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

    void addEagle(string nickname,int genre,tuple<int, int>age){
        animals.push_back(new Eagle(std::move(nickname),genre,age));
    }

    void addHen(string nickname,int genre,tuple<int, int>age){
        animals.push_back(new Hen(std::move(nickname),genre,age));
    }

    void addTiger(string nickname,int genre,tuple<int, int>age){
        animals.push_back(new Tiger(std::move(nickname),genre,age));
    }

    int GetNbr() {
        return animals.size();
    };


    [[nodiscard]] int GetCapacity() const {
        return capacity;
    };

    void SetCapacity(int nbr) {
        capacity += nbr;
        cout << "capacity : " << capacity << endl;
    }

    string SetAName() {
        cout << "choose a nickname : " << endl;
        string nickname;
        cin >> nickname;
        return nickname;
    }

    void removeLast(){
        if (!animals.empty()) {
           delete animals.back();
           animals.pop_back();
        }
    }

    vector<Animals*>& GetArray() {
        return animals;
    }

    void NameOfAnimals(const string& type) {
        for (int i = 0 ; i < GetNbr(); i++) {
            cout << type << i << " :" << animals[i]->GetName() << endl;
        }
    }

};

#endif //B1_CPP_ZOO_HABITAT_H
