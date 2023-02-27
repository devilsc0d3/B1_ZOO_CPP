#include <iostream>
#include "Market.h"
#include "Zoo.h"
#include "Menu.h"


using namespace std;

int main()
{
    Zoo* zoo = new Zoo("Zoodyssey", 80000);
    zoo->Stats();

    Menu menu;
    menu.show();


    return 0;

}
