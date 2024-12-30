#pragma once
#include <string>
#include <iostream>
#include <memory>
#include "Backpack.h"
#include "Item.h"

using namespace std;



class AttackStrategy {
public:
    virtual void attack(Unit& attacker, Unit& target) = 0;
    virtual ~AttackStrategy() = default;
};


class MeleeAttack : public AttackStrategy {
public:
    void attack(Unit& attacker, Unit& target) override {
        int damage = attacker.getAttackPower() - target.getDefense();
        if (damage > 0) target.takeDamage(damage);
    }
};

class RangedAttack : public AttackStrategy {
public:
    void attack(Unit& attacker, Unit& target) override {
        int damage = (attacker.getAttackPower() * 1.2) - target.getDefense();
        if (damage > 0) target.takeDamage(damage);
    }
};

class Unit
{
protected:
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

    int getAttackPower() const { return attackPower; }
    int getDefense() const { return defense; }

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
    unique_ptr<AttackStrategy> attackStrategy;
public:
    void setAttackStrategy(unique_ptr<AttackStrategy> strategy) {
        attackStrategy = move(strategy);
    }
    void performAttack(Unit& target) {
        if (attackStrategy) attackStrategy->attack(*this, target);
    }

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
