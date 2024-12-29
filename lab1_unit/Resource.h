#pragma once
#include <string>

using namespace std;

class Resource {
private:
    string name;
    int posX, posY;
    int amount;

public:
    Resource(string n, int x, int y, int amt)
        : name(n), posX(x), posY(y), amount(amt) {}

    string getName() const { return name; }
    int getX() const { return posX; }
    int getY() const { return posY; }
    int getAmount() const { return amount; }

    void collect(int qty) {
        if (qty <= amount) {
            amount -= qty;
        }
    }
};
