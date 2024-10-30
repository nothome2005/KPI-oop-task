#pragma once
#include <vector>
#include <iostream>
#include "Item.h"

using namespace std;

class Backpack
{
private:
    vector<Item> items;
    int maxWeight;
    int currentWeight;

public:
    Backpack(int maxW) : maxWeight(maxW), currentWeight(0) {}

    bool addItem(const Item& item)
    {
        if (currentWeight + item.getWeight() <= maxWeight)
        {
            items.push_back(item);
            currentWeight += item.getWeight();
            return true;
        }
        return false;
    }

    void displayItems() const
    {
        for (const auto& item : items)
        {
            cout << "Item: " << item.getName() << ", Weight: " << item.getWeight() << endl;
        }
    }
};
