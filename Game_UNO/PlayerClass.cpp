#include "PlayerClass.h"
#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
#include <thread>
#include <chrono>

using namespace std;

// Конструктор
Player::Player(string n, bool bot, int diff) : name(n), isBot(bot), difficulty(diff) {}

// Додавання карти до руки гравця
void Player::drawCard(Card card) {
    hand.push_back(card);
}

// Показати карти гравця
void Player::showHand() {
    if (isBot) {
        cout << name << " has " << hand.size() << " cards." << endl;
    }
    else {
        cout << name << "'s hand: ";
        for (size_t i = 0; i < hand.size(); ++i) {
            cout << i + 1 << ". [" << colorToString(hand[i].color) << " " << hand[i].value << "] ";
        }
        cout << endl;
    }
}

// Вибрати карти для гри
vector<Card> Player::chooseCards(Card topCard) {
    vector<Card> playedCards;

    for (auto it = hand.begin(); it != hand.end(); ++it) {
        if (it->value == topCard.value || it->color == topCard.color || it->color == NONE) {
            playedCards.push_back(*it);
            hand.erase(it);
            break;
        }
    }

    return playedCards;
}

// Зміна кольору (для спеціальних карт)
Color Player::changeColor() {
    if (isBot) {
        Color colors[] = { RED, BLUE, GREEN, YELLOW };
        return colors[rand() % 4];
    }
    else {
        int choice;
        cout << "Choose a new color:\n";
        cout << "1. Red\n2. Blue\n3. Green\n4. Yellow\n";
        cin >> choice;

        while (choice < 1 || choice > 4) {
            cout << "Invalid choice. Try again: ";
            cin >> choice;
        }

        switch (choice) {
        case 1: return RED;
        case 2: return BLUE;
        case 3: return GREEN;
        case 4: return YELLOW;
        default: return NONE;
        }
    }
}

// Хід гравця
vector<Card> Player::playerTurn(Card& topCard, Deck& deck, Player& nextPlayer) {
    showHand(); // Показати карти гравця
    cout << "Top card: [" << colorToString(topCard.color) << " " << topCard.value << "]" << endl;

    if (isBot) {
        // Логіка для бота
        this_thread::sleep_for(chrono::seconds(1)); // Затримка для імітації ходу бота
        vector<Card> playedCards = chooseCards(topCard); // Вибрати карти для гри

        if (!playedCards.empty()) {
            cout << name << " plays: [" << colorToString(playedCards[0].color) << " " << playedCards[0].value << "]" << endl;

            // Обробка спеціальних карт
            if (playedCards[0].value == "CHANGE_COLOR") {
                topCard.color = changeColor();
                cout << name << " changes the color to " << colorToString(topCard.color) << endl;
            }
            else if (playedCards[0].value == "+4") {
                topCard.color = changeColor();
                cout << name << " changes the color to " << colorToString(topCard.color) << endl;
                for (int i = 0; i < 4; ++i) {
                    nextPlayer.drawCard(deck.drawCard()); // Наступний гравець бере 4 карти
                }
                cout << nextPlayer.name << " draws 4 cards and skips their turn!" << endl;
            }
            else if (playedCards[0].value == "STOP") {
                // Карта "STOP" - нічого не робимо тут, логіка в main.cpp
            }
            else {
                topCard = playedCards[0]; // Оновлюємо верхню карту
            }
        }
        else {
            // Бот не може зіграти карту, бере карту з колоди
            cout << name << " says: 'I take a card and skip my turn.'" << endl;
            drawCard(deck.drawCard());
        }

        return playedCards;
    }
    else {
        // Логіка для гравця-людини
        int choice;
        while (true) {
            cout << "Choose a card to play (1-" << hand.size() << ") or enter 0 to draw: ";
            cin >> choice;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Try again.\n";
                continue;
            }

            if (choice == 0) {
                // Гравець бере карту з колоди
                drawCard(deck.drawCard());
                return {}; // Повертаємо порожній вектор (гравець не зіграв карту)
            }

            if (choice >= 1 && choice <= static_cast<int>(hand.size())) {
                Card selectedCard = hand[choice - 1]; // Обрана карта

                // Перевіряємо, чи карта відповідає правилам
                if (selectedCard.value == topCard.value || selectedCard.color == topCard.color || selectedCard.color == NONE) {
                    vector<Card> playedCards;
                    playedCards.push_back(selectedCard); // Додаємо карту до зіграних
                    hand.erase(hand.begin() + (choice - 1)); // Видаляємо карту з руки

                    cout << name << " plays: [" << colorToString(selectedCard.color) << " " << selectedCard.value << "]" << endl;

                    // Обробка спеціальних карт
                    if (selectedCard.value == "CHANGE_COLOR") {
                        topCard.color = changeColor();
                        cout << name << " changes the color to " << colorToString(topCard.color) << endl;
                    }
                    else if (selectedCard.value == "+4") {
                        topCard.color = changeColor();
                        cout << name << " changes the color to " << colorToString(topCard.color) << endl;
                        for (int i = 0; i < 4; ++i) {
                            nextPlayer.drawCard(deck.drawCard()); // Наступний гравець бере 4 карти
                        }
                        cout << nextPlayer.name << " draws 4 cards and skips their turn!" << endl;
                    }
                    else if (selectedCard.value == "STOP") {
                        // Карта "STOP" - нічого не робимо тут, логіка в main.cpp
                    }
                    else {
                        topCard = selectedCard; // Оновлюємо верхню карту
                    }

                    return playedCards;
                }
                else {
                    cout << "Invalid choice. The card must match the color or value of the top card.\n";
                }
            }
            else {
                cout << "Invalid choice. Try again.\n";
            }
        }
    }
}

// Перетворення кольору в рядок
string colorToString(Color color) {
    switch (color) {
    case RED: return "Red";
    case BLUE: return "Blue";
    case GREEN: return "Green";
    case YELLOW: return "Yellow";
    case NONE: return "None";
    default: return "None";
    }
}