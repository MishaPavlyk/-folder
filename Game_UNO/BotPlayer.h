#ifndef BOTPLAYER_H
#define BOTPLAYER_H

#include "Player.h"

class BotPlayer : public Player {
    int difficulty;
public:
    BotPlayer(const std::string& playerName, int diff);
    std::vector<Card> playTurn(const Card& topCard, Deck& deck, Player& nextPlayer) override;
    Color chooseColor() override;
};

#endif