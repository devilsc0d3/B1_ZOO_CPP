
#ifndef B1_CPP_ZOO_MENU_H
#define B1_CPP_ZOO_MENU_H

#include <iostream>
#include <string>
#include "Zoo.h"
#include "time.h"
#include "MenuMarket.h"

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
        } else if (choice == 2) {
            cout << "You have chosen to skip the month." << endl;
            zoo->subvention();
            zoo->VisitorforAnimals();
            zoo->eventExceptional();
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
        cout << "Enter your choice (1-5): ";
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
            marketSell();
        } else if (choice == 5) {
            show();
        } else {
            cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
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
            zoo->addSeed();
        } else if (choice == 2) {
            zoo->addMeal();
        } else if (choice == 3) {
            showMarket();
        } else {
            cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
            marketChoicesFood();
        }
    }

    //ANIMALS
    void marketAnimals() {
        cout << "\nMarket Animals :" << endl;
        cout << "   1. hen" << endl;
        cout << "   2. eagle" << endl;
        cout << "   3. tiger" << endl;
        cout << "   4. Cancel\n" << endl;
        marketChoicesAnimals();
    }

    void marketChoicesAnimals() {
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        marketTypeAnimals();
    }

    void marketTypeAnimals() {
        if (choice == 1) {
            marketGenreHen();
        } else if (choice == 2) {
            marketGenreEagle();
        } else if (choice == 3) {
            marketGenreTiger();
        } else if (choice == 4) {
            showMarket();
        } else {
            cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
            marketChoicesAnimals();
        }
    }

    void marketAgeAnimalTiger() {
        cout << "\nMarket Animals Age :" << endl;
        cout << "   1. 6 Month" << endl;
        cout << "   2. 4 Years" << endl;
        cout << "   3. 14 Years" << endl;
        cout << "   4. Cancel\n" << endl;
        marketChoicesAgeAnimalTiger();
    }

    void marketChoicesAgeAnimalTiger() {
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        marketTypeAgeAnimalTiger();
    }

    void marketTypeAgeAnimalTiger() {
        if (choice == 1) {
            zoo->AddTiger6month();
        } else if (choice == 2) {
            zoo->AddTiger4years();
        } else if (choice == 3) {
            zoo->AddTiger14years();
        } else if (choice == 4) {
            showMarket();
        } else {
            cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
            marketChoicesAgeAnimalTiger();
        }
    }

    void marketAgeAnimalEagle() {
        cout << "\nMarket Animals Age :" << endl;
        cout << "   1. 6 Month" << endl;
        cout << "   2. 4 Years" << endl;
        cout << "   3. 14 Years" << endl;
        cout << "   4. Cancel\n" << endl;
        marketChoicesAgeAnimalEagle();
    }

    void marketChoicesAgeAnimalEagle() {
        cout << "Enter your choice (1-3): ";
        cin >> choice;
        marketTypeAgeAnimalEagle();
    }

    void marketTypeAgeAnimalEagle() {
        if (choice == 1) {
            zoo->AddEagle6month();
        } else if (choice == 2) {
            zoo->AddEagle4years();
        } else if (choice == 3) {
            zoo->AddEagle14years();
        } else if (choice == 4) {
            showMarket();
        } else {
            cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
            marketChoicesAgeAnimalEagle();
        }
    }

    void marketGenreHen() {
        cout << "\nMarket Animals Genre:" << endl;
        cout << "   1. male" << endl;
        cout << "   2. female" << endl;
        cout << "   3. Cancel\n" << endl;
        marketChoicesGenreAnimalHen();
    }

    void marketChoicesGenreAnimalHen() {
        cout << "Enter your choice (1-3): ";
        cin >> choice;
        marketTypeGenreAnimalHen();
    }

    void marketTypeGenreAnimalHen() {
        if (choice == 1) {
            zoo->AddHenMale();
        } else if (choice == 2) {
            zoo->AddHenFemale();
        } else if (choice == 3) {
            showMarket();
        } else {
            cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
            marketChoicesGenreAnimalHen();
        }
    }

    void marketGenreTiger() {
        cout << "\nMarket Animals Genre:" << endl;
        cout << "   1. male" << endl;
        cout << "   2. female" << endl;
        cout << "   3. Cancel\n" << endl;
        marketChoicesGenreAnimalTiger();
    }

    void marketChoicesGenreAnimalTiger() {
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        marketTypeGenreAnimalTiger();
    }

    void marketTypeGenreAnimalTiger() {
        if (choice == 1) {
            marketAgeAnimalTiger();
        } else if (choice == 2) {
            marketAgeAnimalTiger();
        } else if (choice == 3) {
            showMarket();
        } else {
            cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
            marketChoicesGenreAnimalTiger();
        }
    }

    void marketGenreEagle() {
        cout << "\nMarket Animals Genre:" << endl;
        cout << "   1. male" << endl;
        cout << "   2. female" << endl;
        cout << "   3. Cancel\n" << endl;
        marketChoicesGenreAnimalEagle();
    }

    void marketChoicesGenreAnimalEagle() {
        cout << "Enter your choice (1-3): ";
        cin >> choice;
        marketTypeGenreAnimalEagle();
    }

    void marketTypeGenreAnimalEagle() {
        if (choice == 1) {
            marketAgeAnimalEagle();
        } else if (choice == 2) {
            marketAgeAnimalEagle();
        } else if (choice == 3) {
            showMarket();
        } else {
            cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
            marketChoicesGenreAnimalEagle();
        }
    }

    //HABITAT
    void marketHabitat() {
        cout << "\nMarket Habitat:" << endl;
        cout << "   1. eagle" << endl;
        cout << "   2. hen" << endl;
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
            zoo->AddHabitatHen();
        } else if (choice == 3) {
            zoo->AddHabitatTiger();
        } else if (choice == 4) {
            showMarket();
        } else {
            cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
            marketChoicesHabitat();
        }
    }

    //SELL
    void marketSell() {
        cout << "\nMarket sell :" << endl;
        cout << "   1. Habitat eagle" << endl;
        cout << "   2. Habitat hen" << endl;
        cout << "   3. Habitat tiger" << endl;
        cout << "   4. hen" << endl;
        cout << "   5. eagle" << endl;
        cout << "   6. tiger" << endl;
        cout << "   7. Cancel\n" << endl;
        marketChoicesSell();
    }

    void marketChoicesSell() {
        cout << "Enter your choice (1-7): ";
        cin >> choice;
        marketTypeSell();
    }

    void marketTypeSell() {
        if (choice == 1) {
            zoo->SellHabitatEagle();
        } else if (choice == 2) {
            zoo->SellHabitatHen();
        } else if (choice == 3) {
            zoo->SellHabitatTiger();
        } else if (choice == 4) {
        } else if (choice == 5) {
        } else if (choice == 6) {
        } else if (choice == 7) {
            showMarket();
        } else {
            cout << "Invalid choice. Please enter a number between 1 and 7." << endl;
            marketChoicesSell();
        }
    }

};

#endif //B1_CPP_ZOO_MENU_H
