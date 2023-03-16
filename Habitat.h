
#ifndef B1_CPP_ZOO_HABITAT_H
#define B1_CPP_ZOO_HABITAT_H
#include <vector>
#include <iostream>
#include "Animals.h"
#include "Tiger.h"

using namespace  std;

class Habitat {
    int capacity;
    int probabilityOfDisease;
    vector <Tiger> arrayTiger;

public:
    Habitat( int m_capacity, int m_probabilityOfDisease):capacity(m_capacity), probabilityOfDisease(m_probabilityOfDisease) {}

    void addEagle(){
        string nickname;
        cin >> nickname;
        arrayEagle.push_back(*new Eagle(nickname));
        cout << arrayEagle[0].GetName() << endl;
        //TODO : fill parameter of function
    }
    void addHen(){
        string nickname;
        cin >> nickname;
        arrayHen.push_back(*new Hen(nickname));
        cout << arrayHen[0].GetName() << endl;
        //TODO : fill parameter of function
    }
    void addTiger(){
        string nickname;
        cin >> nickname;
        arrayTiger.push_back(*new Tiger(nickname));
        cout << arrayTiger[0].GetName() << endl;
        //TODO : fill parameter of function
    }

    int GetNbrTiger() {
        return arrayTiger.size();
    };

    int GetNbrEagle() {
        return arrayEagle.size();
    };

    int GetNbrHen() {
        return arrayHen.size();
    };

    void SetCapacity(int nbr) {
        capacity += nbr;
        cout << "capacity : " << capacity << endl;
    }

    int GetCapacity() {
        return capacity;
    };

};


#endif //B1_CPP_ZOO_HABITAT_H
