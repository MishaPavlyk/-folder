#ifndef CARD_H
#define CARD_H

enum Color { RED, BLUE, GREEN, YELLOW, NONE };

struct Card {
    Color color;
    int value;
};

#endif
