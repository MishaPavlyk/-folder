#include <iostream>
#include <map>
#include <fstream>
#include <string>

using namespace std;

class Dictionary {
private:
    map<string, string> words;

public:
    void addWord(const string& word, const string& definition) {
        words[word] = definition;
        cout << "Word added.\n";
    }

    void removeWord(const string& word) {
        if (words.erase(word)) {
            cout << "Word removed.\n";
        }
        else {
            cout << "Word not found.\n";
        }
    }

    void editWord(const string& word, const string& newDefinition) {
        auto it = words.find(word);
        if (it != words.end()) {
            it->second = newDefinition;
            cout << "Word edited.\n";
        }
        else {
            cout << "Word not found.\n";
        }
    }

    void findWord(const string& word) const {
        auto it = words.find(word);
        if (it != words.end()) {
            cout << word << ": " << it->second << "\n";
        }
        else {
            cout << "Word not found.\n";
        }
    }

    void saveToFile(const string& filename) const {
        ofstream file(filename);
        if (file) {
            for (const auto& pair : words) {
                file << pair.first << "=" << pair.second << "\n";
            }
            cout << "Dictionary saved to file.\n";
        }
        else {
            cout << "File save error.\n";
        }
    }

    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (file) {
            words.clear();
            string line;
            while (getline(file, line)) {
                size_t pos = line.find('=');
                if (pos != string::npos) {
                    string word = line.substr(0, pos);
                    string definition = line.substr(pos + 1);
                    words[word] = definition;
                }
            }
            cout << "Dictionary loaded from file.\n";
        }
        else {
            cout << "File open error.\n";
        }
    }
};

int main() {
    Dictionary dict;
    int choice;
    string word, definition, filename;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add word\n";
        cout << "2. Remove word\n";
        cout << "3. Edit word\n";
        cout << "4. Find word\n";
        cout << "5. Save dictionary to file\n";
        cout << "6. Load dictionary from file\n";
        cout << "0. Exit\n";
        cout << "Your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Enter word: ";
            getline(cin, word);
            cout << "Enter definition: ";
            getline(cin, definition);
            dict.addWord(word, definition);
            break;
        case 2:
            cout << "Enter word to remove: ";
            getline(cin, word);
            dict.removeWord(word);
            break;
        case 3:
            cout << "Enter word to edit: ";
            getline(cin, word);
            cout << "Enter new definition: ";
            getline(cin, definition);
            dict.editWord(word, definition);
            break;
        case 4:
            cout << "Enter word to find: ";
            getline(cin, word);
            dict.findWord(word);
            break;
        case 5:
            cout << "Enter filename: ";
            getline(cin, filename);
            dict.saveToFile(filename);
            break;
        case 6:
            cout << "Enter filename: ";
            getline(cin, filename);
            dict.loadFromFile(filename);
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}
