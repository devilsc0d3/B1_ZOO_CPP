#ifndef B1_CPP_ZOO_ZOO_H
#define B1_CPP_ZOO_ZOO_H
#include <utility>
#include <vector>
#include <iostream>
#include <random>
#include <cmath>
#include "Habitat.h"
#include "Tiger.h"
#include <cstdlib>
#include <ctime>

using namespace std;

class Zoo{
    string name;
    double money;
    int nbrMaxVisitor;
    int nbrVisitor;
    int nbrPet;
    int nbrHabitat;
    int numberOfVisitor{};
    float seed;
    float meal;
    Habitat* hen = new Habitat(10,4);
    Habitat* eagle = new Habitat(4,1);
    Habitat* tiger = new Habitat(2,1);


public:
    Zoo(string m_name, float m_money):name(std::move(m_name)), money(m_money) {
        tiger->addTiger("roger");
        hen->addHen("Marine");
        eagle->addEagle("Gertrude");

        nbrPet = 4;
        nbrMaxVisitor = 200;
        nbrVisitor = 0;
        seed = 0;
        meal = 0;
        nbrHabitat = 0;
    }

    void Stats() {
//        tiger->NameOfAnimals("tiger :");
//        hen->NameOfAnimals("hen :");
//        eagle->NameOfAnimals("eagle :");
//        cout << tiger->GetCapacity() << endl;
//        cout << eagle->GetCapacity() << endl;
//        cout << hen->GetCapacity() << endl;
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

    //event

    void eventExceptional() {
        GrillingZoo();
        kidnapping();
    }

//SUBVENTION
    void subvention(){
        if (tiger->GetNbr()>0){
            money += (tiger->GetNbr()*3650);
        }
        if(eagle->GetNbr()>0) {
            money += (eagle->GetNbr()*182.5);
        }
    }

    //------------------------------------------- VISITOR ------------------------------------------------------//
    double getRandomNumber(int) const {
        random_device rd;
        mt19937 gen(rd());
        double lowerBound = numberOfVisitor - 0.2 * numberOfVisitor;
        double upperBound = numberOfVisitor + 0.2 * numberOfVisitor;
        uniform_real_distribution<double> dis(lowerBound, upperBound);
        double randomNumber = dis(gen);
        if (fmod(randomNumber, 1.0) != 0) {
            randomNumber = round(randomNumber);
        }
        return randomNumber;
    }

    void GrillingZoo(){
        srand(time(nullptr));
        int random_num = rand() % 100 + 1;
        if (random_num == 1) {
            cout << "light the fire" << endl;
            int random_habitat = rand() % 3 + 1;
            if (random_habitat == 1 && tiger->GetCapacity() >= 2) {
                tiger->SetCapacity(-2);
                cout << "tiger habitat..." << endl;
            }
            else if (random_habitat == 2 && eagle->GetCapacity() >= 4) {
                eagle->SetCapacity(-4);
                cout << "eagle habitat..." << endl;
            }
            else if (random_habitat == 3 && hen->GetCapacity() >= 10) {
                hen->SetCapacity(-10);

                cout << "hen habitat..." << endl;
            }
        }
    }

    void kidnapping(){
        srand(time(nullptr));
        int random_num = rand() % 100 + 1;
        if (random_num > 1) {
            string response;
            cout << "We have kidnapped an animal from your zoo, Pay and it will come back to you!" << endl;
            cout << "Ransom is $6500\n\nPAY : YES or NO" << endl;
            cin >> response;
            if (response == "Yes") {
                money -= 6500;
                cout << "Thanks !" << endl;
            } else {
                int random_habitat = rand() % 3 + 1;
                if (random_habitat == 1) {
                    tiger->removeLast();
                }
                else if (random_habitat == 2) {
                    eagle->removeLast();
                }
                else if (random_habitat == 3) {
                    hen->removeLast();
                }
                cout << "Too bad" << endl;
            }
        }
    }

    void Visitor(int visitorNumber) {
        if (visitorNumber % 2 == 0) {
            money += (visitorNumber / 2 * 17);
            money += (visitorNumber / 2 * 13);
            money += 55;
        } else {
            visitorNumber -= 1;
            money += (visitorNumber / 2 * 17);
            money += (visitorNumber / 2 * 13);
            money += 17;
        }
    }
//
//    void VisitorforAnimals() {
//        if (time->getMonth()>=4 && time->getMonth()<=8){
//            if(habitat->GetNbrTiger()>0){
//                numberOfVisitor = 30*habitat->GetNbrTiger();
//                nbrVisitor += getRandomNumber(numberOfVisitor);
//                Visitor(getRandomNumber(numberOfVisitor));
//            }
//            if(habitat->GetNbrEagle()>0) {
//                numberOfVisitor = 15*habitat->GetNbrEagle();
//                nbrVisitor += getRandomNumber(numberOfVisitor);
//                Visitor(getRandomNumber(numberOfVisitor));
//            }
//            if(habitat->GetNbrHen()>0) {
//                numberOfVisitor = 2*habitat->GetNbrHen();
//                nbrVisitor += getRandomNumber(numberOfVisitor);
//                Visitor(getRandomNumber(numberOfVisitor));
//            }
//        } else if ((time->getMonth()<4 || time->getMonth()>8)){
//            if(habitat->GetNbrTiger()>0){
//                numberOfVisitor = 5*habitat->GetNbrTiger();
//                nbrVisitor += getRandomNumber(numberOfVisitor);
//                Visitor(getRandomNumber(numberOfVisitor));
//            }
//            if(habitat->GetNbrEagle()>0) {
//                numberOfVisitor = 7*habitat->GetNbrEagle();
//                nbrVisitor += getRandomNumber(numberOfVisitor);
//                Visitor(getRandomNumber(numberOfVisitor));
//            }
//            if(habitat->GetNbrHen()>0) {
//                numberOfVisitor = 0.5*habitat->GetNbrHen();
//                nbrVisitor += getRandomNumber(numberOfVisitor);
//                Visitor(getRandomNumber(numberOfVisitor));
//            }
//        }
//    };

    //------------------------------------------- BUY ------------------------------------------------------//
    //HABITAT
    void AddHabitatEagle() {
        float price = 2000;
        if (money > price) {
            money -= price;
            nbrHabitat++;
            eagle->SetCapacity(4);
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
            tiger->addTiger(tiger->SetAName());
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
            tiger->addTiger(tiger->SetAName());
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
            tiger->addTiger(tiger->SetAName());
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
            eagle->addEagle(eagle->SetAName());
        } else {
            cout << "NO Money, You're too poor !!!" << endl;
        }
    };

    void AddEagle4years() {
        float price = 4000;
        if (money > price) {
            money -= price;
            nbrPet++;
            eagle->addEagle(eagle->SetAName());
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
            eagle->addEagle(eagle->SetAName());
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
            hen->addHen(hen->SetAName());
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
            hen->addHen(hen->SetAName());
            cout << "you got a good deal !" << endl;
        } else {
            cout << "NO Money, You're too poor !!!" << endl;
        }
    };

    //SELL - HABITAT
    void SellHabitatTiger() {
        if (tiger->GetCapacity() > 1 || (tiger->GetCapacity() >= 2 && tiger->GetNbr() == 0)) {
            money += 500;
            nbrHabitat--;
            tiger->SetCapacity(-2);
            cout << "you got a good deal !" << endl;
        } else if (eagle->GetCapacity() == 0) {
            cout << "Cri cri cri, there is no more habitat" << endl;
        } else {
            cout << "NO, NO to animals on the street !!!" << endl;
        }
    };

    void SellHabitatEagle() {
        if (eagle->GetCapacity() > 4 || (eagle->GetCapacity() >= 4 && eagle->GetNbr() == 0)) {
            money += 500;
            nbrHabitat--;
            eagle->SetCapacity(-4);
            cout << "you got a good deal !" << endl;
        } else if (eagle->GetCapacity() == 0) {
            cout << "Crii crii crii, there is no more habitat" << endl;
        } else {
            cout << "NO, NO to animals on the street !!!" << endl;
        }
    };

    void SellHabitatHen() {
        cout << "argent : " << money << endl;
        if (hen->GetCapacity() > 1 || (hen->GetCapacity() >= 10 && hen->GetNbr() == 0)) {
            money += 50;
            nbrHabitat--;
            hen->SetCapacity(-10);
            cout << "you got a good deal !" << endl;
        }  else if (eagle->GetCapacity() == 0) {
            cout << "Crii crii crii, there is no more habitat" << endl;
        } else {
            cout << "NO, NO to animals on the street !!!" << endl;
        }

        cout << "argent : " << money << endl;
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
};


#endif //B1_CPP_ZOO_ZOO_H
