#ifndef B1_CPP_ZOO_ZOO_H
#define B1_CPP_ZOO_ZOO_H
#include <vector>
#include <iostream>
#include <random>
#include <cmath>
#include "Habitat.h"
#include "Tiger.h"
#include "Time.h"

using namespace std;

class Zoo{
    string name;
    float money;
    int nbrMaxVisitor;
    int nbrVisitor;
    int nbrPet;
    int nbrHabitat;
    int numberOfVisiTor;
    float seed;
    float meal;
    Habitat* hen = new Habitat(10,4);
    Habitat* eagle = new Habitat(4,1);
    Habitat* tiger = new Habitat(2,1);
    Time* time;
    Habitat* habitat;

public:
    Zoo(string m_name, float m_money):name(m_name), money(m_money) {
        tiger->addTiger();
        hen->addHen();
        eagle->addEagle();
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
        cout << "maximum number of visitors per month : " << nbrMaxVisitor << endl;
        cout << "average number of visitors per month : " << nbrVisitor << endl;
        cout << "=----------------------------=\n" << endl;
    }

//SUBVENTION
    int subvention(){
        if (habitat->GetNbrTiger()>0){
            money += (habitat->GetNbrTiger()*3650);
        } else if(habitat->GetNbrEagle()>0) {
            money += (habitat->GetNbrEagle()*182.5);
        }
    }

    //------------------------------------------- VISITOR ------------------------------------------------------//
    double getRandomNumber(int) {
        random_device rd;
        mt19937 gen(rd());
        double lowerBound = numberOfVisiTor - 0.2*numberOfVisiTor;
        double upperBound = numberOfVisiTor + 0.2*numberOfVisiTor;
        uniform_real_distribution<double> dis(lowerBound, upperBound);
        double randomNumber = dis(gen);
        if (fmod(randomNumber, 1.0) != 0) {
            randomNumber = round(randomNumber);
        }
        return randomNumber;
    }

    void Visitor(int visitorNumber) {
        if (visitorNumber % 2 == 0) {
            money += ((visitorNumber / 2)*17);
            money += ((visitorNumber / 2)*13);
        } else {
            visitorNumber -= 1;
            money += ((visitorNumber / 2)*17);
            money += ((visitorNumber / 2)*13);
            money += 17;
        }
    }

    void VisitorforAnimals() {
        if (time->getMonth()>=4 && time->getMonth()<=8){
            if(habitat->GetNbrTiger()>0){
                numberOfVisiTor = 30*habitat->GetNbrTiger();
                nbrVisitor += getRandomNumber(numberOfVisiTor);
                Visitor(getRandomNumber(numberOfVisiTor));
            } else if(habitat->GetNbrEagle()>0) {
                numberOfVisiTor = 15*habitat->GetNbrEagle();
                nbrVisitor += getRandomNumber(numberOfVisiTor);
                Visitor(getRandomNumber(numberOfVisiTor));
            } else if(habitat->GetNbrHen()>0) {
                numberOfVisiTor = 2*habitat->GetNbrHen();
                nbrVisitor += getRandomNumber(numberOfVisiTor);
                Visitor(getRandomNumber(numberOfVisiTor));
            }
        } else if ((time->getMonth()<4 || time->getMonth()>8)){
            if(habitat->GetNbrTiger()>0){
                numberOfVisiTor = 5*habitat->GetNbrTiger();
                nbrVisitor += getRandomNumber(numberOfVisiTor);
                Visitor(getRandomNumber(numberOfVisiTor));
            } else if(habitat->GetNbrEagle()>0) {
                numberOfVisiTor = 7*habitat->GetNbrEagle();
                nbrVisitor += getRandomNumber(numberOfVisiTor);
                Visitor(getRandomNumber(numberOfVisiTor));
            } else if(habitat->GetNbrHen()>0) {
                numberOfVisiTor = 0.5*habitat->GetNbrHen();
                nbrVisitor += getRandomNumber(numberOfVisiTor);
                Visitor(getRandomNumber(numberOfVisiTor));
            }
        }
    };

