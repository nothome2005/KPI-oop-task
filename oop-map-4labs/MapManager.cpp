#include "MapManager.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <sys/stat.h>

MapManager::MapManager(int width, int height) : width(width), height(height) {
    std::srand(std::time(0));
    if (width <= 0 || height <= 0) {
        std::cerr << "������������ ����i� �����" << std::endl;
        return;
    }
    RecreateMap(width, height);
}

void MapManager::RecreateMap(int width, int height) {
    if (width <= 0 || height <= 0) {
        std::cerr << "������������ ����i� �����" << std::endl;
        return;
    }
    this->width = width;
    this->height = height;
    tiles.clear();
    tiles.reserve(width * height);
    for (int i = 0; i < width * height; ++i) {
        tiles.push_back(CellFactory::CreateCell(static_cast<Cell::Type>(std::rand() % 4)));
    }
    InitializeCoordinates();
}

void MapManager::InitializeCoordinates() {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            tiles[y * width + x]->SetCoords(x, y);
        }
    }
}

void MapManager::RenderMap() const {
    if (tiles.empty()) {
        std::cerr << "����� �������, �i���� �i���������" << std::endl;
        return;
    }
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            std::cout << tiles[y * width + x]->GetSymbol() << ' ';
        }
        std::cout << std::endl;
    }
}

void MapManager::SaveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "�� ������� �i������ ���� ��� ������" << std::endl;
        return;
    }
    file << width << " " << height << "\n";
    for (const auto& tile : tiles) {
        file << tile->GetType() << " " << tile->GetCoords()[0] << " " << tile->GetCoords()[1] << "\n";
    }
    file.close();
}

bool FileExists(const std::string& filename) {
    struct stat buffer;
    return (stat(filename.c_str(), &buffer) == 0);
}

void MapManager::LoadFromFile(const std::string& filename) {
    if (!FileExists(filename)) {
        std::cerr << "���� �� i���: " << filename << std::endl;
        tiles.clear(); // �������� ������� �����, ���� ���� �� ��������
        return;
    }
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "�� ������� �i������ ���� ��� �������" << std::endl;
        tiles.clear(); // �������� ������� �����, ���� ���� �� ������� �i������
        return;
    }
    file >> width >> height;
    if (width <= 0 || height <= 0) {
        std::cerr << "������������ ����i� ����� � ����i" << std::endl;
        tiles.clear(); // �������� ������� �����, ���� ����i�� ����� � ����i ���������i
        return;
    }
    tiles.clear();
    tiles.reserve(width * height);
    int type, x, y;
    while (file >> type >> x >> y) {
        auto cell = CellFactory::CreateCell(static_cast<Cell::Type>(type));
        cell->SetCoords(x, y);
        tiles.push_back(std::move(cell));
    }
    file.close();
}