#pragma once
#include <string>
#include <iostream>

using namespace std;

class Obstacle {
private:
    string name;
    int posX, posY;

public:
    Obstacle(string n, int x, int y) : name(n), posX(x), posY(y) {}

    string getName() const { return name; }
    int getX() const { return posX; }
    int getY() const { return posY; }
};