#include <iostream>
#include <iomanip>
#include <limits>

// Menu options
enum MenuOption {
    SHOW_BALANCE = 1,
    DEPOSIT,
    WITHDRAW,
    EXIT
};

void showBalance(const double balance);
double getValidAmount(const std::string& prompt);
void deposit(double& balance);
void withdraw(double& balance);

int main() {
    double balance = 0.0;
    int choice = 0;

    do {
        std::cout << "\n************ BANK MENU ************\n";
        std::cout << "1. Show balance\n";
        std::cout << "2. Deposit money\n";
        std::cout << "3. Withdraw money\n";
        std::cout << "4. Exit\n";
        std::cout << "Select an option: ";

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case SHOW_BALANCE:
                showBalance(balance);
                break;

            case DEPOSIT:
                deposit(balance);
                break;

            case WITHDRAW:
                withdraw(balance);
                break;

            case EXIT:
                std::cout << "Thank you for banking with us.\n";
                break;

            default:
                std::cout << "Invalid option. Please choose 1–4.\n";
        }

    } while (choice != EXIT);

    return 0;
}

// --------------------------------------------------

void showBalance(const double balance) {
    std::cout << "Current balance: $"
              << std::fixed << std::setprecision(2)
              << balance << "\n";
}

double getValidAmount(const std::string& prompt) {
    double amount{};

    while (true) {
        std::cout << prompt;
        if (std::cin >> amount && amount > 0) {
            return amount;
        }

        std::cout << "Invalid amount. Try again.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void deposit(double& balance) {
    const double amount = getValidAmount("Enter amount to deposit: ");
    balance += amount;
    std::cout << "Deposit successful.\n";
    showBalance(balance);
}

void withdraw(double& balance) {
    const double amount = getValidAmount("Enter amount to withdraw: ");

    if (amount > balance) {
        std::cout << "Insufficient funds!\n";
        std::cout << "Balance: " << balance << std::endl;
        return;
    }

    balance -= amount;
    std::cout << "Withdrawal successful.\n";
    showBalance(balance);
}
