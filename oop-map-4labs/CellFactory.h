#pragma once
#include <memory>
#include "Cell.h"

class CellFactory {
public:
    static std::unique_ptr<Cell> CreateCell(Cell::Type type);
};
