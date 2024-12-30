#pragma once
#include "Unit.h"

// Фабрика для створення юнітів
class UnitFactory {
public:
    virtual shared_ptr<Unit> createUnit(int x, int y) = 0;
    virtual ~UnitFactory() = default;
};

class WarriorFactory : public UnitFactory {
public:
    shared_ptr<Unit> createUnit(int x, int y) override {
        return make_shared<Warrior>(x, y);
    }
};

class ArcherFactory : public UnitFactory {
public:
    shared_ptr<Unit> createUnit(int x, int y) override {
        return make_shared<Archer>(x, y);
    }
};
