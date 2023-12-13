# Task 1 - Number Guessing Game

This folder contains the source code for a simple number guessing game desktop application written in C++/CLI.

## About
This application lets the user choose a difficulty level, and based on that, it calculates the range and generates a random number in that range.
The user is allowed to guess the number in as few attempts as possible, and is given a limited amount of tries (depending on the difficulty level).
After each guess, the app indicates if the guess was too high or too low. Once the correct number is guessed, the app shows the number of attempts taken.

The app has a simple Windows Forms interface built using WinForms in Visual Studio. The core logic is implemented in C++/CLI.

## Files
- `Main.cpp` - Entry point for the application
- `MainForm.h` - Header file for the Windows Form design and the game logic

## How to run
The app was developed using Visual Studio 2022 and C++/CLI. To run it:

1. Open `Task1 - Number Guessing Game.sln` in Visual Studio
2. Build the solution
3. Run it to launch the game window

The executable will be created in `x64/Debug/` folder.
