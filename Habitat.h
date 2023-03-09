//
// Created by faure on 27/02/2023.
//

#ifndef B1_CPP_ZOO_HABITAT_H
#define B1_CPP_ZOO_HABITAT_H
#include <vector>
#include <iostream>
//animals h
using namespace  std;

class Habitat {
    int capacity;
    int probabilityOfDisease;
    vector <Habitat> arrayAnimals;

public:
    Habitat( int m_capacity, int m_probabilityOfDisease):capacity(m_capacity), probabilityOfDisease(m_probabilityOfDisease) {}

    void addEagle(){
        //TODO : fill parameter of function
    }
    void addHen(){

    }
    void addTiger(){

    }

    void SetCapacity(int nbr) {
        capacity += nbr;
        cout << "capacity : " << capacity << endl;
    }

};


#endif //B1_CPP_ZOO_HABITAT_H
