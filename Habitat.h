
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
        //TODO : fill parameter of function
    }
    void addHen(){
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

    void SetCapacity(int nbr) {
        capacity += nbr;
        cout << "capacity : " << capacity << endl;
    }

    int GetCapacity() {
        return capacity;
    };

};


#endif //B1_CPP_ZOO_HABITAT_H
