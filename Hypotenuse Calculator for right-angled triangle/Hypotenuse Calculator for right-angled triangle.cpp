#include <iostream>
#include <cmath>
#include <iomanip>

// Calculates the hypotenuse of a right-angled triangle
double calculateHypotenuse(double a, double b) {
    return std::hypot(a, b);
}

int main() {
    double a{};
    double b{};
    char choice{};

    do {
        std::cout << "Enter side A: ";
        if (!(std::cin >> a) || a <= 0) {
            std::cout << "Invalid input. Please enter a positive number.\n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }

        std::cout << "Enter side B: ";
        if (!(std::cin >> b) || b <= 0) {
            std::cout << "Invalid input. Please enter a positive number.\n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }

        const double hypotenuse = calculateHypotenuse(a, b);

        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Hypotenuse is: " << hypotenuse << "\n";

        std::cout << "Do you want to calculate again? (y/n): ";
        std::cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
