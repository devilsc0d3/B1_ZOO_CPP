#ifndef B1_CPP_ZOO_EAGLE_H
#define B1_CPP_ZOO_EAGLE_H
#include "Animals.h"
#include <tuple>
#include <utility>

class Eagle: public Animals {
    int max_age = 25;
    string fidelity;
    int daySick = 30;
    int gestationTime = 45;

public:
    Eagle(string m_name, int m_genre,std::tuple<int, int>  m_age,int m_food = 1,int m_quantity = 12): Animals(std::move(m_name),m_genre, m_age, m_food, m_quantity){}

    void coupling(string name){
        fidelity = std::move(name);
    }

    bool setDayGestation() {
        gestationTime--;
        if (gestationTime == 0) {
            setSickness(false);
            gestationTime = 45;
            cout << "A new eagle makes its entrance" << endl;
            return true;
        }
        return false;
    }

    void setDaySick() {
        daySick--;
        if (daySick == 0) {
            setSickness(false);
            daySick = 15;
            cout << "Eagle healed"<< endl;
        }
    }

    void theDead() {
        if (this->GetYears() >= max_age) {
            cout << "mort" << endl;
        }
    }

    ~Eagle() {};
};


#endif //B1_CPP_ZOO_EAGLE_H
