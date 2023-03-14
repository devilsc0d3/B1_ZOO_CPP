
#ifndef B1_CPP_ZOO_MENU_H
#define B1_CPP_ZOO_MENU_H

#include <iostream>
#include <string>

#include "Zoo.h"
#include "Time.h"
#include "MenuMarket.h"

using namespace std;

class Menu {
private:
    int choice{};
    Zoo* zoo;
    Time* time;
    MenuMarket* MenuMarket;
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
            MenuMarket->showMarket();
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
};

#endif //B1_CPP_ZOO_MENU_H
