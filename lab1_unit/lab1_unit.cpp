using namespace std;


#include <iostream>
#include "Unit.h"


int main()
{
    Unit warrior("warrior", 100, 20, 5, 0, 0, 2);
    Unit archer("archer", 80, 15, 3, 1, 1, 3);
    //lab2_backpack_test
    Item sword("Sword", 15);
    warrior.addItemToBackpack(sword);
    cout<<"Warrior's backpack:"<<endl;
    warrior.showBackpack();

    warrior.move(1, 1);
    cout << "warrior moved to new position!" << endl;

    warrior.attack(archer);
    cout << "warrior attacked archer" << endl;

    if (!archer.isAlive())
    {
        cout << "archer has been defeated" << endl;
    }
    else
    {
        cout << "archer survived with " << archer.getHealth() << " health " << endl;
    }

    return 0;
}



