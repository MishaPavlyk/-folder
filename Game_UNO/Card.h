#ifndef CARD_H
#define CARD_H

#include <string>

enum Color {
    RED,
    BLUE,
    GREEN,
    YELLOW,
    NONE // Додано для спеціальних карт
};

struct Card {
    Color color;
    std::string value;

    // Конструктор для ініціалізації
    Card(Color c, std::string v) : color(c), value(v) {}
};

#endif