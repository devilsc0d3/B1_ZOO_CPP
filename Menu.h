
#ifndef B1_CPP_ZOO_MENU_H
#define B1_CPP_ZOO_MENU_H

#include <iostream>
#include <string>

#include "Zoo.h"
#include "Time.h"

using namespace std;

class Menu {
private:
    int choice{};
    Zoo* zoo;
    Time* time;
    bool quit = false;

public:
    Menu(Zoo* zoo, Time* time) : zoo(zoo), time(time) {}

    void show() {
        while (!quit) {
            cout << "Current time: " << time->toString() << endl;
            zoo->Stats();
            cout << "Menu :" << endl;
            cout << "   1. Market" << endl;
            cout << "   2. Skip Month" << endl;
            cout << "   3. Quit Game\n" << endl;
            choose();
        }
    }


    void choose() {
        cout << "Enter your choice (1-3): ";
        cin >> choice;
        execute();
    }

    void execute() {
        if (choice == 1) {
            showMarket();
//            quit = true;
        } else if (choice == 2) {
            cout << "You have chosen to skip the month." << endl;
            time->skip();
            cout << time->toString() << endl;
        } else if (choice == 3) {
            cout << "You chose to give up cowardly." << endl;
            quit = true;
            return;
        } else {
                cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
                return choose();
        }
    }

    //------------------------------------------- MARKET ------------------------------------------------------//
    //TODO : garde fou --> habitat existent ;

    void showMarket() {
        while (!quit) {
            cout << "\nMarket :" << endl;
            cout << "   1. Habitat" << endl;
            cout << "   2. Animals" << endl;
            cout << "   3. Food" << endl;
            cout << "   4. Sell" << endl;
            cout << "   5. Cancel\n" << endl;
            marketChoices();
        }
    }

    void marketChoices() {
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        marketType();
    }


    void marketType() {
        if (choice == 1) {
            marketHabitat();
        } else if (choice == 2) {
            marketAnimals();
        } else if (choice == 3) {
            marketFood();
        } else if (choice == 4) {

            cout << " welcome to selling " << endl;
            zoo.t

        } else if (choice == 5) {
            show();
        } else {
            cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
            marketChoices();
        }
    }

    //FOOD
    void marketFood() {
        cout << "\nMarket Food :" << endl;
        cout << "   1. Seed" << endl;
        cout << "   2. Meal" << endl;
        cout << "   3. Cancel\n" << endl;
        marketChoicesFood();
    }

    void marketChoicesFood() {
        cout << "Enter your choice (1-3): ";
        cin >> choice;
        marketTypeFood();
    }

    void marketTypeFood() {
        if (choice == 1) {
        } else if (choice == 2) {
        } else if (choice == 3) {
        } else {
            cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
            marketChoicesFood();
        }
    }

    //ANIMALS
    void marketAnimals() {
        cout << "\nMarket Habitat :" << endl;
        cout << "   1. poule" << endl;
        cout << "   2. poule" << endl;
        cout << "   2. aigle" << endl;
        cout << "   4. aigle" << endl;
        cout << "   5. tiger" << endl;
        cout << "   6. tiger" << endl;
        cout << "   7. Cancel\n" << endl;
        marketChoicesAnimals();
    }

    void marketChoicesAnimals() {
        cout << "Enter your choice (1-7): ";
        cin >> choice;
        marketTypeAnimals();
    }

    void marketTypeAnimals() {
        int genre = marketGenre();
        if (choice == 1) {
        } else if (choice == 2) {
        } else if (choice == 3) {
        } else if (choice == 4) {
        } else if (choice == 5) {
        } else if (choice == 6) {
        } else if (choice == 7) {
            showMarket();
        } else {
            cout << "Invalid choice. Please enter a number between 1 and 7." << endl;
            marketChoicesFood();
        }
    }

    int marketGenre() {
        cout << "\nMarket Animals Genre:" << endl;
        cout << "   1. male" << endl;
        cout << "   2. female" << endl;
        cin >> choice;
        return choice;
    }


    //HABITAT
    void marketHabitat() {
        cout << "\nMarket Habitat:" << endl;
        cout << "   1. aigle" << endl;
        cout << "   2. poule" << endl;
        cout << "   3. tiger" << endl;
        cout << "   4. Cancel\n" << endl;
        marketChoicesHabitat();
    }

    void marketChoicesHabitat() {
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        marketTypeHabitat();
    }

    void marketTypeHabitat() {
        if (choice == 1) {
            zoo->AddHabitatEagle();
        } else if (choice == 2) {
            zoo->AddHabitatPoule();
        } else if (choice == 3) {
            zoo->AddHabitatTiger();
        } else if (choice == 4) {
            showMarket();
        } else {
            cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
            marketChoicesHabitat();
        }
    }
};


#endif //B1_CPP_ZOO_MENU_H