    //------------------------------------------- BUY ------------------------------------------------------//
    //HABITAT
    void AddHabitatEagle() {
        float price = 2000;
        if (money > price) {
            money -= price;
            nbrHabitat++;
            eagle->SetCapacity(4);
            eagle->addEagle();

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
            hen->addHen();

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

    //FOOD
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

    //ANIMALS - TIGER
    void AddTiger6month() {
        float price = 3000;
        if (money > price) {
            money -= price;
            nbrPet++;
            cout << "you got a good deal !" << endl;
        } else {
            cout << "NO Money, You're too poor !!!" << endl;
        }
    };

    void AddTiger4years() {
        float price = 120000;
        if (money > price) {
            money -= price;
            nbrPet++;
            cout << "you got a good deal !" << endl;
        } else {
            cout << "NO Money, You're too poor !!!" << endl;
        }
    };

    void AddTiger14years() {
        float price = 60000;
        if (money > price) {
            money -= price;
            nbrPet++;
            tiger->addTiger();
            cout << "you got a good deal !" << endl;
        } else {
            cout << "NO Money, You're too poor !!!" << endl;
        }
    };

    //ANIMALS - EAGLE
    void AddEagle6month() {
        float price = 1000;
        if (money > price) {
            money -= price;
            nbrPet++;
            cout << "you got a good deal !" << endl;
        } else {
            cout << "NO Money, You're too poor !!!" << endl;
        }
    };

    void AddEagle4years() {
        float price = 4000;
        if (money > price) {
            money -= price;
            nbrPet++;
            cout << "you got a good deal !" << endl;
        } else {
            cout << "NO Money, You're too poor !!!" << endl;
        }
    };

    void AddEagle14years() {
        float price = 2000;
        if (money > price) {
            money -= price;
            nbrPet++;
            cout << "you got a good deal !" << endl;
        } else {
            cout << "NO Money, You're too poor !!!" << endl;
        }
    };

    //ANIMALS - HEN
    void AddHenFemale() {
        float price = 20;
        if (money > price) {
            money -= price;
            nbrPet++;
            hen->addHen();
            cout << "you got a good deal !" << endl;
        } else {
            cout << "NO Money, You're too poor !!!" << endl;
        }
    };

    void AddHenMale() {
        float price = 100;
        if (money > price) {
            money -= price;
            nbrPet++;
            hen->addHen();
            cout << "you got a good deal !" << endl;
        } else {
            cout << "NO Money, You're too poor !!!" << endl;
        }
    };

    /* void SellTiger6month() {
        cout << "argent : " << money << endl;
        if (hen->GetCapacity() > 1 || (hen->GetCapacity() >= 10 && hen->GetNbrAnimals() == 0)) {
            money += 1500;
            nbrPet--;
            cout << "you got a good deal !" << endl;
        }  else if (eagle->GetCapacity() == 0) {
            cout << "Crii crii crii, there is no more habitat" << endl;
        } else {
            cout << "NO, NO to animals on the street !!!" << endl;
        }

        cout << "argent : " << money << endl;
    };

    void SellTiger4years() {
        cout << "argent : " << money << endl;
        if (hen->GetCapacity() > 1 || (hen->GetCapacity() >= 10 && hen->GetNbrAnimals() == 0)) {
            money += 60000;
            nbrPet--;
            cout << "you got a good deal !" << endl;
        }  else if (eagle->GetCapacity() == 0) {
            cout << "Crii crii crii, there is no more habitat" << endl;
        } else {
            cout << "NO, NO to animals on the street !!!" << endl;
        }

        cout << "argent : " << money << endl;
    };

    void SellTiger14years() {
        cout << "argent : " << money << endl;
        if (hen->GetCapacity() > 1 || (hen->GetCapacity() >= 10 && hen->GetNbrAnimals() == 0)) {
            money += 10000;
            nbrPet--;
            cout << "you got a good deal !" << endl;
        }  else if (eagle->GetCapacity() == 0) {
            cout << "Crii crii crii, there is no more habitat" << endl;
        } else {
            cout << "NO, NO to animals on the street !!!" << endl;
        }

        cout << "argent : " << money << endl;
    };

    void SellEagle6month() {
        cout << "argent : " << money << endl;
        if (hen->GetCapacity() > 1 || (hen->GetCapacity() >= 10 && hen->GetNbrAnimals() == 0)) {
            money += 500;
            nbrPet--;
            cout << "you got a good deal !" << endl;
        }  else if (eagle->GetCapacity() == 0) {
            cout << "Crii crii crii, there is no more habitat" << endl;
        } else {
            cout << "NO, NO to animals on the street !!!" << endl;
        }

        cout << "argent : " << money << endl;
    };

    void SellEagle4years() {
        cout << "argent : " << money << endl;
        if (hen->GetCapacity() > 1 || (hen->GetCapacity() >= 10 && hen->GetNbrAnimals() == 0)) {
            money += 2000;
            nbrPet--;
            cout << "you got a good deal !" << endl;
        }  else if (eagle->GetCapacity() == 0) {
            cout << "Crii crii crii, there is no more habitat" << endl;
        } else {
            cout << "NO, NO to animals on the street !!!" << endl;
        }

        cout << "argent : " << money << endl;
    };

    void SellEagle14years() {
        cout << "argent : " << money << endl;
        if (hen->GetCapacity() > 1 || (hen->GetCapacity() >= 10 && hen->GetNbrAnimals() == 0)) {
            money += 400;
            nbrPet--;
            cout << "you got a good deal !" << endl;
        }  else if (eagle->GetCapacity() == 0) {
            cout << "Crii crii crii, there is no more habitat" << endl;
        } else {
            cout << "NO, NO to animals on the street !!!" << endl;
        }

        cout << "argent : " << money << endl;
    };

     void SellHenFemale() {
         cout << "argent : " << money << endl;
         if (hen->GetCapacity() > 1 || (hen->GetCapacity() >= 10 && hen->GetNbrAnimals() == 0)) {
             money += 10;
             nbrPet--;
             hen->SetCapacity(-10);
             cout << "you got a good deal !" << endl;
         }  else if (eagle->GetCapacity() == 0) {
             cout << "Crii crii crii, there is no more habitat" << endl;
         } else {
             cout << "NO, NO to animals on the street !!!" << endl;
         }

         cout << "argent : " << money << endl;
     };

     void SellHenMale() {
         cout << "argent : " << money << endl;
         if (hen->GetCapacity() > 1 || (hen->GetCapacity() >= 10 && hen->GetNbrAnimals() == 0)) {
             money += 20;
             nbrPet--;
             cout << "you got a good deal !" << endl;
         }  else if (eagle->GetCapacity() == 0) {
             cout << "Crii crii crii, there is no more habitat" << endl;
         } else {
             cout << "NO, NO to animals on the street !!!" << endl;
         }

         cout << "argent : " << money << endl;
     };
 */
    void AddVisitor() {

    };
};


#endif //B;1_CPP_ZOO_ZOO_H
