#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

string generateNumber() {
    string number;
    while (number.size() < 4) {
        char digit = '0' + rand() % 10;
        if (number.find(digit) == string::npos) { 
            number += digit;
        }
    }
    return number;
}

void calculateBullsAndCows(const string& secret, const string& guess, int& bulls, int& cows) {
    bulls = 0;
    cows = 0;
    for (int i = 0; i < 4; ++i) {
        if (guess[i] == secret[i]) {
            ++bulls;
        }
        else if (secret.find(guess[i]) != string::npos) {
            ++cows;
        }
    }
}

void playGame(const string& secret, int attempts = 1) {
    string guess;
    cout << "Enter your guess (4 unique digits): ";
    cin >> guess;

    if (guess.size() != 4 || guess.find_first_not_of("0123456789") != string::npos) {
        cout << "Invalid input. Please enter a 4-digit number with unique digits.\n";
        playGame(secret, attempts);
        return;
    }

    int bulls, cows;
    calculateBullsAndCows(secret, guess, bulls, cows);

    if (bulls == 4) {
        cout << "Congratulations! You guessed the number in " << attempts << " attempts.\n";
        return;
    }
    else {
        cout << "Bulls: " << bulls << ", Cows: " << cows << "\n";
        playGame(secret, attempts + 1);
    }
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    string secret = generateNumber();
    cout << "Welcome to Bulls and Cows!\n";
    playGame(secret);

    return 0;
}
