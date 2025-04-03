#ifndef CARD_H
#define CARD_H

#include <string>

enum Color { RED, BLUE, GREEN, YELLOW, NONE };

struct Card {
    Color color;
    std::string value;

    Card(Color c = RED, std::string v = "0") : color(c), value(v) {}

    bool operator==(const Card& other) const {
        return color == other.color && value == other.value;
    }

    bool isPlayableOn(const Card& other) const {
        return color == other.color || value == other.value || color == NONE;
    }
};

std::string colorToString(Color color);

#endif