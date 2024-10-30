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
	Unit(string n, int hp, int ap, int def, int x, int y, int spd)
		: name(n), health(hp), attackPower(ap), defense(def), posX(x), posY(y), speed(spd), backpack(maxBackpackWeight) {}

	void move(int x, int y);
	void attack(Unit& target);
	void takeDamage(int damage);
	bool isAlive() const;
	int getHealth() const;

	bool addItemToBackpack(const Item& item);
	void showBackpack() const;
};

