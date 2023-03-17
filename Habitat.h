
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
    //capacite tiger,hhh
    int probabilityOfDisease;
    vector <Tiger> arrayTiger;
    vector <Eagle> arrayEagle;
    vector <Hen> arrayHen;

public:
    Habitat( int m_capacity, int m_probabilityOfDisease):capacity(m_capacity), probabilityOfDisease(m_probabilityOfDisease) {}

    void addEagle(){
        string nickname;
        cout << "choose a nickname : " << endl;
        cin >> nickname;
        arrayEagle.push_back(*new Eagle(nickname = "gerard",1,std::make_tuple(0, 0)));
    }

    void addHen(){
        string nickname;
        cout << "choose a nickname : " << endl;
        cin >> nickname;
        arrayHen.push_back(*new Hen(nickname = "gerard",1,std::make_tuple(0, 0)));
    }

    void addTiger(){
        string nickname;
        cout << "choose a nickname : " << endl;
        cin >> nickname;
        arrayTiger.push_back(*new Tiger(nickname = "gerard",1,std::make_tuple(0, 0)));
    }

    int GetNbrTiger() {
        return arrayTiger.size();
    };

    int GetNbrHen() {
        return arrayHen.size();
    };

    int GetNbrEagle() {
        return arrayEagle.size();
    };

    void SetCapacity(int nbr) {
        capacity += nbr;
        cout << "capacity : " << capacity << endl;
    }

    int GetCapacity() {
        return capacity;
    };

    void AgeOfTiger() {
        for (int i = 0 ; i < GetNbrTiger(); i++) {
            arrayTiger[i].TheTime();
            cout << "years : "<< arrayTiger[i].GetYears() << "month :" << arrayTiger[i].GetMonth() << "test" << endl;
        }
    }

};


#endif //B1_CPP_ZOO_HABITAT_H
