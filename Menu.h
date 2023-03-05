
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

    void marketChoices() {
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        marketType();
    }

    void showMarket() {
        while (!quit) {
            cout << "\nMarket :" << endl;
            cout << "   1. Habitat" << endl;
            cout << "   2. Animals" << endl;
            cout << "   3. Food" << endl;
            cout << "   4. Cancel\n" << endl;
            marketChoices();
        }
    }


    void marketType() {
        if (choice == 1) {
            marketHabitat();
        } else if (choice == 2) {
            marketAnimals();
        } else if (choice == 3) {
            marketFood();
        } else if (choice == 4) {
            show();
        } else {
            cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
            marketChoices();
        }
    }

    void marketFood() {
        cout << "\nMarket Food :" << endl;
        cout << "   1. Seed" << endl;
        cout << "   2. Meal" << endl;
        cout << "   3. Cancel\n" << endl;
    }

    void marketAnimals() {
        cout << "\nMarket Habitat :" << endl;
        cout << "   1. poule" << endl;
        cout << "   2. poule" << endl;
        cout << "   2. aigle" << endl;
        cout << "   4. aigle" << endl;
        cout << "   5. tiger\n" << endl;
        cout << "   6. tiger" << endl;
        cout << "   7. Cancel\n" << endl;
    }

    void marketHabitat() {
        cout << "\nMarket Habitat:" << endl;
        cout << "   1. aigle" << endl;
        cout << "   2. poule" << endl;
        cout << "   3. tiger" << endl;
        cout << "   4. Cancel\n" << endl;
    }
};


#endif //B1_CPP_ZOO_MENU_H
