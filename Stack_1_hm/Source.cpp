#include <iostream>
#include <stack>
#include <string>

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
        (open == '{' && close == '}') ||
        (open == '[' && close == ']');
}

void checkBrackets(const std::string& str) {
    std::stack<char> bracketStack;
    std::stack<size_t> indexStack;

    for (size_t i = 0; i < str.length(); ++i) {
        char ch = str[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            bracketStack.push(ch);
            indexStack.push(i);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (bracketStack.empty()) {
                std::cout << "Error: unmatched closing bracket '" << ch << "' at position " << i + 1 << ".\n";
                std::cout << str.substr(0, i + 1) << "\n";
                return;
            }

            char top = bracketStack.top();
            if (!isMatchingPair(top, ch)) {
                std::cout << "Error: mismatched brackets '" << top << "' and '" << ch << "' at position " << i + 1 << ".\n";
                std::cout << str.substr(0, i + 1) << "\n";
                return;
            }

            bracketStack.pop();
            indexStack.pop();
        }
        else if (ch == ';') {
            break; // End of input detected
        }
    }

    if (!bracketStack.empty()) {
        std::cout << "Error: unmatched opening bracket '" << bracketStack.top() << "' at position " << indexStack.top() + 1 << ".\n";
        std::cout << str.substr(0, indexStack.top() + 1) << "\n";
    }
    else {
        std::cout << "The string is correct.\n";
    }
}

int main() {
    std::string input;
    std::cout << "Enter a string ending with ';': ";
    std::getline(std::cin, input);

    checkBrackets(input);

    return 0;
}