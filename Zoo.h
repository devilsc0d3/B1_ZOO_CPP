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
#include "Time.h"
#include "Animals.h"

using namespace std;

class Zoo{
    string name;
    double money;
    int nbrMaxVisitor;
    int nbrVisitor;
    int nbrPet;
    int nbrHabitat;
    int numberOfVisitor;
    double seed;
    double meat;
    int jTiger = 2;
    int jEagle = 10;
    int jHen = 2;
    Habitat* hen = new Habitat(10,4);
    Habitat* eagle = new Habitat(4,1);
    Habitat* tiger = new Habitat(2,1);
    vector<Habitat*> veterinary;
    Time* timePassed;

public:

    Zoo(string m_name, float m_money, Time* m_timePassed):name(std::move(m_name)), money(m_money), timePassed(m_timePassed) {
        tiger->addTiger("roger");
        hen->addHen("Marine");
        eagle->addEagle("Gertrude");

        nbrPet = 3;
        nbrMaxVisitor = 200;
        nbrVisitor = 0;
        seed = 0;
        meat = 0;
        nbrHabitat = 0;
    }

    void Stats() {

        cout << "\n=---------- STATS -----------=" << endl;
        cout << "name : " << name << endl;
        cout << "money : " << money << endl;
        cout << "seed in kg : " << seed << endl;
        cout << "meat in kg : " << meat << endl;
        cout << "number of pets : " << nbrPet << endl;
        cout << "number of habitat : " << nbrHabitat << endl;
        cout << "maximum number of visitors per month : " << nbrMaxVisitor << endl;
        cout << "average number of visitors per month : " << nbrVisitor << endl;
        cout << "=----------------------------=\n" << endl;
    }
    //event

    void eventExceptional() {
        overpopulation();
        GrillingZoo();
        kidnapping();
//        loophole();
        end();
        harmful();
        corruptedMeat();
    }

    void Ration() {
//        Todo faire dans les animaux eux meme
        if (jTiger == 1) {
            for (int i = 0; i < tiger->GetNbr(); i++) {
                meat += tiger->GetArray()[i]->FeedMe(meat);
            }
            jTiger = 2;
        }
        if (jEagle == 1) {
            for (int i = 0; i < tiger->GetNbr(); i++) {
                meat += eagle->GetArray()[i]->FeedMe(meat);
            }
            jEagle = 10;
        }
        if (jHen == 1) {
            for (int i = 0; i < hen->GetNbr(); i++) {
                seed += hen->GetArray()[i]->FeedMe(seed);
            }
            jHen = 2;
        }
        jTiger -= 1;
        jEagle -= 1;
        jHen -= 1;
    }

    void end() {
        if (timePassed->getYears() == 10) {
            cout << "Congrats !!! "<< name << "celebrates these 10 years" << endl;
            cout << "1.continue or 2.exit" << endl;
            int response;
            cin >> response;
            if (response != 1) {
                exit(0);
            }
        }
    }

    void loophole() {
        srand(time(nullptr));
        int random_num = rand() % 100 + 1;
        if (random_num == 1) {
            hen->GetArray().push_back(move(tiger->GetArray().back()));
            tiger->GetArray().pop_back();
            // detruit tout les poulet
        }
    }


