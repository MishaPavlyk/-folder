#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"
#include <vector>

class HumanPlayer : public Player {
public:
    explicit HumanPlayer(const std::string& playerName);

    std::vector<Card> playTurn(const Card& topCard, Deck& deck, Player& nextPlayer) override;
    Color chooseColor() override;
};

#endif