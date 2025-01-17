#include <iostream>
#include <cmath>

struct Complex {
    double real;
    double imag;

    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag,
            real * other.imag + imag * other.real);
    }

    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        return Complex((real * other.real + imag * other.imag) / denominator,
            (imag * other.real - real * other.imag) / denominator);
    }

    void display() const {
        std::cout << real << (imag >= 0 ? " + " : " - ") << fabs(imag) << "i" << std::endl;
    }
};

int main() {
    double r1, i1, r2, i2;

    std::cout << "Enter real and imaginary parts of the first complex number: ";
    std::cin >> r1 >> i1;
    Complex a(r1, i1);

    std::cout << "Enter real and imaginary parts of the second complex number: ";
    std::cin >> r2 >> i2;
    Complex b(r2, i2);

    Complex sum = a + b;
    Complex diff = a - b;
    Complex prod = a * b;
    Complex quot = a / b;

    std::cout << "Sum: "; sum.display();
    std::cout << "Difference: "; diff.display();
    std::cout << "Product: "; prod.display();
    std::cout << "Quotient: "; quot.display();

    return 0;
}
