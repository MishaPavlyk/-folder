#include <iostream>
#include <windows.h>
#include <thread>
#include <chrono>

using namespace std;

void playBeep() {
    for (int i = 0; i < 3; i++) {
        Beep(750, 300);
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

void setTextColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

int main() {
    const int YELLOW_COLOR = 14;
    const int DEFAULT_COLOR = 7;

    string text[] = {
        "'U lukomor'a dub zelenij,",
        "Zlataya zep na dupe tom,",
        "I dnem i nochju kot uchenij",
        "vse hodit po cepi krugom'"
    };

    for (const string& line : text) {
        playBeep();
        setTextColor(YELLOW_COLOR);
        cout << line << endl;
        setTextColor(DEFAULT_COLOR);
        this_thread::sleep_for(chrono::milliseconds(1000));
    }

    return 0;
}
