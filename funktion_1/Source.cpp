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

int main() {
    int day1, month1, year1;
    int day2, month2, year2;

    std::cout << "Enter first date (day month year): ";
    std::cin >> day1 >> month1 >> year1;

    std::cout << "Enter second date (day month year): ";
    std::cin >> day2 >> month2 >> year2;

    int difference = differenceBetweenDates(day1, month1, year1, day2, month2, year2);

    std::cout << "Difference between dates in days: " << difference << std::endl;

    return 0;
}