    void overpopulation(){
        srand(time(nullptr));
        int random_num;
        if (tiger->GetNbr() > tiger->GetCapacity()) {
            random_num = rand() % 100 + 1;
            if (random_num >= 50) {
                tiger->GetArray().pop_back();
            }
        }
        if (eagle->GetNbr() > eagle->GetCapacity()) {
            random_num = rand() % 100 + 1;
            if (random_num >= 50) {
                eagle->GetArray().pop_back();
            }
        }
        if (hen->GetNbr() > hen->GetCapacity()) {
            random_num = rand() % 100 + 1;
            if (random_num >= 50) {
                for (int i = 0 ; i < 4 ; i++) {
                    if (!hen->GetArray().empty()) {
                        hen->GetArray().pop_back();
                    }
                }
            }
        }
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
        if (random_num == 1) {
            int response;
            cout << "We have kidnapped an animal from your zoo, Pay and it will come back to you!" << endl;
            cout << "Ransom is $6500\n\nPAY : 1.YES or 2.NO" << endl;
            cin >> response;
            if (response == 1) {
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

    void harmful(){
        srand(time(nullptr));
        int random_num = rand() % 100 + 1;
        if (random_num <=20){
            int perte = seed * 0.1;
            seed -= perte;
        }
    }

    void corruptedMeat(){
        srand(time(nullptr));
        int random_num = rand() % 100 + 1;
        if (random_num <=10){
            int perte = meat * 0.2;
            meat -= perte;
        }
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

    void VisitorforAnimals() {
        if (timePassed->getMonth()>=4 && timePassed->getMonth()<=8){
            if(tiger->GetNbr()>0){
                numberOfVisitor = 30*tiger->GetNbr();
                nbrVisitor += getRandomNumber(numberOfVisitor);
                Visitor(getRandomNumber(numberOfVisitor));
            }
            if(eagle->GetNbr()>0) {
                numberOfVisitor = 15*eagle->GetNbr();
                nbrVisitor += getRandomNumber(numberOfVisitor);
                Visitor(getRandomNumber(numberOfVisitor));
            }
            if(hen->GetNbr()>0) {
                numberOfVisitor = 2*hen->GetNbr();
                nbrVisitor += getRandomNumber(numberOfVisitor);
                Visitor(getRandomNumber(numberOfVisitor));
            }
        } else if ((timePassed->getMonth()<4 || timePassed->getMonth()>8)){
            if(tiger->GetNbr()>0){
                numberOfVisitor = 5*tiger->GetNbr();
                nbrVisitor += getRandomNumber(numberOfVisitor);
                Visitor(getRandomNumber(numberOfVisitor));
            }
            if(eagle->GetNbr()>0) {
                numberOfVisitor = 7*eagle->GetNbr();
                nbrVisitor += getRandomNumber(numberOfVisitor);
                Visitor(getRandomNumber(numberOfVisitor));
            }
            if(hen->GetNbr()>0) {
                numberOfVisitor = 0.5*hen->GetNbr();
                nbrVisitor += getRandomNumber(numberOfVisitor);
                Visitor(getRandomNumber(numberOfVisitor));
            }
        }
    };

    void RefreshVisitor() {
        nbrVisitor = 0;
    }

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
            meat += kilos;
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
        cout << "money : " << money << endl;
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
        cout << "money : " << money << endl;
    };

    void SellHabitatHen() {
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
        cout << "money : " << money << endl;
    };

    void SellTiger() {
        if (tiger->GetNbr() > 0) {
            for (int i = 0; i < tiger->GetNbr(); i++) {
                cout << i << " Nom : " << tiger->GetArray()[i]->GetName() << ", Age : " << tiger->GetArray()[i]->GetMonth() << " months and " << tiger->GetArray()[i]->GetYears() << " years" << endl;
            }
            cout << "Enter the number of the tiger you want to sell : ";
            int num;
            cin >> num;
            if (num < 0 || num > tiger->GetNbr()) {
                cout << "Invalid number." << endl;
            } else {
                int year = tiger->GetArray()[num]->GetYears();
                if ((year >= 0) && (year < 4)) {
                    nbrPet--;
                    money += 1500;
                } else if ((year >= 4) && (year < 14)) {
                    nbrPet--;
                    money += 60000;
                } else if (year >= 14) {
                    nbrPet--;
                    money += 10000;
                }
                cout << "You sold " << tiger->GetArray()[num]->GetName()  << " !" << endl;
            }
        } else {
            cout << "Crii crii crii, there is no tiger." << endl;
        }
        cout << "money : " << money << endl;
    };

    void SellEagle() {
        if (eagle->GetNbr() > 0) {
            for (int i = 0; i < eagle->GetNbr(); i++) {
                cout << i << " Name : " << eagle->GetArray()[i]->GetName() << ", Age : " << eagle->GetArray()[i]->GetMonth() << " months and " << eagle->GetArray()[i]->GetYears() << " years" << endl;
            }
            cout << "Enter the number of the eagle you want to sell : ";
            int num;
            cin >> num;
            if (num < 0 || num > eagle->GetNbr()) {
                cout << "Invalid number." << endl;
            } else {
                int year = eagle->GetArray()[num]->GetYears();
                if ((year >= 0) && (year < 4)) {
                    nbrPet--;
                    money += 500;
                } else if ((year >= 4) && (year < 14)) {
                    nbrPet--;
                    money += 2000;
                } else if (year >= 14) {
                    nbrPet--;
                    money += 400;
                }
                cout << "You sold " << eagle->GetArray()[num]->GetName() << " !" << endl;
            }
        } else {
            cout << "Crii crii crii, there is no eagle." << endl;
        }
        cout << "money : " << money << endl;
    }

    void SellHen() {
        if (hen->GetNbr() > 0) {
            for (int i = 0; i < hen->GetNbr(); i++) {
                cout << i << " Name : " << hen->GetArray()[i]->GetName() << ", Genre : " << hen->GetArray()[i]->GetGenre() << endl;
            }
            cout << "Enter the number of the hen you want to sell : ";
            int num;
            cin >> num;
            if (num < 0 || num > hen->GetNbr()) {
                cout << "Invalid number." << endl;
            } else {
                int genre = hen->GetArray()[num]->GetGenre();
                if (genre == 0) {
                    nbrPet--;
                    money += 10;
                } else if (genre == 1) {
                    nbrPet--;
                    money += 20;
                }
                cout << "You sold " << hen->GetArray()[num]->GetName() << " !" << endl;
            }
        } else {
            cout << "Crii crii crii, there is no hen." << endl;
        }
        cout << "money : " << money << endl;
    }
};


#endif //B1_CPP_ZOO_ZOO_H
