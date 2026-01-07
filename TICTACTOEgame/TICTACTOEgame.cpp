#include <iostream>
#include <ctime>

// Function declarations
void drawBoard(char spaces[]);
void playerMove(char spaces[], char player);
void computerMove(char spaces[], char computer);
bool checkWinner(char spaces[], char player, char computer);
bool checkTie(char spaces[]);

int main() {
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;

    srand(static_cast<unsigned int>(time(nullptr))); // seed ONCE

    drawBoard(spaces);

    while (running) {
        playerMove(spaces, player);
        drawBoard(spaces);

        if (checkWinner(spaces, player, computer) || checkTie(spaces))
            break;

        computerMove(spaces, computer);
        drawBoard(spaces);

        if (checkWinner(spaces, player, computer) || checkTie(spaces))
            break;
    }

    std::cout << "Thanks for playing!\n";
    return 0;
}

// --------------------------------------------------

void drawBoard(char spaces[]) {
    std::cout << "\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "\n";
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "\n";
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "\n";
    std::cout << "     |     |     \n\n";
}

void playerMove(char spaces[], char player) {
    int number;

    while (true) {
        std::cout << "Enter a position (1-9): ";
        std::cin >> number;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }

        number--;

        if (number < 0 || number > 8) {
            std::cout << "Invalid range.\n";
            continue;
        }

        if (spaces[number] == ' ') {
            spaces[number] = player;
            break;
        } else {
            std::cout << "Spot already taken.\n";
        }
    }
}

void computerMove(char spaces[], char computer) {
    int number;

    do {
        number = rand() % 9;
    } while (spaces[number] != ' ');

    spaces[number] = computer;
}

bool checkWinner(char spaces[], char player, char computer) {
    int wins[8][3] = {
        {0,1,2},{3,4,5},{6,7,8},
        {0,3,6},{1,4,7},{2,5,8},
        {0,4,8},{2,4,6}
    };

    for (auto &w : wins) {
        if (spaces[w[0]] != ' ' &&
            spaces[w[0]] == spaces[w[1]] &&
            spaces[w[1]] == spaces[w[2]]) {

            if (spaces[w[0]] == player)
                std::cout << "You win!\n";
            else
                std::cout << "Computer wins!\n";

            return true;
        }
    }
    return false;
}

bool checkTie(char *spaces)
{
    for(int i = 0; i < 9; i++)
    {
        if(spaces[i] == ' ')
        {
            return false;
        }
    }
    std::cout << "It's a tie\n";
    return true;
}

