#include <iostream>
#include <cmath>

bool isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            return year % 400 == 0;
        }
        return true;
    }
    return false;
}

int daysInMonth(int month, int year) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    return 31;
}

int dateToDays(int day, int month, int year) {
    int days = day;
    for (int y = 1; y < year; y++) {
        days += isLeapYear(y) ? 366 : 365;
    }
    for (int m = 1; m < month; m++) {
        days += daysInMonth(m, year);
    }
    return days;
}

int differenceBetweenDates(int day1, int month1, int year1, int day2, int month2, int year2) {
    int days1 = dateToDays(day1, month1, year1);
    int days2 = dateToDays(day2, month2, year2);
    return std::abs(days2 - days1);
}

double calculateAverage(const int* array, int size) {
    if (size <= 0) return 0.0;
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum / size;
}

void countElements(const int* array, int size, int& positives, int& negatives, int& zeros) {
    positives = negatives = zeros = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] > 0) {
            positives++;
        }
        else if (array[i] < 0) {
            negatives++;
        }
        else {
            zeros++;
        }
    }
}

int main() {
    int day1, month1, year1;
    int day2, month2, year2;

    std::cout << "Enter first date (day month year): ";
    std::cin >> day1 >> month1 >> year1;

    std::cout << "Enter second date (day month year): ";
    std::cin >> day2 >> month2 >> year2;

    int difference = differenceBetweenDates(day1, month1, year1, day2, month2, year2);

    std::cout << "Difference between dates in days: " << difference << std::endl;

    int array[] = { 1, -2, 3, 0, -5, 6, 0, -8 };
    int size = sizeof(array) / sizeof(array[0]);
    double average = calculateAverage(array, size);

    std::cout << "Average of array elements: " << average << std::endl;

    int positives, negatives, zeros;
    countElements(array, size, positives, negatives, zeros);

    std::cout << "Positive elements: " << positives << std::endl;
    std::cout << "Negative elements: " << negatives << std::endl;
    std::cout << "Zero elements: " << zeros << std::endl;

    return 0;
}
