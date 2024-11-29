/**
 * Hangman Game
*/
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

void printHangman(int attempts) {
    switch (attempts) {
        case 0:
            cout << R"(
  _______
  |     |
  |     
  |    
  |    
  |    
__|__
)" << '\n';
            break;
        case 1:
            cout << R"(
  _______
  |     |
  |     O
  |    
  |    
  |    
__|__
)" << '\n';
            break;
        case 2:
            cout << R"(
  _______
  |     |
  |     O
  |     |
  |    
  |    
__|__
)" << '\n';
            break;
        case 3:
            cout << R"(
  _______
  |     |
  |     O
  |    /|
  |    
  |    
__|__
)" << '\n';
            break;
        case 4:
            cout << R"(
  _______
  |     |
  |     O
  |    /|\
  |    
  |    
__|__
)" << '\n';
            break;
        case 5:
            cout << R"(
  _______
  |     |
  |     O
  |    /|\
  |    / 
  |    
__|__
)" << '\n';
            break;
        case 6:
            cout << R"(
  _______
  |     |
  |     O
  |    /|\
  |    / \
  |    
__|__
)" << '\n';
            break;
    }
}

void printWord(const string& word, const vector<bool>& guessed) {
    for (size_t i = 0; i < word.size(); i++) {
        if (guessed[i]) {
            cout << word[i] << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << "\n";
}

int main()
{
    vector<string> randomWords = {"book", "computer", "pizza", "ball", "canion", "cellphone"};
    int attempts = 0;
    
    srand(static_cast<unsigned int>(time(nullptr)));    // Initialize the random number generator

    string wordToGuess = randomWords[rand() % randomWords.size()];
    vector<bool> guessed(wordToGuess.size(), false);
    char guess;

    cout << "Welcome to Hangman Game!" << endl;

    while (attempts < 6)
    {
        printHangman(attempts);
        printWord(wordToGuess, guessed);

        cout << "\n\nEnter you letter: ";
        cin >> guess;
        guess = tolower(guess);
        
        if (!isalpha(guess)) {
            cout << "Invalid input. Please enter a letter.\n";
            continue;
        }

        bool found = false;
        for (size_t i = 0; i < wordToGuess.size(); i++)
        {
            if (wordToGuess[i] == guess)
            {
                guessed[i] = true;
                found = true;
            }
        }

        if (!found)
        {
            attempts++;
        }

        int trueCounter = 0;
        for (size_t i = 0; i < guessed.size(); i++)
        {
            if (guessed[i])
            {
                trueCounter++;
            }
        }

        if (trueCounter == guessed.size())
        {
            cout << "You won! You've guessed the word: " << wordToGuess << ".\n";

            printHangman(attempts);
            printWord(wordToGuess, guessed);
            break;
        }
    }

    if (attempts == 6)
    {
        printHangman(attempts);
        printWord(wordToGuess, guessed);

        cout << "\nGame Over! The word was: " << wordToGuess << ".\n";
    }

    return 0;
}