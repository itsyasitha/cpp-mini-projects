#include <iostream>
#include <random>
#include <cctype>

// ===============================
// Function Declarations
// ===============================
char getUserChoice();
char getComputerChoice();
void showChoice(char choice);
void chooseWinner(char player, char computer);

// ===============================
// Main Function
// ===============================
int main() {
    char player{};
    char computer{};
    char choice{};

    std::cout << "*******************************************\n";
    std::cout << " Welcome to the Rock Paper Scissors Game! \n";
    std::cout << "*******************************************\n";

    do {
        player = getUserChoice();
        computer = getComputerChoice();

        std::cout << "\nYour choice: ";
        showChoice(player);

        std::cout << "Computer choice: ";
        showChoice(computer);

        chooseWinner(player, computer);

        std::cout << "\nPlay again? (y/n): ";
        std::cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    std::cout << "Thanks for playing!\n";
    return 0;
}

// ===============================
// Function Definitions
// ===============================

char getUserChoice() {
    char player{};

    while (true) {
        std::cout << "\nChoose one:\n";
        std::cout << "R - Rock\nP - Paper\nS - Scissors\n";
        std::cout << "Your choice: ";
        std::cin >> player;

        player = std::tolower(player);

        if (player == 'r' || player == 'p' || player == 's')
            return player;

        std::cout << "Invalid choice. Try again.\n";
    }
}

char getComputerChoice() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dist(1, 3);

    int num = dist(gen);

    switch (num) {
        case 1: return 'r';
        case 2: return 'p';
        default: return 's';
    }
}

void showChoice(char choice) {
    switch (choice) {
        case 'r': std::cout << "Rock\n"; break;
        case 'p': std::cout << "Paper\n"; break;
        case 's': std::cout << "Scissors\n"; break;
    }
}

void chooseWinner(char player, char computer) {
    std::cout << "\nResult: ";

    if (player == computer) {
        std::cout << "It's a tie!\n";
        return;
    }

    if ((player == 'r' && computer == 's') ||
        (player == 'p' && computer == 'r') ||
        (player == 's' && computer == 'p')) {
        std::cout << "You win!\n";
    } else {
        std::cout << "Computer wins!\n";
    }
}
