#pragma once
#include <string>

using namespace std;

#include <vector>

// Інтерфейс спостерігача
class Observer {
public:
    virtual void update(const Resource& resource) = 0;
    virtual ~Observer() = default;
};

// Суб'єкт (ресурс)
class Resource {
    vector<Observer*> observers;
    int amount;
public:
    void attach(Observer* observer) {
        observers.push_back(observer);
    }
    void detach(Observer* observer) {
        observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
    }
    void notify() {
        for (auto observer : observers) {
            observer->update(*this);
        }
    }
    void collect(int qty) {
        if (qty <= amount) {
            amount -= qty;
            notify();
        }
    }
};

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
