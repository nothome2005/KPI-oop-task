#pragma once
#define UNIT_H
using namespace std;
#include <string>


class Unit
{
private:
	string name;
	int health;
	int attackPower;
	int defense;
	int posX, posY;
	int speed;
Backpack backpack;

public:
    Unit(string n, int hp, int ap, int def, int x, int y, int spd, int maxBackpackWeight)
        : name(n), health(hp), attackPower(ap), defense(def), posX(x), posY(y), speed(spd), backpack(maxBackpackWeight) {}

    virtual ~Unit() = default;


   virtual void move(int x, int y);
    virtual void attack(Unit& target);
    virtual void takeDamage(int damage);
    virtual void specialAbility() = 0;

    bool isAlive() const;
    int getHealth() const;
    string getName() const { return name; }
    bool addItemToBackpack(const Item& item);
    void showBackpack() const;

    int getX() const { return posX; } 
    int getY() const { return posY; } 
};
class Warrior : public Unit {
public:
    Warrior(int x, int y)
        : Unit("Warrior", 120, 25, 10, x, y, 2, 100) {}  

    void specialAbility() override {
        cout << "Warrior uses Shield Block to reduce incoming damage!" << endl;
        defense += 5;
    }
};

class Archer : public Unit {
public:
    Archer(int x, int y)
        : Unit("Archer", 90, 20, 5, x, y, 3, 80) {}  

    void specialAbility() override {
        cout << "Archer shoots a powerful arrow!" << endl;
        attackPower += 10;
    }
};

