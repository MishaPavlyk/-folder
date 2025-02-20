#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <cctype>

std::string cleanWord(const std::string& word) {
    std::string cleaned;
    for (char ch : word) {
        if (std::isalnum(ch)) {
            cleaned += std::tolower(ch);
        }
    }
    return cleaned;
}

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");

    if (!inputFile) {
        std::cerr << "Failed to open input.txt" << std::endl;
        return 1;
    }

    std::map<std::string, int> wordFrequency;
    std::string line, word;

    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        while (ss >> word) {
            word = cleanWord(word);
            if (!word.empty()) {
                wordFrequency[word]++;
            }
        }
    }

    inputFile.close();

    std::cout << "Word frequency dictionary:\n";
    outputFile << "Word frequency dictionary:\n";
    for (const auto& entry : wordFrequency) {
        std::cout << entry.first << ": " << entry.second << " time(s)\n";
        outputFile << entry.first << ": " << entry.second << " time(s)\n";
    }

    std::string mostFrequentWord;
    int maxFrequency = 0;

    for (const auto& entry : wordFrequency) {
        if (entry.second > maxFrequency) {
            maxFrequency = entry.second;
            mostFrequentWord = entry.first;
        }
    }

    std::cout << "\nMost frequent word: " << mostFrequentWord << " (" << maxFrequency << " time(s))\n";
    outputFile << "\nMost frequent word: " << mostFrequentWord << " (" << maxFrequency << " time(s))\n";

    outputFile.close();

    return 0;
}
