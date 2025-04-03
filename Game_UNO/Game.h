#ifndef GAME_H
#define GAME_H

#include <vector>
#include <memory>
#include <iostream>
#include "DeckClass.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "BotPlayer.h"

using std::cout;
using std::cin;

class Game {
private:
    Deck deck;
    std::vector<std::unique_ptr<Player>> players;
    Card currentCard;
    bool skipNext = false;

    void setupPlayers() {
        int numPlayers, numBots = 0, difficulty = 1;

        while (true) {
            cout << "Enter number of human players (1-4): ";
            cin >> numPlayers;
            if (numPlayers >= 1 && numPlayers <= 4) break;
            cout << "Invalid number of players.\n";
        }

        while (true) {
            cout << "Enter number of bots (0-4): ";
            cin >> numBots;
            if (numBots >= 0 && numBots <= 4 && numPlayers + numBots >= 2) break;
            cout << "Invalid number of bots (min 2 players total).\n";
        }

        for (int i = 0; i < numPlayers; ++i) {
            players.push_back(std::make_unique<HumanPlayer>("Player " + std::to_string(i + 1)));
        }

        if (numBots > 0) {
            while (true) {
                cout << "Choose bot difficulty (1-Easy, 2-Hard): ";
                cin >> difficulty;
                if (difficulty == 1 || difficulty == 2) break;
                cout << "Invalid difficulty.\n";
            }

            for (int i = 0; i < numBots; ++i) {
                players.push_back(std::make_unique<BotPlayer>("Bot " + std::to_string(i + 1), difficulty));
            }
        }
    }

    void handleSpecialCard(const Card& card, Player& nextPlayer) {
        if (card.value == "STOP") {
            skipNext = true;
            cout << nextPlayer.getName() << "'s turn will be skipped!\n";
        }
        else if (card.value == "+4") {
            for (int j = 0; j < 4; ++j) {
                Card drawn = deck.drawCard();
                cout << nextPlayer.getName() << " draws: ["
                    << colorToString(drawn.color) << " " << drawn.value << "]\n";
                nextPlayer.drawCard(drawn);
            }
        }
    }

public:
    void start();
};

#endif