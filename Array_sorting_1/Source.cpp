#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Contact {
    std::string mobile;
    std::string home;
};

void sortByMobile(std::vector<Contact>& contacts) {
    std::sort(contacts.begin(), contacts.end(), [](const Contact& a, const Contact& b) {
        return a.mobile < b.mobile;
        });
}

void sortByHome(std::vector<Contact>& contacts) {
    std::sort(contacts.begin(), contacts.end(), [](const Contact& a, const Contact& b) {
        return a.home < b.home;
        });
}

void displayContacts(const std::vector<Contact>& contacts) {
    std::cout << "\nList of users:" << std::endl;
    for (const auto& contact : contacts) {
        std::cout << "Mobile: " << contact.mobile << ", Home: " << contact.home << std::endl;
    }
}

int main() {
    std::vector<Contact> contacts = {
        {"0951234567", "0441234567"},
        {"0677654321", "0447654321"},
        {"0509876543", "0449876543"},
        {"0934567890", "0444567890"}
    };

    int choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Sort by mobile numbers\n";
        std::cout << "2. Sort by home numbers\n";
        std::cout << "3. Display the list of users\n";
        std::cout << "4. Exit\n";
        std::cout << "Your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            sortByMobile(contacts);
            std::cout << "\nList sorted by mobile numbers.\n";
            break;
        case 2:
            sortByHome(contacts);
            std::cout << "\nList sorted by home numbers.\n";
            break;
        case 3:
            displayContacts(contacts);
            break;
        case 4:
            std::cout << "\nExiting the program.\n";
            break;
        default:
            std::cout << "\nInvalid choice. Please try again.\n";
            break;
        }
    } while (choice != 4);

    return 0;
}
