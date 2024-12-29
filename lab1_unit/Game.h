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
