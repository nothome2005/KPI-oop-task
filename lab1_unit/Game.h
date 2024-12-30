#pragma once
#include <vector>
#include <memory>
#include "Unit.h"
#include "Building.h"
#include "Obstacle.h"
#include "Resource.h"

using namespace std;

class Game {
private:
    vector<shared_ptr<Unit>> units;
    vector<shared_ptr<Building>> buildings;
    vector<shared_ptr<Obstacle>> obstacles;
    vector<shared_ptr<Resource>> resources;
    bool playerTurn;

public:
    Game() : playerTurn(true) {}

    void addUnit(shared_ptr<Unit> unit);
    void addBuilding(shared_ptr<Building> building);
    void addObstacle(shared_ptr<Obstacle> obstacle);
    void addResource(shared_ptr<Resource> resource);

    void start();
    void playerTurnAction(shared_ptr<Unit> selectedUnit, const string& action, shared_ptr<Unit> target = nullptr, int dx = 0, int dy = 0);
    void computerTurnAction();
    bool isGameOver() const;
};

#include <queue>

// Інтерфейс команди
class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() = default;
};

// Команди
class MoveCommand : public Command {
    shared_ptr<Unit> unit;
    int dx, dy;
public:
    MoveCommand(shared_ptr<Unit> u, int x, int y) : unit(u), dx(x), dy(y) {}
    void execute() override {
        unit->move(dx, dy);
    }
};

class AttackCommand : public Command {
    shared_ptr<Unit> attacker, target;
public:
    AttackCommand(shared_ptr<Unit> a, shared_ptr<Unit> t) : attacker(a), target(t) {}
    void execute() override {
        attacker->performAttack(*target);
    }
};

// Менеджер команд
class CommandManager {
    queue<unique_ptr<Command>> commands;
public:
    void addCommand(unique_ptr<Command> command) {
        commands.push(move(command));
    }
    void executeCommands() {
        while (!commands.empty()) {
            commands.front()->execute();
            commands.pop();
        }
    }
};
