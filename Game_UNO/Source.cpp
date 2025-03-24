#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <map>
#include <string>
#include <thread>
#include <chrono>
#include <random>
#include "PlayerClass.h"
#include "DeckClass.h"

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0))); // Ініціалізація генератора випадкових чисел
    Deck deck;
    int numPlayers, numBots, difficulty;
    vector<Player> players;

    // Введення кількості гравців (людей)
    while (true) {
        cout << "Enter number of human players (1-4): ";
        cin >> numPlayers;

        if (numPlayers >= 1 && numPlayers <= 4) {
            break; // Введено коректне значення
        }
        else {
            cout << "Invalid number of human players. Please enter a number between 1 and 4.\n";
        }
    }

    // Введення кількості ботів
    while (true) {
        cout << "Enter number of bots (1-4): ";
        cin >> numBots;

        if (numBots >= 1 && numBots <= 4) {
            break; // Введено коректне значення
        }
        else {
            cout << "Invalid number of bots. Please enter a number between 1 and 4.\n";
        }
    }

    // Перевірка загальної кількості гравців (людей + ботів)
    if (numPlayers + numBots > 4) {
        cout << "Total players (humans + bots) cannot exceed 4. Exiting...\n";
        return 1; // Завершення програми, якщо кількість перевищує 4
    }

    // Введення рівня складності ботів
    while (true) {
        cout << "Choose bot difficulty (1 - Easy, 2 - Hard): ";
        cin >> difficulty;

        if (difficulty == 1 || difficulty == 2) {
            break; // Введено коректне значення
        }
        else {
            cout << "Invalid difficulty. Please enter 1 for Easy or 2 for Hard.\n";
        }
    }

    // Додавання гравців (людей)
    for (int i = 0; i < numPlayers; ++i) {
        players.push_back(Player("Player " + to_string(i + 1)));
    }

    // Додавання ботів
    for (int i = 0; i < numBots; ++i) {
        players.push_back(Player("Bot " + to_string(i + 1), true, difficulty));
    }

    // Роздача початкових карт
    for (auto& player : players) {
        for (int i = 0; i < 5; ++i) {
            player.drawCard(deck.drawCard());
        }
    }

    cout << "Starting game..." << endl;
    Card topCard = deck.drawCard();
    bool gameOver = false;
    bool skipNextTurn = false; // Змінна для пропуску ходу наступного гравця

    // Основний цикл гри
    while (!gameOver) {
        for (size_t i = 0; i < players.size(); ++i) {
            Player& currentPlayer = players[i];
            Player& nextPlayer = players[(i + 1) % players.size()]; // Наступний гравець

            // Перевірка, чи потрібно пропустити хід
            if (skipNextTurn) {
                cout << "\n" << currentPlayer.name << "'s turn is skipped because of the STOP card!\n";
                skipNextTurn = false; // Скидаємо прапорець після пропуску ходу
                continue; // Пропускаємо хід поточного гравця
            }

            cout << "\n" << currentPlayer.name << "'s turn:\n";
            vector<Card> playedCards = currentPlayer.playerTurn(topCard, deck, nextPlayer);

            if (!playedCards.empty()) {
                // Оновлюємо верхню карту
                topCard = playedCards.back();

                // Перевіряємо, чи зіграно карту "STOP"
                if (playedCards.back().value == "STOP") {
                    skipNextTurn = true; // Встановлюємо прапорець для пропуску ходу наступного гравця
                    cout << nextPlayer.name << "'s turn will be skipped!\n";
                }
            }

            if (currentPlayer.hand.empty()) {
                cout << "\n" << currentPlayer.name << " WINS! Game Over." << endl;
                gameOver = true;
                break;
            }
        }
    }

    return 0;
}w