#pragma once
#include <string>
#include <iostream>

using namespace std;

class Building {
protected:
    string name;
    int posX, posY;

public:
    Building(string n, int x, int y) : name(n), posX(x), posY(y) {}
    virtual ~Building() = default;

    virtual void produceUnit() = 0;
    string getName() const { return name; }
};

class Factory : public Building {
public:
    Factory(int x, int y) : Building("Factory", x, y) {}

    void produceUnit() override {
        cout << name << " produces a Warrior unit!" << endl;
    }
};