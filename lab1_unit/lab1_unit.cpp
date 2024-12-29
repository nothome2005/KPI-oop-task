#include <iostream>
#include "Unit.h"
#include "Item.h"
#include "Backpack.h"
#include "Game.h"

int main() {
    Game game;

    auto warrior = make_shared<Warrior>(0, 0);
    auto archer = make_shared<Archer>(1, 1);

    game.addUnit(warrior);
    game.addUnit(archer);

    auto factory = make_shared<Factory>(5, 5);
    game.addBuilding(factory);

    auto rock = make_shared<Obstacle>("Rock", 3, 3);
    game.addObstacle(rock);

    auto gold = make_shared<Resource>("Gold", 10, 10, 100);
    game.addResource(gold);

    game.start();

    return 0;
}


