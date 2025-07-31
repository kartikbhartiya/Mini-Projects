# Tic Tac Toe Game in C++

A simple console-based Tic Tac Toe game implemented in C++. Two players can play the game by entering their moves as row and column coordinates.

## Features

- Two-player gameplay (`X` and `O`).
- Input validation to prevent overwriting occupied positions.
- Automatic win detection for rows, columns, and diagonals.
- Displays the game board after every move.
- Prints appropriate messages on win or draw.
- Pauses before closing so the user can see the final output.

## How to Play

- The board is a 3x3 grid.
- Input format is `xy`, where `x` is the row number and `y` is the column number:
  - Rows and columns are 1-indexed (i.e., from 1 to 3).
- Example input `23` means 2nd row, 3rd column.
- Players alternate turns, starting with Player 1 (`X`).


## Code Structure

- `player` class: Represents each player, holds their symbol (`X` or `O`), and provides methods for input, display, and win checking.
- `main()` function manages the game loop, alternates turns, and checks for winning conditions or draw.

## How to Compile and Run

Use a C++ compiler like `g++` to compile:

```bash
g++ main.cpp -o main.exe
.\main
```
## Notes

- Input validation handles occupied spaces by prompting for re-entry.
- The program uses `cin.ignore()` and `cin.get()` to pause at the end, so the console window does not close immediately (especially useful when running on Windows).
- The game loops for a maximum of 9 turns (all board spaces).

## License

This project is open source and free to use.

