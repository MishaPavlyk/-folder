#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <map>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

enum Color { RED, BLUE, GREEN, YELLOW, NONE };

string colorToString(Color color) {
    switch (color) {
    case RED: return "Red";
    case BLUE: return "Blue";
    case GREEN: return "Green";
    case YELLOW: return "Yellow";
    default: return "None";
    }
}

struct Card {
    Color color;
    int value;

    bool operator==(const Card& other) const {
        return color == other.color && value == other.value;
    }
};

class Deck {
private:
    vector<Card> cards;
public:
    Deck() {
        refillDeck();
    }
    void refillDeck() {
        cards.clear();
        for (int c = RED; c <= YELLOW; ++c) {
            for (int v = 0; v <= 9; ++v) {
                cards.push_back({ static_cast<Color>(c), v });
                cards.push_back({ static_cast<Color>(c), v });
            }
        }
        shuffleDeck();
    }
    void shuffleDeck() {
        srand(static_cast<unsigned int>(time(0)));
        random_shuffle(cards.begin(), cards.end());
    }
    Card drawCard() {
        if (cards.empty()) {
            cout << "Deck is empty! Refilling..." << endl;
            refillDeck();
        }
        Card top = cards.back();
        cards.pop_back();
        return top;
    }
};

class Player {
public:
    string name;
    vector<Card> hand;
    bool isBot;
    int difficulty;

    Player(string n, bool bot = false, int diff = 1) : name(n), isBot(bot), difficulty(diff) {}

    void drawCard(Deck& deck) {
        hand.push_back(deck.drawCard());
    }
    void showHand() {
        cout << name << "'s hand: ";
        for (size_t i = 0; i < hand.size(); ++i) {
            cout << i + 1 << ". [" << colorToString(hand[i].color) << " " << hand[i].value << "] ";
        }
        cout << endl;
    }

    vector<Card> chooseBestCards(Card topCard) {
        vector<Card> bestPlay;
        Card firstMatch = { NONE, -1 };

        for (const auto& card : hand) {
            if (card.color == topCard.color || card.value == topCard.value) {
                firstMatch = card;
                break;
            }
        }

        if (firstMatch.value == -1) {
            return {};
        }

        for (auto it = hand.begin(); it != hand.end();) {
            if (it->value == firstMatch.value) {
                bestPlay.push_back(*it);
                it = hand.erase(it);
            }
            else {
                ++it;
            }
        }
        return bestPlay;
    }

    vector<Card> playerTurn(Card topCard, Deck& deck) {
        showHand();
        cout << "Top card: [" << colorToString(topCard.color) << " " << topCard.value << "]" << endl;
        int choice;
        do {
            cout << "Choose a card to play (1-" << hand.size() << ") or enter 0 to draw: ";
            cin >> choice;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                choice = -1;
            }
            if (choice == 0) {
                drawCard(deck);
                return {};
            }
        } while (choice < 1 || choice > static_cast<int>(hand.size()));

        Card selectedCard = hand[choice - 1];
        vector<Card> playedCards;
        for (auto it = hand.begin(); it != hand.end();) {
            if (it->value == selectedCard.value) {
                playedCards.push_back(*it);
                it = hand.erase(it);
            }
            else {
                ++it;
            }
        }
        return playedCards;
    }
};

int main() {
    Deck deck;
    int numPlayers, numBots, difficulty;
    vector<Player> players;

    cout << "Enter number of human players (1-4): ";
    cin >> numPlayers;
    cout << "Enter number of bots (1-4): ";
    cin >> numBots;
    cout << "Choose bot difficulty (1 - Easy, 2 - Hard): ";
    cin >> difficulty;

    for (int i = 0; i < numPlayers; ++i) {
        players.push_back(Player("Player " + std::to_string(i + 1)));
    }
    for (int i = 0; i < numBots; ++i) {
        players.push_back(Player("Bot " + std::to_string(i + 1), true, difficulty));
    }

    for (auto& player : players) {
        for (int i = 0; i < 5; ++i) {
            player.drawCard(deck);
        }
    }

    cout << "Starting game..." << endl;
    Card topCard = deck.drawCard();
    bool gameOver = false;

    while (!gameOver) {
        for (auto& player : players) {
            cout << "\n" << player.name << "'s turn:\n";
            vector<Card> playedCards;
            if (player.isBot) {
                this_thread::sleep_for(chrono::seconds(1));
                playedCards = player.chooseBestCards(topCard);
                if (!playedCards.empty()) {
                    cout << player.name << " plays: ";
                    for (const auto& card : playedCards) {
                        cout << "[" << colorToString(card.color) << " " << card.value << "] ";
                    }
                    cout << endl;
                }
                else {
                    cout << player.name << " says: 'I take a card and skip my turn.'" << endl;
                    player.drawCard(deck);
                    continue;
                }
            }
            else {
                playedCards = player.playerTurn(topCard, deck);
            }
            if (!playedCards.empty()) {
                topCard = playedCards.front();
            }
            if (player.hand.empty()) {
                cout << "\n" << player.name << " WINS! Game Over." << endl;
                gameOver = true;
                break;
            }
        }
    }
    return 0;
}
