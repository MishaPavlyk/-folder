#include <iostream>
#include <vector>
#include <iomanip>

void displayGrades(const std::vector<double>& grades) {
    std::cout << "Grades: ";
    for (double grade : grades) {
        std::cout << grade << " ";
    }
    std::cout << std::endl;
}

void retakeExam(std::vector<double>& grades) {
    int index;
    double newGrade;

    std::cout << "Enter the index of the grade to change (1-10): ";
    std::cin >> index;

    if (index < 1 || index > 10) {
        std::cout << "Invalid index!" << std::endl;
        return;
    }

    std::cout << "Enter the new grade: ";
    std::cin >> newGrade;

    grades[index - 1] = newGrade;
    std::cout << "Grade updated successfully." << std::endl;
}

void checkScholarship(const std::vector<double>& grades) {
    double sum = 0;
    for (double grade : grades) {
        sum += grade;
    }

    double average = sum / grades.size();
    std::cout << "Average grade: " << std::fixed << std::setprecision(2) << average << std::endl;

    if (average >= 10.7) {
        std::cout << "Scholarship is awarded." << std::endl;
    }
    else {
        std::cout << "No scholarship." << std::endl;
    }
}

int main() {
    std::vector<double> grades(10);
    std::cout << "Enter 10 grades: ";
    for (double& grade : grades) {
        std::cin >> grade;
    }

    int choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Display grades\n";
        std::cout << "2. Retake exam\n";
        std::cout << "3. Check scholarship\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            displayGrades(grades);
            break;
        case 2:
            retakeExam(grades);
            break;
        case 3:
            checkScholarship(grades);
            break;
        case 4:
            std::cout << "Exiting..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice!" << std::endl;
        }
    } while (choice != 4);

    return 0;
}
