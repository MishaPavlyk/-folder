#include "DeckClass.h"
#include <iostream>
#include <random>

// Конструктор
Deck::Deck() {
    refillDeck(); // Заповнюємо колоду при створенні
    shuffleDeck(); // Перемішуємо колоду
}

// Заповнення колоди
void Deck::refillDeck() {
    cards.clear(); // Очищаємо колоду перед заповненням

    // Масив кольорів
    Color colors[] = { RED, BLUE, GREEN, YELLOW };

    // Додаємо звичайні карти (0-9) для кожного кольору
    for (Color color : colors) {
        for (int value = 0; value <= 9; ++value) {
            cards.push_back(Card(color, std::to_string(value))); // Додаємо карти
            if (value != 0) { // Карта "0" лише одна для кожного кольору
                cards.push_back(Card(color, std::to_string(value)));
            }
        }
    }

    // Додаємо спеціальні карти (STOP, CHANGE_COLOR, +4)
    for (Color color : colors) {
        cards.push_back(Card(color, "STOP")); // Карта "STOP"
        cards.push_back(Card(color, "CHANGE_COLOR")); // Карта "CHANGE_COLOR"
        cards.push_back(Card(color, "+4")); // Карта "+4"
    }

    shuffleDeck(); // Перемішуємо колоду
}

// Перемішування колоди
void Deck::shuffleDeck() {
    std::random_device rd; // Генератор випадкових чисел
    std::mt19937 g(rd()); // Механізм для перемішування
    std::shuffle(cards.begin(), cards.end(), g); // Перемішуємо карти
}

// Витягування карти з колоди
Card Deck::drawCard() {
    if (cards.empty()) {
        std::cout << "Deck is empty! Refilling..." << std::endl;
        refillDeck(); // Якщо колода порожня, заповнюємо її знову
    }
    Card top = cards.back(); // Беремо верхню карту
    cards.pop_back(); // Видаляємо її з колоди
    return top; // Повертаємо карту
}

// Отримання посилання на вектор карт
std::vector<Card>& Deck::getCards() {
    return cards; // Повертаємо посилання на вектор карт
}

// Перевірка, чи колода порожня
bool Deck::isEmpty() const {
    return cards.empty(); // Повертаємо true, якщо колода порожня
}

// Додавання карти до колоди
void Deck::addCard(const Card& card) {
    cards.push_back(card); // Додаємо карту до колоди
}