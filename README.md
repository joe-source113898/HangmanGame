# HangmanGame
Welcome to the Hangman Game! This program, written in C++, allows the player to guess a randomly generated word before completing the hangman drawing.

## Features

- Randomly generated words from a predefined list.
- ASCII-based hangman drawing updated with each failed attempt.
- Input validation (only letters are allowed).
- Clear win or lose messages.

## Requirements

To compile and run the program, you need:

- A C++ compiler compatible with C++11 or later (e.g., `g++`).
- An environment that supports console programs.

## How to Run

1. Compile the source code using a C++ compiler. For example:
   ```bash
   g++ -o hangman hangman.cpp
   ```

2. Run the program:
   ```bash
   ./hangman
   ```

3. Follow the on-screen instructions to play.

## Game Rules

1. A random word is generated, and the player must guess it.
2. The player inputs one letter per turn.
3. If the letter is in the word, its position(s) are revealed.
4. If the letter is not in the word, the number of failed attempts increases, and the hangman drawing is updated.
5. The game ends when:
   - The player guesses all the letters in the word (Victory! 🎉).
   - The hangman is fully drawn after 6 failed attempts (Game Over 😞).

## Example Gameplay

```text
Welcome to Hangman Game!

  _______
  |     |
  |     
  |    
  |    
  |    
__|__

_ _ _ _ _ _ 

Enter your letter: c

  _______
  |     |
  |     
  |    
  |    
  |    
__|__

_ _ _ c _ _ 
```

## Customization

- You can modify the available words by editing the `randomWords` vector in the source code.
- To increase or decrease difficulty, adjust the number of allowed attempts by changing the limit in `while (attempts < 6)`.

## Contributions

If you have ideas to improve the code or add new features, feel free to fork the repository and submit a pull request.

---

Thank you for playing Hangman Game!
