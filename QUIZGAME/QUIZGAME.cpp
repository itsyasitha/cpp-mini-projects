#include <iostream>
#include <string>
#include <cctype>   // for toupper()

// Constants
const int NUM_QUESTIONS = 4;
const int NUM_OPTIONS = 4;

// Function to ask a single question and return whether the user was correct
bool askQuestion(const std::string &question, const std::string options[], char correctAnswer)
{
    std::cout << "************************" << std::endl;
    std::cout << question << std::endl;
    std::cout << "************************" << std::endl;

    // Display options
    for (int i = 0; i < NUM_OPTIONS; i++)
    {
        std::cout << options[i] << std::endl;
    }

    char guess;
    bool validInput = false;

    // Input validation loop
    do
    {
        std::cout << "Your answer (A-D): ";
        std::cin >> guess;
        guess = toupper(guess);

        if (guess >= 'A' && guess <= 'D')
        {
            validInput = true;
        }
        else
        {
            std::cout << "Invalid input! Please enter A, B, C, or D." << std::endl;
        }
    } while (!validInput);

    // Check answer
    if (guess == correctAnswer)
    {
        std::cout << "Correct!" << std::endl;
        return true;
    }
    else
    {
        std::cout << "Incorrect!" << std::endl;
        std::cout << "Correct answer: " << correctAnswer << std::endl;
        return false;
    }
}

int main()
{
    // Questions
    std::string questions[NUM_QUESTIONS] = {
        "1. What year was C++ created?",
        "2. Who invented C++?",
        "3. What is the predecessor of C++?",
        "4. Is the Earth flat?"
    };

    // Options for each question
    std::string options[NUM_QUESTIONS][NUM_OPTIONS] = {
        {"A. 1969", "B. 1975", "C. 1985", "D. 1989"},
        {"A. Guido van Rossum", "B. Bjarne Stroustrup", "C. John Carmack", "D. Mark Zuckerberg"},
        {"A. C", "B. C+", "C. C--", "D. B++"},
        {"A. Yes", "B. No", "C. Sometimes", "D. Maybe"}
    };

    // Correct answers
    char answerKey[NUM_QUESTIONS] = {'C', 'B', 'A', 'B'};

    int score = 0;

    // Main loop for all questions
    for (int i = 0; i < NUM_QUESTIONS; i++)
    {
        if (askQuestion(questions[i], options[i], answerKey[i]))
        {
            score++;
        }
    }

    // Display results
    std::cout << "************************" << std::endl;
    std::cout << "          RESULTS       " << std::endl;
    std::cout << "************************" << std::endl;

    std::cout << "Correct guesses: " << score << std::endl;
    std::cout << "Total questions: " << NUM_QUESTIONS << std::endl;
    std::cout << "Score: " << (score / (double)NUM_QUESTIONS) * 100 << "%" << std::endl;

    return 0;
}
