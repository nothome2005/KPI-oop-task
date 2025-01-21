#include "Cell.h"

void Cell::SetCoords(int x, int y) {
    coords[0] = x;
    coords[1] = y;
}

Cell::Type Cell::GetType() const {
    return type;
}

const int* Cell::GetCoords() const {
    return coords;
}

WaterCell::WaterCell() {
    type = WATER;
    occupied = false;
}

char WaterCell::GetSymbol() const {
    return 'W';
}

LandCell::LandCell() {
    type = LAND;
    occupied = false;
}

char LandCell::GetSymbol() const {
    return 'L';
}

ForestCell::ForestCell() {
    type = FOREST;
    occupied = false;
}

char ForestCell::GetSymbol() const {
    return 'F';
}

MountainCell::MountainCell() {
    type = MOUNTAIN;
    occupied = false;
}

char MountainCell::GetSymbol() const {
    return 'M';
}
