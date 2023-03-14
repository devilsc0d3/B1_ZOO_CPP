//
// Created by Utilisateur on 14/03/2023.
//

#ifndef B1_CPP_ZOO_MENUMARKET_H
#define B1_CPP_ZOO_MENUMARKET_H

#include <iostream>
#include <string>

#include "Zoo.h"

class MenuMarket {
    int choice{};
    Zoo* zoo;
    bool quit = false;

    public:

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
            marketSell();
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
            marketAgeAnimalEagle();
        } else if (choice == 3) {
            marketAgeAnimalTiger();
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
        if (choice == 1) {
            marketGenre();
            zoo->AddTiger6month();
        } else if (choice == 2) {
            marketGenre();
            zoo->AddTiger4years();
        } else if (choice == 3) {
            marketGenre();
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
        if (choice == 1) {
            marketGenre();
            zoo->AddEagle6month();
        } else if (choice == 2) {
            marketGenre();
            zoo->AddEagle4years();
        } else if (choice == 3) {
            marketGenre();
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
        if (choice == 1) {
            zoo->AddHenMale();
        } else if (choice == 2) {
            zoo->AddHenFemale();
        } else if (choice == 3) {
            showMarket();
        } else {
            cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
            marketChoicesGenreAnimalHen();
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
        marketSellHabitat();
    }

    void marketSellHabitat() {
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
            cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
            marketChoices();
        }
    }
};


#endif //B1_CPP_ZOO_MENUMARKET_H
