#include "Game.h"

void Game::addUnit(shared_ptr<Unit> unit) {
    units.push_back(unit);
}

void Game::addBuilding(shared_ptr<Building> building) {
    buildings.push_back(building);
}

void Game::addObstacle(shared_ptr<Obstacle> obstacle) {
    obstacles.push_back(obstacle);
}

void Game::addResource(shared_ptr<Resource> resource) {
    resources.push_back(resource);
}

void Game::start() {
    while (!isGameOver()) {
        if (playerTurn) {
            for (auto& unit : units) {
                if (unit->isAlive()) {
                    
                    playerTurnAction(unit, "move", nullptr, 1, 0);
                }
            }
        }
        else {
            computerTurnAction();
        }
        playerTurn = !playerTurn;
    }
}

void Game::computerTurnAction() {
    for (auto& unit : units) {
        if (unit->isAlive()) {
            shared_ptr<Unit> target = nullptr;
            int minDistance = INT_MAX;

            // Знаходження найближчої цілі
            for (const auto& potentialTarget : units) {
                if (potentialTarget->isAlive()) {
                    int distance = abs(potentialTarget->getX() - unit->getX()) +
                        abs(potentialTarget->getY() - unit->getY());
                    if (distance < minDistance) {
                        minDistance = distance;
                        target = potentialTarget;
                    }
                }
            }

            if (target) {
                if (minDistance <= 1) {
                    unit->attack(*target);
                }
                else {
                    int dx = (target->getX() - unit->getX()) > 0 ? 1 : -1;
                    int dy = (target->getY() - unit->getY()) > 0 ? 1 : -1;
                    unit->move(dx, dy);
                }
            }
        }
    }
}


void Game::playerTurnAction(shared_ptr<Unit> selectedUnit, const string& action, shared_ptr<Unit> target, int dx, int dy) {
    if (!selectedUnit || !selectedUnit->isAlive()) return;

    if (action == "move") {
        selectedUnit->move(dx, dy);
    }
    else if (action == "attack" && target && target->isAlive()) {
        selectedUnit->attack(*target);
    }
}



bool Game::isGameOver() const {
    bool playerAlive = false;
    bool computerAlive = false;

    for (const auto& unit : units) {
        if (unit->isAlive()) {
            if (unit->getName() == "Warrior" || unit->getName() == "Archer") {
                playerAlive = true;
            }
            else {
                computerAlive = true;
            }
        }
    }

    return !(playerAlive && computerAlive);
}
