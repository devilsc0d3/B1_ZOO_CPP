#ifndef B1_CPP_ZOO_HEN_H
#define B1_CPP_ZOO_HEN_H
#include "Animals.h"
#include <tuple>
#include <utility>

class Hen: public Animals {
    int max_age = 15;
    int gestation_time = 31*3;
    int daySick = 5;
public:
    Hen(string m_name, int m_genre,std::tuple<int, int>  m_age,int m_food = 1,int m_quantity = 12): Animals(std::move(m_name),m_genre, m_age, m_food, m_quantity){
    }

    string cocot() {
        return "cocococooooooot";
    }

    void gestation() {
        gestation_time--;
        if (gestation_time == 0) {
            cout << "a new animal !"<< endl;
            //create animals
            gestation_time = 45;
        }
    }

    void setDaySick() {
        daySick--;
        if (daySick == 0) {
            daySick = 5;
            cout << "hen healed"<< endl;
            setSickness(false);
            cout << "ihh" << this->getSick();

        }
    }

    void theDead() {
        if (this->GetYears() >= max_age) {
            cout << "mort" << endl;
        }
    }

    ~Hen(){}
};


#endif //B1_CPP_ZOO_HEN_H
