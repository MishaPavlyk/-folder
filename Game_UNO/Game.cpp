#include "Game.h"
#include <iostream>
#include <ctime>
#include <memory>

void Game::start() {
    srand(static_cast<unsigned>(time(nullptr)));
    setupPlayers();

    // Початкова роздача карт
    for (auto& player : players) {
        for (int i = 0; i < 5; ++i) {
            player->drawCard(deck.drawCard());
        }
    }

    currentCard = deck.drawCard();
    skipNext = false;

    // Основний ігровий цикл
    while (true) {
        for (size_t i = 0; i < players.size(); ++i) {
            if (skipNext) {
                std::cout << players[i]->getName() << "'s turn is skipped!\n";
                skipNext = false;
                continue;
            }

            auto& currentPlayer = players[i];
            auto& nextPlayer = *players[(i + 1) % players.size()];

            std::cout << "\nCurrent card: [" << colorToString(currentCard.color)
                << " " << currentCard.value << "]\n";

            // Визначаємо чи це гравець чи бот
            if (dynamic_cast<HumanPlayer*>(currentPlayer.get())) {
                // Хід гравця (людини)
                std::cout << "=== YOUR TURN ===\n";
            }
            else {
                // Хід бота
                std::cout << "=== " << currentPlayer->getName() << "'s TURN ===\n";
            }

            auto playedCards = currentPlayer->playTurn(currentCard, deck, nextPlayer);

            if (!playedCards.empty()) {
                currentCard = playedCards.back();
                handleSpecialCard(currentCard, nextPlayer);

                if (currentCard.value == "CHANGE_COLOR") {
                    currentCard.color = currentPlayer->chooseColor();
                    std::cout << "Color changed to: " << colorToString(currentCard.color) << "\n";
                }
            }

            if (currentPlayer->hasEmptyHand()) {
                std::cout << currentPlayer->getName() << " wins!\n";
                return;
            }
        }
    }
}