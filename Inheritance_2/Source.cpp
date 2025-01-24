#include <iostream>
#include <vector>
#include <string>

class Passport {
protected:
    std::string firstName;
    std::string lastName;
    std::string dateOfBirth;
    std::string passportNumber;
    std::string nationality;

public:
    Passport(std::string fName, std::string lName, std::string dob, std::string pNumber, std::string nation)
        : firstName(fName), lastName(lName), dateOfBirth(dob), passportNumber(pNumber), nationality(nation) {}

    void display() const {
        std::cout << "\nPassport Information:" << std::endl;
        std::cout << "Name: " << firstName << " " << lastName << std::endl;
        std::cout << "Date of Birth: " << dateOfBirth << std::endl;
        std::cout << "Passport Number: " << passportNumber << std::endl;
        std::cout << "Nationality: " << nationality << std::endl;
    }
};

class ForeignPassport : public Passport {
private:
    std::string foreignPassportNumber;
    std::vector<std::string> visas;

public:
    ForeignPassport(std::string fName, std::string lName, std::string dob, std::string pNumber, std::string nation,
        std::string foreignPNumber, std::vector<std::string> visaList)
        : Passport(fName, lName, dob, pNumber, nation), foreignPassportNumber(foreignPNumber), visas(visaList) {}

    void addVisa(const std::string& visa) {
        visas.push_back(visa);
    }

    void display() const {
        Passport::display();
        std::cout << "Foreign Passport Number: " << foreignPassportNumber << std::endl;
        std::cout << "Visas: ";
        for (const auto& visa : visas) {
            std::cout << visa << ", ";
        }
        std::cout << std::endl;
    }
};

int main() {
    std::vector<std::string> visas = { "USA", "Canada", "Germany" };
    ForeignPassport foreignPass("John", "Doe", "1990-01-01", "UA123456", "Ukrainian", "FP987654", visas);

    foreignPass.display();

    foreignPass.addVisa("UK");
    std::cout << "\nAfter adding a new visa:" << std::endl;
    foreignPass.display();

    return 0;
}