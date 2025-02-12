#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct Node {
    string license_plate;
    vector<string> violations;
    Node* left, * right;
    Node(string plate, string violation) : license_plate(plate), left(nullptr), right(nullptr) {
        violations.push_back(violation);
    }
};

class TrafficDatabase {
private:
    Node* root;

    Node* insert(Node* node, string plate, string violation) {
        if (!node) return new Node(plate, violation);
        if (plate < node->license_plate)
            node->left = insert(node->left, plate, violation);
        else if (plate > node->license_plate)
            node->right = insert(node->right, plate, violation);
        else
            node->violations.push_back(violation);
        return node;
    }

    void printInOrder(Node* node) {
        if (!node) return;
        printInOrder(node->left);
        cout << "Car " << node->license_plate << ": ";
        for (const string& v : node->violations) cout << v << ", ";
        cout << endl;
        printInOrder(node->right);
    }

    Node* search(Node* node, string plate) {
        if (!node || node->license_plate == plate) return node;
        if (plate < node->license_plate)
            return search(node->left, plate);
        return search(node->right, plate);
    }

    void printRange(Node* node, string low, string high) {
        if (!node) return;
        if (low < node->license_plate) printRange(node->left, low, high);
        if (low <= node->license_plate && node->license_plate <= high) {
            cout << "Car " << node->license_plate << ": ";
            for (const string& v : node->violations) cout << v << ", ";
            cout << endl;
        }
        if (high > node->license_plate) printRange(node->right, low, high);
    }

public:
    TrafficDatabase() : root(nullptr) {}

    void addTicket(string plate, string violation) {
        root = insert(root, plate, violation);
    }

    void printAll() {
        printInOrder(root);
    }

    void printByPlate(string plate) {
        Node* node = search(root, plate);
        if (node) {
            cout << "Car " << plate << ": ";
            for (const string& v : node->violations) cout << v << ", ";
            cout << endl;
        }
        else {
            cout << "No records for " << plate << endl;
        }
    }

    void printByRange(string low, string high) {
        printRange(root, low, high);
    }
};

int main() {
    TrafficDatabase db;
    db.addTicket("AA1234BB", "Speeding");
    db.addTicket("AB5678CC", "Parking Violation");
    db.addTicket("AA1234BB", "Running Red Light");
    db.addTicket("AC9999DD", "Speeding");

    cout << "Full database:\n";
    db.printAll();

    cout << "\nSearch by plate AA1234BB:\n";
    db.printByPlate("AA1234BB");

    cout << "\nSearch by range AB0000 - AC9999:\n";
    db.printByRange("AB0000", "AC9999");

    return 0;
}
