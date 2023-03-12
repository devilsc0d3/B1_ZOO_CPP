
#ifndef B1_CPP_ZOO_HABITAT_H
#define B1_CPP_ZOO_HABITAT_H
#include <vector>
#include <iostream>

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
        //TODO : fill parameter of function
    }
    void addTiger(){
        //TODO : fill parameter of function
    }

    int GetNbrAnimals() {
        return arrayAnimals.size();
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
