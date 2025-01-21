#include "MapManager.h"
#include <iostream>

void DisplayMenu() {
    std::cout << "1. Створити нову карту\n";
    std::cout << "2. Зберегти карту\n";
    std::cout << "3. Завантажити карту\n";
    std::cout << "4. Вийти\n";
    std::cout << "Виберiть опцiю: ";
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
            std::cout << "Введiть ширину карти: ";
            std::cin >> width;
            std::cout << "Введiть висоту карти: ";
            std::cin >> height;
            map.RecreateMap(width, height);
            map.RenderMap();
            break;
        case 2:
            std::cout << "Введiть iм'я файлу для збереження: ";
            std::cin >> filename;
            map.SaveToFile(filename);
            break;
        case 3:
            std::cout << "Введiть iм'я файлу для завантаження: ";
            std::cin >> filename;
            map.LoadFromFile(filename);
            map.RenderMap();
            break;
        case 4:
            return 0;
        default:
            std::cout << "Невiрний вибiр. Спробуйте ще раз.\n";
            break;
        }
    }
    return 0;
}
