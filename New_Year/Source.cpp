#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int balance = 0;
map<string, int> inventory;

enum Question {
    RED_NOSED_REINDEER,
    TREE_TOP_DECORATION,
    CHRISTMAS_MONTH,
    FIREPLACE_HANGING,
    SANTA_SUIT_COLOR,
    QUESTION_COUNT
};

const map<Question, pair<string, string>> questions = {
    {RED_NOSED_REINDEER, {"What is the name of the red-nosed reindeer?", "Rudolph"}},
    {TREE_TOP_DECORATION, {"What is traditionally placed on top of a Christmas tree?", "Star"}},
    {CHRISTMAS_MONTH, {"In which month is Christmas celebrated?", "December"}},
    {FIREPLACE_HANGING, {"What do people hang by the fireplace on Christmas Eve?", "Stockings"}},
    {SANTA_SUIT_COLOR, {"What is the color of Santa Claus's suit?", "Red"}}
};

enum Gift {
    RED_GIFT,
    BLUE_GIFT,
    GREEN_GIFT,
    YELLOW_GIFT,
    SILVER_GIFT,
    GOLD_GIFT,
    GIFT_COUNT
};

const string giftNames[GIFT_COUNT] = {
    "Red Gift",
    "Blue Gift",
    "Green Gift",
    "Yellow Gift",
    "Silver Gift",
    "Gold Gift"
};

Gift unsortedGifts[GIFT_COUNT] = { RED_GIFT, BLUE_GIFT, GREEN_GIFT, YELLOW_GIFT, SILVER_GIFT, GOLD_GIFT };
Gift sortedGifts[GIFT_COUNT];

struct ShopItem {
    string name;
    int price;
    int quantity;
};

ShopItem shop[] = {
    {"Rain decoration", 50, 4},
    {"Christmas Tree", 5000, 1},
    {"Candy Box", 120, 7},
    {"Garland", 300, 2}
};

const int SHOP_SIZE = sizeof(shop) / sizeof(shop[0]);

void showMainMenu();
void handleQuiz();
void handleGiftSorting();
void handleShop();
void handleInventory();
void updateBalance(int amount);

int main() {
    srand(time(0));
    int choice;

    while (true) {
        system("cls"); 
        cout << "Balance: " << balance << " UAH" << endl;
        showMainMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            handleQuiz();
            break;
        case 2:
            handleGiftSorting();
            break;
        case 3:
            handleShop();
            break;
        case 4:
            handleInventory();
            break;
        case 5:
            cout << "Exiting program. Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}

void showMainMenu() {
    cout << "\n--- Main Menu ---" << endl;
    cout << "1. Quiz" << endl;
    cout << "2. Sort Gifts" << endl;
    cout << "3. Shop" << endl;
    cout << "4. Inventory" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

void handleQuiz() {
    system("cls");
    cout << "--- Quiz ---" << endl;

    double randomMulti = (rand() % 120) * 0.1;
    Question questionIndex = static_cast<Question>(rand() % QUESTION_COUNT);
    cout << questions.at(questionIndex).first << endl;

    string answer;
    cin.ignore();
    getline(cin, answer);

    if (answer == questions.at(questionIndex).second) {
        cout << "Correct! You earned " << randomMulti * 100 << " UAH.\n";
        updateBalance(100 * randomMulti);
    }
    else {
        cout << "Wrong! The correct answer was: " << questions.at(questionIndex).second << "\n";
    }

    cout << "Press Enter to continue...";
    cin.ignore();
}

void handleGiftSorting() {
    system("cls");
    cout << "--- Sort Gifts ---" << endl;

    copy(begin(unsortedGifts), end(unsortedGifts), begin(sortedGifts));
    sort(begin(sortedGifts), end(sortedGifts), [](Gift a, Gift b) {
        return giftNames[a] < giftNames[b];
        });

    string userSortedGifts[GIFT_COUNT];
    cout << "Unsorted Gifts:" << endl;
    for (const auto& gift : unsortedGifts) {
        cout << giftNames[gift] << endl;
    }

    cout << "\nPlease enter the gifts in sorted order one by one:" << endl;

    cin.ignore(); 

    for (size_t i = 0; i < GIFT_COUNT; ++i) {
        string gift;
        cout << "Gift " << i + 1 << ": ";
        getline(cin, gift);
        userSortedGifts[i] = gift;
    }

    bool isCorrect = true;
    for (size_t i = 0; i < GIFT_COUNT; ++i) {
        if (userSortedGifts[i] != giftNames[sortedGifts[i]]) {
            isCorrect = false;
            break;
        }
    }

    if (isCorrect) {
        double randomMulti = (rand() % 120) * 0.1;
        cout << "\nSorting complete! You earned " << 500* randomMulti << "UAH.\n";
        updateBalance(500*randomMulti);
    }
    else {
        cout << "\nSorting failed. Gifts were not in correct order.\n";
    }

    cout << "Press Enter to continue...";
    cin.ignore();
}

void handleShop() {
    while (true) {
        system("cls");
        cout << "--- Shop ---\n";
        double randomMulti = (rand() % 120) * 0.1;
        cout << "Infaction: " << 1 << " $ = " << 10 * randomMulti << " UAH" << endl;
        for (size_t i = 0; i < SHOP_SIZE; ++i) {
            cout << i + 1 << ". " << shop[i].name << " - " << shop[i].price * randomMulti << " UAH (" << shop[i].quantity << " left)\n"; 
            if (shop[i].price == 0) {
                cout << "Today is sale day!.\n";
            }
        }
        cout << "\nBalance: " << balance << " UAH\n";
        cout << SHOP_SIZE + 1 << ". Exit\n";

        int choice;
        cout << "Enter the number of the item to buy: ";
        cin >> choice;

        if (choice < 1 || choice > SHOP_SIZE + 1) {
            cout << "Invalid choice. Try again.\n";
            continue;
        }

        if (choice == SHOP_SIZE + 1) break;

        ShopItem& item = shop[choice - 1];

        if (item.quantity == 0) {
            cout << "Sorry, " << item.name << " is out of stock.\n";
        }
        else if (balance < item.price * randomMulti) {
            cout << "Not enough balance to buy " << item.name << ".\n";
        }
        else {
            item.quantity--;
            updateBalance(-item.price * randomMulti);
            inventory[item.name]++;
            cout << "You bought " << item.name << "!\n";
        }

        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get();
    }
}

void handleInventory() {
    system("cls");
    cout << "--- Inventory ---\n";
    for (const auto& item : inventory) {
        cout << item.first << " x" << item.second << endl;
    }
    cout << "\nBalance: " << balance << " UAH\n";
    cout << "Press Enter to go back...";
    cin.ignore();
    cin.get();
}

void updateBalance(int amount) {
    balance += amount;
}
