//
// Created by Utilisateur on 27/02/2023.
//

#ifndef B1_CPP_ZOO_MENU_H
#define B1_CPP_ZOO_MENU_H

#include <iostream>
#include <string>
#include "Time.h"

using namespace std;

class Menu {
private:
    int choice;
    Time time;

public:

    void show() {
        cout << time.toString() << endl;
        cout << "Menu :" << endl;
        cout << "1. Market" << endl;
        cout << "2. Skip Month" << endl;
        cout << "3. Quit Game" << endl;
        choose();
    }

    void choose() {
        cout << "Enter your choice (1-3): ";
        cin >> choice;
        execute();
    }

    void execute() {
        if (choice == 1) {
            cout << "You have chosen the market." << endl;

        } else if (choice == 2) {
            cout << "You have chosen to skip the month." << endl;
            time.skip();
            cout << time.toString() << endl;
        } else if (choice == 3) {
            cout << "You have chosen to leave the game." << endl;
            return;
        } else {
                cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
                return choose();
        }
    }

    string GetTime(){
        return time.toString();
    }
};


#endif //B1_CPP_ZOO_MENU_H
