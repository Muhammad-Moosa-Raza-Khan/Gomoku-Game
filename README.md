Gomoku: The Game of Legend
Overview
This project is a C++ implementation of Gomoku, a classic board game where players take turns placing their symbols on a grid. The goal is to be the first to align a specified number of symbols (WIN_COUNT) in a row—vertically, horizontally, or diagonally. The game supports customizable settings, including grid size, player count, and symbols.

Features
Customizable Grid: Play on a grid of any dimension (up to 100x100).

Flexible Player Count: Supports 1+ players with unique symbols for each.

Adjustable Win Condition: Set the required number of symbols in a row to win (WIN_COUNT).

Input Validation: Ensures valid moves and provides error feedback.

Win/Draw Detection: Automatically checks for wins or a draw after each move.

How to Play
Setup:

Enter the grid dimension (e.g., 15 for a 15x15 board).

Specify the number of players and their symbols (e.g., X and O).

Set the WIN_COUNT (e.g., 5 for Gomoku's standard five-in-a-row).

Gameplay:

Players take turns entering row and column indices (0-based) to place their symbols.

The game ends when a player meets the WIN_COUNT or the board fills up (draw).

Code Structure
Win Detection: Functions like IsHorizontalWin, IsVerticalWin, and IsDiagonalTL2BR check for winning conditions.

Game Logic: Handles turn management, board updates, and input validation.

UI: Simple console-based interface for input/output.

Example
plaintext
Enter dimension of the grid: 10
Enter how many players: 2
Enter player symbols: X O
Enter Win Count: 5
...
Player X's Turn
Enter row: 3
Enter column: 4
Requirements
C++ compiler (e.g., g++).

How to Run
Compile: g++ PF_Final_Project.cpp -o gomoku

Execute: ./gomoku (Linux/Mac) or gomoku.exe (Windows).

Future Improvements
GUI implementation (e.g., using SFML or Qt).

AI opponent for single-player mode.

Score tracking across multiple games.

Enjoy the game! 🎮
