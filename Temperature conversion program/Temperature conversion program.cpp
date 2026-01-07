#include <iostream>
#include <iomanip>
#include <cctype> // for toupper()

// Convert Celsius to Fahrenheit
double celsiusToFahrenheit(double c) {
    return (c * 1.8) + 32.0;
}

// Convert Fahrenheit to Celsius
double fahrenheitToCelsius(double f) {
    return (f - 32.0) / 1.8;
}

int main() {
    double temp{};
    char unit{};
    char choice{};

    std::cout << "********* TEMPERATURE CONVERSION *********\n";

    do {
        std::cout << "Convert to (C/F): ";
        std::cin >> unit;
        unit = toupper(unit);

        if (unit == 'F') {
            std::cout << "Enter temperature in Celsius: ";
            if (!(std::cin >> temp)) {
                std::cout << "Invalid input. Please enter a number.\n";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                continue;
            }

            std::cout << std::fixed << std::setprecision(2);
            std::cout << "Temperature is: " << celsiusToFahrenheit(temp) << " F\n";

        } else if (unit == 'C') {
            std::cout << "Enter temperature in Fahrenheit: ";
            if (!(std::cin >> temp)) {
                std::cout << "Invalid input. Please enter a number.\n";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                continue;
            }

            std::cout << std::fixed << std::setprecision(2);
            std::cout << "Temperature is: " << fahrenheitToCelsius(temp) << " C\n";

        } else {
            std::cout << "Invalid unit. Please enter C or F.\n";
            continue;
        }

        std::cout << "Do you want to convert another temperature? (y/n): ";
        std::cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    std::cout << "*****************************************\n";
    return 0;
}
