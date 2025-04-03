#ifndef DECKCLASS_H
#define DECKCLASS_H

#include <vector>
#include "Card.h"

class Deck {
private:
    std::vector<Card> cards;
public:
    Deck();
    void refillDeck();
    void shuffleDeck();
    Card drawCard();
    std::vector<Card>& getCards();
    bool isEmpty() const;
    void addCard(const Card& card);
};

#endif