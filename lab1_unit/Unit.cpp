#include "Unit.h"



void Unit::move(int x, int y)
{
	posX += x * speed;
	posY += y * speed;
}

void Unit::attack(Unit& target)
{
	int damage = attackPower - target.defense;
	if (damage > 0)
	{
		target.takeDamage(damage);
	}
}
void Unit::takeDamage(int damage)
{
	health -= damage;
	if (health < 0)
	{
		health = 0;
	}
}
bool Unit::isAlive()
{
	return health > 0;
}
int Unit::getHealth()
{
	return health;
}
bool Unit::addItemToBackpack(const Item& item)
{
return backpack.addItem(item);	
}
void Unit::showBackpack()
{
	backpack.displayItems();
}
