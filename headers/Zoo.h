#ifndef B1_CPP_ZOO_ZOO_H
#define B1_CPP_ZOO_ZOO_H
#include <utility>
#include <vector>
#include <iostream>
#include <random>
#include <cmath>
#include "Habitat.h"
#include "Tiger.h"
#include "Eagle.h"
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
    int totalVisitor;
    double seed;
    double meat;
    int jTiger = 2;
    int jEagle = 10;
    int jHen = 2;
    int reputation = 1;
    Habitat* hen = new Habitat(20,4);
    Habitat* eagle = new Habitat(4,1);
    Habitat* tiger = new Habitat(4,1);
    vector<Animals*> veterinary;
    Time* timePassed;

public:

    Zoo(string m_name, float m_money, Time* m_timePassed):name(std::move(m_name)), money(m_money), timePassed(m_timePassed) {
        tiger->addTiger("roger",1,tuple<int, int>{8, 6});
        tiger->addTiger("moli",0,tuple<int, int>{8, 6});
        tiger->addTiger("joelle",1,tuple<int, int>{8, 6});
        tiger->addTiger("varti",0,tuple<int, int>{8, 6});

        hen->addHen("Mascote(fixproblem)",-1,tuple<int, int>{-999, -999});
        hen->addHen("jean marie",1,tuple<int, int>{8, 6});
        hen->addHen("joie",0,tuple<int, int>{8, 6});
        hen->addHen("julie",0,tuple<int, int>{8, 6});
        hen->addHen("juliette",0,tuple<int, int>{8, 6});
        hen->addHen("daniele",0,tuple<int, int>{8, 6});
        hen->addHen("dominique",0,tuple<int, int>{8, 6});
        hen->addHen("denise",0,tuple<int, int>{8, 6});
        hen->addHen("laurie",0,tuple<int, int>{8, 6});
        hen->addHen("laurine",0,tuple<int, int>{8, 6});
        hen->addHen("Marine",0,tuple<int, int>{8, 6});
        hen->addHen("aline",0,tuple<int, int>{8, 6});

        eagle->addEagle("Gertrude",1,tuple<int, int>{8, 6});
        eagle->addEagle("mama",0,tuple<int, int>{8, 6});
        eagle->addEagle("basque",1,tuple<int, int>{8, 6});
        eagle->addEagle("barbara",0,tuple<int, int>{8, 6});

        // test naissance
//        veterinary.push_back(new Tiger("momo",0,tuple<int, int>{8, 8}));


        nbrPet = 11 + 4 + 4;
        nbrMaxVisitor = 200;
        nbrVisitor = 0;
        seed = 0;
        meat = 0;
        nbrHabitat = 0;
    }

    void Stats() {
        cout << "\n=--------------------------- STATS --------=" << endl;
        cout << "name : " << name << endl;
        cout << "money : " << money << endl;
        cout << "seed in kg : " << seed << endl;
        cout << "meat in kg : " << meat << endl;
        cout << "number of pets : " << nbrPet << endl;
        cout << "number of habitat : " << nbrHabitat << endl;
        cout << "maximum number of visitors per month : " << nbrMaxVisitor << endl;
        cout << "average number of visitors per month : " << nbrVisitor << endl;
        cout << "=------------------------------------------=\n" << endl;
    }
    //event

    void eventExceptional() {
        GrillingZoo();
        kidnapping();
//      loophole();
        end();
        harmful();
        corruptedMeat();
        endYear();
        fallIntoTiger();
    }

    void endYear() {
        if (timePassed->getMonth() == 1) {
            int prime = 1000 + reputation * 5;
            money += prime;
            reputation++;
            cout << "Happy New Year!"<< endl;
            cout << "Good job, you have a prime of :" << prime << " TZM(Try-zoo-mix)"<< endl;
            tigerSick(30);
            HenSick();
            EagleSick();
        }
    }

    void monthly() {
        ageUpdate();

        subvention();
        RefreshVisitor();
        VisitorforAnimals();
        restaurant();
        overpopulation();

        eventExceptional();
    }

    void ageUpdate() {
        for (int i = 0; i < tiger->GetNbr(); i++) {
            tiger->GetArray()[i]->TheTime();
        }
        for (int i = 0; i < eagle->GetNbr(); i++) {
            eagle->GetArray()[i]->TheTime();
        }
        for (int i = 0; i < hen->GetNbr(); i++) {
            hen->GetArray()[i]->TheTime();
        }
    }

    void FeedTiger() {
        int i = 0;
        while (i < tiger->GetNbr()) {
            if (meat >= 12 && tiger->GetArray()[i]->GetGenre() == 1) {
                meat -= 12;
                i++;
            } else if (meat >= 10 && tiger->GetArray()[i]->GetGenre() == 0) {
                meat -= 10;
                i++;
            } else {
                delete tiger->GetArray()[i];
                tiger->GetArray().erase(tiger->GetArray().begin() + i);
                nbrPet--;
                cout << "RRRRooaaahh, a tiger is dead !" << endl;
            }
        }
    }


    void FeedHen() {
        int i = 1;
        while (i < hen->GetNbr()) {
            if (seed >= 0.18 && hen->GetArray()[i]->GetGenre() == 1) {
                seed -= 0.18;
                i++;
            } else if (seed >= 0.15 && hen->GetArray()[i]->GetGenre() == 0) {
                seed -= 0.15;
                i++;
            } else {
                delete hen->GetArray()[i];
                hen->GetArray().erase(hen->GetArray().begin() + i);
                nbrPet--;
                cout << "cococoooot,a hen is dead !" << endl;
            }
        }
    }


    void FeedEagle() {
        int i = 0;
        while (i < eagle->GetNbr()) {
            if (meat >= 0.18 && eagle->GetArray()[i]->GetGenre() == 1) {
                meat -= 0.18;
                i++;
            } else if (meat >= 0.15 && eagle->GetArray()[i]->GetGenre() == 0) {
                meat -= 0.15;
                i++;
            } else {
                nbrPet--;
                delete eagle->GetArray()[i];
                eagle->GetArray().erase(eagle->GetArray().begin() + i);
                cout << "Yaaaaah,an eagle is dead !" << endl;
            }
        }
    }

    void Ration() {
        if (jTiger == 0) {
            FeedTiger();
            jTiger = 2;
        }
        if (jEagle == 0) {
            FeedEagle();
            jEagle = 10;
        }
        if (jHen == 0) {
            FeedHen();
            jHen = 2;
        }
        jTiger -= 1;
        jEagle -= 1;
        jHen -= 1;
    }

    void gestation() {
        if (veterinary.size() > 0) {
            for (int i = 0 ; i < veterinary.size(); i++) {
                if (veterinary[i]->setDayGestation()) {
                    if (Tiger* tigers = dynamic_cast<Tiger*>(veterinary[0])) {
                        TigerGestation(i);
                    } else {
                        EagleGestation(i);
                    }
                }
            }
        }
    }

    void TigerGestation(int i) {
        for (int j = 0 ; j < 3; j++) {
            int genre = rand() % 2;
            if (rand() % 100 + 1 > 33) {
                tiger->addTiger(tiger->SetAName(), genre, tuple<int, int>{0, 1});
                tiger->GetArray().push_back((veterinary[i]));
                nbrPet++;
            } else {
                cout << "ouch!! Death as a child" << endl;
            }
        }
        veterinary.erase(veterinary.begin() + i);
    }

    void EagleGestation(int i) {
        for (int j = 0 ; j < 2; j++) {
            int genre = rand() % 2;
            if (rand() % 100 + 1 > 50) {
                eagle->addEagle(eagle->SetAName(), genre, tuple<int, int>{5, 5});
                eagle->GetArray().push_back((veterinary[i]));
                nbrPet++;
            } else {
                cout << "ouch!! Death as a child" << endl;
            }
        }
        veterinary.erase(veterinary.begin() + i);

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

        tigerSick(20);
        HenSick();
        EagleSick();

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

    static int Sick() {
        srand(time(nullptr));
        return rand() % 100 + 1;
    }

    void tigerSick(int tigerProbability) {
        if (Sick() <= tigerProbability && tiger->GetNbr() > 0) {
            tiger->GetArray()[0]->setSickness(true);
            cout << "A tiger feels bad" << endl;
        }
    }

    void EagleSick(){
        if (Sick() <= 10  && eagle->GetNbr() > 0) {
            eagle->GetArray()[0]->setSickness(true);
            cout << "An eagle feels bad" << endl;
        }
    }

    void HenSick() {
        if (Sick() <= 5 && hen->GetNbr() > 1) {
            hen->GetArray()[1]->setSickness(true);
            cout << "A hen feels bad" << endl;
        }
    }

    void sickTime() {
        for (int i = 0 ; i < tiger->GetNbr() ; i++) {
            if (tiger->GetArray()[i]->getSick()) {
                tiger->GetArray()[i]->setDaySick();
            }
        }
        for (int i = 0 ; i < eagle->GetNbr() ; i++) {
            if (eagle->GetArray()[i]->getSick()) {
                eagle->GetArray()[i]->setDaySick();
            }
        }
        for (int i = 1 ; i < hen->GetNbr() ; i++) {
            if (hen->GetArray()[i]->getSick()) {
                hen->GetArray()[i]->setDaySick();
            }
        }
    }

    void restaurant(){
        int nbrClientVisitors = (int) round(nbrVisitor * 0.4);
        if ((meat - (nbrClientVisitors * 0.5) > 0) && (seed - (nbrClientVisitors * 0.5) > 0)){
            VisitorRestaurant(nbrClientVisitors);
        } else {
            cout << "\nRestaurant close this month ! \n" << endl;
        }
    }

    void VisitorRestaurant(int visitorNumber) {
        if (visitorNumber % 2 == 0) {
            money += (visitorNumber / 2 * 15);
            money += (visitorNumber / 2 * 10);
            meat -= (visitorNumber * 0.5);
            seed -= (visitorNumber * 0.5);
        } else {
            meat -= (visitorNumber * 0.5);
            seed -= (visitorNumber * 0.5);
            visitorNumber -= 1;
            money += (visitorNumber / 2 * 15);
            money += (visitorNumber / 2 * 10);
            money += 15;
        }
    }

    void fallIntoTiger() {
        srand(time(nullptr));
        int random_num = rand() % 100 + 1;
        if (random_num == 1) {
            cout << "Little Timothy fell into the tiger cage. You lose 50 000 money. \n" << endl;
            nbrVisitor--;
            money -= 50000;
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
        } else {
            visitorNumber -= 1;
            money += (visitorNumber / 2 * 17);
            money += (visitorNumber / 2 * 13);
            money += 17;
        }
    }

    void HighSeasonVisitor() {
        if (timePassed->getMonth() >= 4 && timePassed->getMonth() <= 8) {
            if (tiger->GetNbr() > 0) {
                numberOfVisitor = 30 * tiger->GetNbr();
                nbrVisitor += getRandomNumber(numberOfVisitor);
                totalVisitor += nbrVisitor;
            }
            if (eagle->GetNbr() > 0) {
                numberOfVisitor = 15 * eagle->GetNbr();
                nbrVisitor += getRandomNumber(numberOfVisitor);
                totalVisitor += nbrVisitor;
            }
            if (hen->GetNbr() > 0) {
                numberOfVisitor = 2 * hen->GetNbr();
                nbrVisitor += getRandomNumber(numberOfVisitor);
                totalVisitor += nbrVisitor;
            }
            if (nbrVisitor > nbrMaxVisitor) {
                nbrVisitor = nbrMaxVisitor;
            }
            Visitor(getRandomNumber(nbrVisitor));
        }
    }
        void LowSeasonVisitor() {
            if ((timePassed->getMonth() < 4 || timePassed->getMonth() > 8)) {
                if (tiger->GetNbr() > 0) {
                    numberOfVisitor = 5 * tiger->GetNbr();
                    nbrVisitor += getRandomNumber(numberOfVisitor);
                    totalVisitor += nbrVisitor;
                }
                if (eagle->GetNbr() > 0) {
                    numberOfVisitor = 7 * eagle->GetNbr();
                    nbrVisitor += getRandomNumber(numberOfVisitor);
                    totalVisitor += nbrVisitor;
                }
                if (hen->GetNbr() > 0) {
                    numberOfVisitor = 0.5 * hen->GetNbr();
                    nbrVisitor += getRandomNumber(numberOfVisitor);
                    totalVisitor += nbrVisitor;
                }
                if (nbrVisitor > nbrMaxVisitor) {
                    nbrVisitor = nbrMaxVisitor;
                }
                Visitor(getRandomNumber(nbrVisitor));
            }
        }

        void VisitorforAnimals() {
            HighSeasonVisitor();
            LowSeasonVisitor();
        }

        void RefreshVisitor() {
            nbrVisitor = 0;
        }

        void addExpand() {
            float price = 4000;
            if (money > price) {
                money -= price;
                nbrMaxVisitor += 100;
                cout << "you got a good deal !" << endl;
            } else {
                cout << "NO Money, You're too poor !!!" << endl;
            }
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
    void AddTiger6month(int genre) {
        float price = 3000;
        if (money > price) {
            money -= price;
            nbrPet++;
            tiger->addTiger(tiger->SetAName(),genre,tuple<int, int>{0, 6});

            cout << "you got a good deal !" << endl;
        } else {
            cout << "NO Money, You're too poor !!!" << endl;
        }
    };

    void AddTiger4years(int genre) {
        float price = 120000;
        if (money > price) {
            money -= price;
            nbrPet++;
            tiger->addTiger(tiger->SetAName(),genre,tuple<int, int>{4, 0});
            cout << "you got a good deal !" << endl;
        } else {
            cout << "NO Money, You're too poor !!!" << endl;
        }
    };

    void AddTiger14years(int genre) {
        float price = 60000;
        if (money > price) {
            money -= price;
            nbrPet++;
            tiger->addTiger(tiger->SetAName(),genre,tuple<int, int>{14, 0});
            cout << "you got a good deal !" << endl;
        } else {
            cout << "NO Money, You're too poor !!!" << endl;
        }
    };

    //ANIMALS - EAGLE
    void AddEagle6month(int genre) {
        float price = 1000;
        if (money > price) {
            money -= price;
            nbrPet++;
            cout << "you got a good deal !" << endl;
            eagle->addEagle(eagle->SetAName(),genre,tuple<int, int>{0, 6});
        } else {
            cout << "NO Money, You're too poor !!!" << endl;
        }
    };

    void AddEagle4years(int genre) {
        float price = 4000;
        if (money > price) {
            money -= price;
            nbrPet++;
            eagle->addEagle(eagle->SetAName(),genre,tuple<int, int>{4, 0});
            cout << "you got a good deal !" << endl;
        } else {
            cout << "NO Money, You're too poor !!!" << endl;
        }
    };

    void AddEagle14years(int genre) {
        float price = 2000;
        if (money > price) {
            money -= price;
            nbrPet++;
            eagle->addEagle(eagle->SetAName(),genre,tuple<int, int>{14, 0});
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
            hen->addHen(hen->SetAName(),0,tuple<int, int>{0, 6});
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
            hen->addHen(hen->SetAName(),1,tuple<int, int>{0, 6});
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
            } else if (eagle->GetCapacity() == 0) {
                cout << "Crii crii crii, there is no more habitat" << endl;
            } else {
                cout << "NO, NO to animals on the street !!!" << endl;
            }
            cout << "money : " << money << endl;
        };

        void SellTiger() {
            if (tiger->GetNbr() > 0) {
                for (int i = 0; i < tiger->GetNbr(); i++) {
                    cout << i << " Nom : " << tiger->GetArray()[i]->GetName() << ", Age : "
                         << tiger->GetArray()[i]->GetMonth() << " months and " << tiger->GetArray()[i]->GetYears()
                         << " years" << endl;
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
                    delete tiger->GetArray()[num];
                    tiger->GetArray().erase(tiger->GetArray().begin() + num);
                    cout << "You sold " << tiger->GetArray()[num]->GetName() << " !" << endl;
                }
            } else {
                cout << "Crii crii crii, there is no tiger." << endl;
            }
            cout << "money : " << money << endl;
        };

        void SellEagle() {
            if (eagle->GetNbr() > 0) {
                for (int i = 0; i < eagle->GetNbr(); i++) {
                    cout << i << " Name : " << eagle->GetArray()[i]->GetName() << ", Age : "
                         << eagle->GetArray()[i]->GetMonth() << " months and " << eagle->GetArray()[i]->GetYears()
                         << " years" << endl;
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
                    delete eagle->GetArray()[num];
                    eagle->GetArray().erase(eagle->GetArray().begin() + num);
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
                    cout << i << " Name : " << hen->GetArray()[i]->GetName() << ", Genre : "
                         << hen->GetArray()[i]->GetGenre() << endl;
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
                    delete hen->GetArray()[num];
                    hen->GetArray().erase(hen->GetArray().begin() + num);
                    cout << "You sold " << hen->GetArray()[num]->GetName() << " !" << endl;
                }
            } else {
                cout << "Crii crii crii, there is no hen." << endl;
            }
            cout << "money : " << money << endl;
        }
};


#endif //B1_CPP_ZOO_ZOO_H
