// MapManager.h
#pragma once

#include <vector>

class Cell {
public:
	enum Type { WATER, LAND, FOREST, MOUNTAIN };

	Type type;
	bool occupied;
	int coords[2];

	Cell();

	char GetSymbol() const;
	void SetCoords(int x, int y);
};

class MapManager {
private:
	std::vector<Cell> tiles;
	int	width;
	int	height;

public:
	MapManager(int width, int height);
	void InitializeCoordinates();
	void RenderMap() const;
};

void test(int x, int y);
