#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Card.h"

class Deck;

class Player {
protected:
    std::string name;
    std::vector<Card> hand;

public:
    explicit Player(const std::string& playerName);
    virtual ~Player() = default;

    void drawCard(const Card& card);
    void showHand() const;
    virtual std::vector<Card> playTurn(const Card& topCard, Deck& deck, Player& nextPlayer) = 0;
    virtual Color chooseColor() = 0;

    const std::string& getName() const { return name; }
    bool hasEmptyHand() const { return hand.empty(); }
};

#endif