#pragma once
#include <string>

using namespace std;

class Item
{
private:
    string name;
    int weight;

public:
    Item(const string& itemName, int itemWeight)
        : name(itemName), weight(itemWeight) {}

    string getName() const { return name; }
    int getWeight() const { return weight; }
};
