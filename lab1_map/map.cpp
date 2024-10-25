#include "map.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Cell::Cell() {
    type = static_cast<Type>(rand() % 4);
    occupied = false;
    coords[0] = coords[1] = 0;
}

char Cell::GetSymbol() const {
    switch (type) {
    case WATER: return '~';
    case LAND: return '*';
    case FOREST: return 'T';
    case MOUNTAIN: return '^';
    default: return '?';
    }
}

void Cell::SetCoords(int x, int y) {
    coords[0] = x;
    coords[1] = y;
}

MapManager::MapManager(int width, int height) : width(width), height(height) {
    srand(time(NULL));
    tiles.resize(width * height);
    InitializeCoordinates();
}

void MapManager::InitializeCoordinates() {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            tiles[y * width + x].SetCoords(x, y);
        }
    }
}

void MapManager::RenderMap() const {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            std::cout << tiles[y * width + x].GetSymbol() << " ";
        }
        std::cout << std::endl;
    }
}

void test(int x, int y) {
    MapManager mapManager(x, y);
    mapManager.RenderMap();
}
