#include <iostream>
#include "Zoo.h"
#include "Menu.h"
#include "Time.h"

using namespace std;

int main()
{
    Zoo* zoo = new Zoo("Tri Zoo Mie", 80000);

    Time time;
    Menu menu(zoo, &time);
    menu.show();

    return 0;
}
