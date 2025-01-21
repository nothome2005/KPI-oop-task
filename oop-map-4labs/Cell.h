#pragma once

class Cell {
public:
    enum Type { WATER, LAND, FOREST, MOUNTAIN };

    virtual ~Cell() = default;
    virtual char GetSymbol() const = 0;
    void SetCoords(int x, int y);
    Type GetType() const;
    const int* GetCoords() const;

protected:
    Type type;
    bool occupied;
    int coords[2];
};

class WaterCell : public Cell {
public:
    WaterCell();
    char GetSymbol() const override;
};

class LandCell : public Cell {
public:
    LandCell();
    char GetSymbol() const override;
};

class ForestCell : public Cell {
public:
    ForestCell();
    char GetSymbol() const override;
};

class MountainCell : public Cell {
public:
    MountainCell();
    char GetSymbol() const override;
};
