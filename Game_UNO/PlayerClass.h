#ifndef PLAYERCLASS_H
#define PLAYERCLASS_H

#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include "DeckClass.h"

class Player {
public:
    std::string name;
    bool isBot;
    int difficulty;
    std::vector<Card> hand;

    Player(std::string n, bool bot = false, int diff = 1);
    void drawCard(Card card);
    void showHand();
    std::vector<Card> chooseCards(Card topCard);
    std::vector<Card> playerTurn(Card& topCard, Deck& deck, Player& nextPlayer); // Додано nextPlayer для спец. карт
    Color changeColor(); // Метод для зміни кольору
};

std::string colorToString(Color color);

#endif