#pragma once
#include <vector>
#include <memory>
#include <string>
#include "Cell.h"
#include "CellFactory.h"

class MapManager {
private:
    std::vector<std::unique_ptr<Cell>> tiles;
    int width;
    int height;

    void InitializeCoordinates();

public:
    MapManager(int width, int height);
    void RenderMap() const;
    void SaveToFile(const std::string& filename) const;
    void LoadFromFile(const std::string& filename);
    void RecreateMap(int width, int height);
};
