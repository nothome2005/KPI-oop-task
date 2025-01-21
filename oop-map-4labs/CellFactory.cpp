#include "CellFactory.h"

std::unique_ptr<Cell> CellFactory::CreateCell(Cell::Type type) {
    switch (type) {
    case Cell::WATER:
        return std::make_unique<WaterCell>();
    case Cell::LAND:
        return std::make_unique<LandCell>();
    case Cell::FOREST:
        return std::make_unique<ForestCell>();
    case Cell::MOUNTAIN:
        return std::make_unique<MountainCell>();
    default:
        return nullptr;
    }
}
