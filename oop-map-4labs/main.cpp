#include "MapManager.h"
#include <iostream>

void DisplayMenu() {
    std::cout << "1. �������� ���� �����\n";
    std::cout << "2. �������� �����\n";
    std::cout << "3. ����������� �����\n";
    std::cout << "4. �����\n";
    std::cout << "�����i�� ���i�: ";
}

int main() {
    setlocale(LC_CTYPE, "ukr");
    MapManager map(10, 10);
    int choice;
    std::string filename;

    while (true) {
        DisplayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            int width, height;
            std::cout << "����i�� ������ �����: ";
            std::cin >> width;
            std::cout << "����i�� ������ �����: ";
            std::cin >> height;
            map.RecreateMap(width, height);
            map.RenderMap();
            break;
        case 2:
            std::cout << "����i�� i�'� ����� ��� ����������: ";
            std::cin >> filename;
            map.SaveToFile(filename);
            break;
        case 3:
            std::cout << "����i�� i�'� ����� ��� ������������: ";
            std::cin >> filename;
            map.LoadFromFile(filename);
            map.RenderMap();
            break;
        case 4:
            return 0;
        default:
            std::cout << "���i���� ���i�. ��������� �� ���.\n";
            break;
        }
    }
    return 0;
}
