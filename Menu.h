//
// Created by Utilisateur on 27/02/2023.
//

#ifndef B1_CPP_ZOO_MENU_H
#define B1_CPP_ZOO_MENU_H

#include <iostream>

using namespace std;

class Menu {
private:
    int choice;

public:
    void show() {
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
        switch(choice) {
            case 1:
                cout << "You have chosen the market." << endl;
                // Action à exécuter pour l'option 1
                break;
            case 2:
                cout << "You have chosen to skip the month." << endl;
                // Action à exécuter pour l'option 2
                break;
            case 3:
                cout << "You have chosen to leave the game." << endl;
                // Action à exécuter pour l'option 3
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
                return choose();
        }
    }
};


#endif //B1_CPP_ZOO_MENU_H
