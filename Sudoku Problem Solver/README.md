# Sudoku Solver

## Overview
This repository contains a Sudoku solver implemented in C++. The solver is designed to efficiently solve Sudoku puzzles of various sizes, including 9x9 and 16x16 grids. The solver employs a combination of logical deduction, search strategies, and heuristics to efficiently find solutions to Sudoku puzzles.

## Features
- **Sudoku Board Class**: The `Sudoku` class represents an incomplete Sudoku solution. It features a constructor that takes the size of the board (e.g., 9 for a 9x9 grid) and stores the incomplete solution as a matrix of possibilities for each cell.
- **Logical Deduction**: The solver uses logical deduction to set values in cells based on the constraints of Sudoku. It employs techniques to eliminate possibilities from cells' sets of possible values.
- **Search Strategies**: In more complex puzzles, the solver uses a search strategy to make educated guesses and explore possible solutions. It employs the `Searchable` class, which defines functions for checking if a puzzle is solved and generating successors with different guesses.
- **Heuristic Value**: The solver includes a heuristic that estimates how close the puzzle is to being solved. This heuristic guides the search strategy to focus on more promising paths first.
- **SudokuSquareSet**: To represent possible values for each Sudoku cell, a more efficient data structure called `SudokuSquareSet` is used. This data structure uses bit manipulation to store and manage possible values.
- **Performance Tweaks**: The solver employs various performance enhancements, such as identifying pairs of squares with identical sets of possible values and using heuristics to prioritize promising solutions.

## Usage
To use the Sudoku solver, follow these steps:
1. Compile the source code: Run the following command in the terminal to compile the solver.
```
g++ -std=c++11 -g -o SudokuSolver SudokuSolver.cpp
```
2. Run the solver: Execute the compiled binary to solve a Sudoku puzzle.
```
./SudokuSolver
```

## Testing

1. Clone this repository to your local machine:
```
git clone https://github.com/XEZ1/C++Code
```
2. Navigate to the relevant directory:
```
cd C++Code/Sudoku Problem Solver 
```
3. Compile the program using the following command:
```
g++ -std=c++11 -o TestSudokuSolver TestSudokuSquare.cpp BasicSudoku.cpp BestFSSudoku.cpp BreadthFSSudoku.cpp 
```
4. Run the compiled program:
```
./TestSudokuSolver
```
