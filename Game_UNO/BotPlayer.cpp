#include "BotPlayer.h"
#include "DeckClass.h"
#include <iostream>
#include <algorithm>

BotPlayer::BotPlayer(const std::string& playerName, int diff)
    : Player(playerName), difficulty(diff) {}

std::vector<Card> BotPlayer::playTurn(const Card& topCard, Deck& deck, Player& nextPlayer) {
    std::cout << "\n" << name << "'s turn...\n";
    std::vector<Card> playableCards;

    for (const auto& card : hand) {
        if (card.isPlayableOn(topCard)) {
            playableCards.push_back(card);
        }
    }

    if (playableCards.empty()) {
        std::cout << name << " draws a card.\n";
        drawCard(deck.drawCard());
        return {};
    }

    Card chosen = playableCards[rand() % playableCards.size()];

    if (difficulty == 2) {
        for (const Card& card : playableCards) {
            if (card.value == "+4" || card.value == "STOP") {
                chosen = card;
                break;
            }
        }

        if (chosen.color == NONE) {
            int colorCounts[4] = { 0 };
            for (const Card& card : hand) {
                if (card.color != NONE) {
                    colorCounts[static_cast<int>(card.color)]++;
                }
            }
            int maxIndex = 0;
            for (int i = 1; i < 4; i++) {
                if (colorCounts[i] > colorCounts[maxIndex]) {
                    maxIndex = i;
                }
            }
            chosen.color = static_cast<Color>(maxIndex);
        }
    }

    std::cout << name << " plays: [" << colorToString(chosen.color)
        << " " << chosen.value << "]\n";

    hand.erase(std::remove(hand.begin(), hand.end(), chosen), hand.end());
    return { chosen };
}

Color BotPlayer::chooseColor() {
    int colorCounts[4] = { 0 };
    for (const Card& card : hand) {
        if (card.color != NONE) {
            colorCounts[static_cast<int>(card.color)]++;
        }
    }

    int maxIndex = 0;
    for (int i = 1; i < 4; i++) {
        if (colorCounts[i] > colorCounts[maxIndex]) {
            maxIndex = i;
        }
    }

    Color chosenColor = static_cast<Color>(maxIndex);
    std::cout << name << " changes color to: " << colorToString(chosenColor) << "\n";
    return chosenColor;
}