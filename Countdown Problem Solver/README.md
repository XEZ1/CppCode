# C++ Countdown Problem Solver

This repository contains a C++ program that solves Countdown numbers game problems. The program utilises basic building blocks of C++ including vectors, functions, and classes to implement the solution.

## Introduction

The Countdown numbers game is a mathematical challenge where players are given six integer numbers and a target integer number. The goal is to combine the given numbers using the mathematical operators (+, -, *, /) to get as close as possible to the target number. Each number can only be used once, but it is not mandatory to use all numbers.

## Features

- **COVID Case Data Handling**: The program includes a module to work with data about individuals who have tested positive for COVID. It uses latitude, longitude, name, age, and testing time to represent COVID cases. The `CovidCase` class is designed to store and manipulate this data.

- **RPN Expression Evaluation**: The program can evaluate Reverse Polish Notation (RPN) expressions. An `evaluateCountdown` function has been implemented to evaluate RPN expressions, allowing for efficient arithmetic calculations.

- **Countdown Problem Solver**: The repository includes a module to solve Countdown numbers game problems. The `CountdownSolution` class stores the solution in the form of an RPN expression and the evaluated value. The `solveCountdownProblem` function finds the best solution to get as close as possible to the target number using the given numbers and mathematical operators.

## Testing

1. Clone this repository to your local machine:
```
git clone https://github.com/XEZ1/C++Code.git
```
2. Navigate to the relevant directory:
```
cd C++Code/Countdown Problem Solver
```
3. Compile the program using the following command:
```
g++ -std=c++11 -o TestCountdownSolver BasicCovidTest.cpp CovidPrintTest.cpp CovidDistanceTest.cpp TestEval.cpp TestCountdown.cpp
```
4. Run the compiled program to test COVID case data handling, RPN expression evaluation, and Countdown problem solving:
```
./TestCountdownSolver
```
The program will execute various test cases and display the results.

## Notes

- The program assumes that the necessary libraries (string, sstream, and vector) are available for use. It avoids using any other external libraries to ensure simplicity and control.

- The solution approach for solving Countdown problems involves constructing RPN expressions, evaluating them, and selecting the best solution based on proximity to the target number.

