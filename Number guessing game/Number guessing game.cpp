#include <iostream>
#include <random>
#include <limits>

constexpr int MIN_NUMBER = 1;
constexpr int MAX_NUMBER = 100;

// Generate a random number between MIN_NUMBER and MAX_NUMBER
int generateRandomNumber() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(MIN_NUMBER, MAX_NUMBER);
    return dist(gen);
}

int main() {
    int secretNumber = generateRandomNumber();
    int guess{};
    int tries = 0;
    char choice{};

    std::cout << "************* Number Guessing Game *************\n";

    do {
        tries = 0;
        secretNumber = generateRandomNumber();

        while (true) {
            std::cout << "Enter a number (" << MIN_NUMBER << " - " << MAX_NUMBER << "): ";

            if (!(std::cin >> guess)) {
                std::cout << "Invalid input. Please enter a number.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            if (guess < MIN_NUMBER || guess > MAX_NUMBER) {
                std::cout << "Number out of range. Try again.\n";
                continue;
            }

            tries++;

            if (guess > secretNumber) {
                std::cout << "Too high!\n";
            } else if (guess < secretNumber) {
                std::cout << "Too low!\n";
            } else {
                std::cout << "Correct! You guessed it in " << tries << " tries.\n";
                break;
            }
        }

        std::cout << "Play again? (y/n): ";
        std::cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    std::cout << "************************************************\n";
    return 0;
}
