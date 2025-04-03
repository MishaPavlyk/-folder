#include "HumanPlayer.h"
#include "DeckClass.h"
#include <iostream>
#include <limits>
#include <algorithm>

HumanPlayer::HumanPlayer(const std::string& playerName) : Player(playerName) {}

std::vector<Card> HumanPlayer::playTurn(const Card& topCard, Deck& deck, Player& nextPlayer) {
    showHand();
    std::vector<Card> playableCards;

    // Знаходимо всі карти, які можна зіграти
    for (const auto& card : hand) {
        if (card.isPlayableOn(topCard)) {
            playableCards.push_back(card);
        }
    }

    // Завжди показуємо опцію "Пропустити хід" (0)
    std::cout << "0. Skip turn (draw card)\n";

    // Показуємо доступні карти
    for (size_t i = 0; i < playableCards.size(); ++i) {
        std::cout << i + 1 << ". [" << colorToString(playableCards[i].color)
            << " " << playableCards[i].value << "]\n";
    }

    int choice = -1;
    while (true) {
        std::cout << "Choose card to play (0-" << playableCards.size() << "): ";

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        // Обробка пропуску ходу
        if (choice == 0) {
            std::cout << name << " draws a card.\n";
            drawCard(deck.drawCard());
            return {};
        }

        // Перевірка коректності вибору карти
        if (choice < 1 || choice > static_cast<int>(playableCards.size())) {
            std::cout << "Invalid choice. Try again.\n";
            continue;
        }

        // Гра вибраної карти
        Card selected = playableCards[choice - 1];
        hand.erase(std::remove(hand.begin(), hand.end(), selected), hand.end());
        return { selected };
    }
}

Color HumanPlayer::chooseColor() {
    int choice;
    while (true) {
        std::cout << "Choose color (1-RED, 2-BLUE, 3-GREEN, 4-YELLOW): ";

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between 1 and 4.\n";
            continue;
        }

        if (choice >= 1 && choice <= 4) {
            break;
        }

        std::cout << "Invalid choice. Please enter a number between 1 and 4.\n";
    }

    return static_cast<Color>(choice - 1);
}