#include "Player.h"
#include <iostream>

Player::Player(const std::string& playerName) : name(playerName) {}

void Player::drawCard(const Card& card) {
    hand.push_back(card);
}

void Player::showHand() const {
    std::cout << name << "'s hand: ";
    for (size_t i = 0; i < hand.size(); ++i) {
        std::cout << i + 1 << ". [" << colorToString(hand[i].color)
            << " " << hand[i].value << "] ";
    }
    std::cout << "\n";
}