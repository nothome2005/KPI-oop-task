#include <iostream>
#include "Unit.h"
#include "Item.h"
#include "Backpack.h"
#include "Game.h"
#include "Factory.h"


int main() {
    Game game;
    CommandManager commandManager;

    // Фабрики для юнітів
    WarriorFactory warriorFactory;
    ArcherFactory archerFactory;

    auto warrior = warriorFactory.createUnit(0, 0);
    auto archer = archerFactory.createUnit(1, 1);

    game.addUnit(warrior);
    game.addUnit(archer);

    // Додавання дій
    commandManager.addCommand(make_unique<MoveCommand>(warrior, 1, 1));
    commandManager.addCommand(make_unique<AttackCommand>(warrior, archer));

    // Виконання команд
    commandManager.executeCommands();

    game.start();
    return 0;
}



