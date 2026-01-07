#include <iostream>
#include <iomanip>

bool calculate(double a, double b, char op, double& result) {
    switch (op) {
        case '+':
            result = a + b;
            return true;
        case '-':
            result = a - b;
            return true;
        case '*':
            result = a * b;
            return true;
        case '/':
            if (b == 0) return false;
            result = a / b;
            return true;
        default:
            return false;
    }
}

int main() {
    double num1{};
    double num2{};
    double result{};
    char op{};
    char choice{};

    std::cout << "*************** CALCULATOR ***************\n";

    do {
        std::cout << "Enter the first value: ";
        if (!(std::cin >> num1)) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }

        std::cout << "Enter the second value: ";
        if (!(std::cin >> num2)) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }

        std::cout << "Enter an operation (+, -, *, /): ";
        std::cin >> op;

        if (calculate(num1, num2, op, result)) {
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "Result: " << result << "\n";
        } else {
            std::cout << "Error: Invalid operation or division by zero.\n";
        }

        std::cout << "Do another calculation? (y/n): ";
        std::cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    std::cout << "******************************************\n";
    return 0;
}
