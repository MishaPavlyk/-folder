#include "DeckClass.h"
#include <algorithm>
#include <random>

Deck::Deck() {
    refillDeck();
}

void Deck::refillDeck() {
    cards.clear();
    Color colors[] = { RED, BLUE, GREEN, YELLOW };

    for (Color color : colors) {
        for (int value = 0; value <= 9; ++value) {
            cards.push_back(Card(color, std::to_string(value)));
            if (value != 0) {
                cards.push_back(Card(color, std::to_string(value)));
            }
        }

        cards.push_back(Card(color, "STOP"));
        cards.push_back(Card(color, "CHANGE_COLOR"));
        cards.push_back(Card(color, "+4"));
    }
    shuffleDeck();
}

void Deck::shuffleDeck() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cards.begin(), cards.end(), g);
}

Card Deck::drawCard() {
    if (cards.empty()) {
        refillDeck();
    }
    Card top = cards.back();
    cards.pop_back();
    return top;
}

std::vector<Card>& Deck::getCards() {
    return cards;
}

bool Deck::isEmpty() const {
    return cards.empty();
}

void Deck::addCard(const Card& card) {
    cards.push_back(card);
}