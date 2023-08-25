# A Collection of C++ code written throughout student years

## Table of Contents

- [Introduction](#introduction)
- [Part 1 - Countdown Problem Solver](#part-1---countdown-problem-solver)
- [Part 2 - Covid Case Extension](#part-2---covid-case-extension)
- [Part 3 - Linked List](#part-3---linked-list)
- [Part 4 - Binary Search Tree + AVL](#part-4---binary-search-tree-and-avl)
- [Part 5 - Sudoku Problem Solver](#part-5---sudoku-problem-solver)
- [Acknowledgments](#acknowledgments)

## Introduction

Welcome to the scala code collection written throughout student years. This is a collection of different code developed though various courseworks, internships and own research. The code contains 8 separate and unrelated projects.

## Part 1 - Countdown Problem Solver

In this part, a solution for the Countdown numbers game is provided. The problem itself is a mathematical challenge where players are given six integer numbers and a target integer number. The goal is to combine the given numbers using the mathematical operators (+, -, *, /) to get as close as possible to the target number. Each number can only be used once, but it is not mandatory to use all numbers. The program utilises basic building blocks of C++ including vectors, functions, and classes to implement the solution.

## Part 2 - Covid Case Extension

This repository showcases a series of practical C++ problem-solving tasks that involve working with fundamental programming concepts such as vectors, functions, classes, and pointers. This is effectively an extension to the previous problem, the solution tackles a string construction and a traveling salesman problems that reflect common software engineering tasks. Solution calculates the most cost-effective way to construct a target string using append and clone operations, showcasing algorithmic problem-solving skills. The TSP solution implements code for efficient route planning to visit Covid-positive patients and return to the starting location.

## Part 3 - Linked List

Here, we present a C++ implementation of a Linked List template class, including node and iterator classes.

## Part 4 - Binary Search Tree and AVL

This project's aim was an implementation of a Binary Search Tree template class & AVL Trees. The project goes beyond basic Binary Search Trees to implement AVL tree balancing techniques. AVL trees automatically maintain a balanced structure, preventing degeneration into linked lists. The four rotation operations (left, right, left-right, and right-left) are applied when necessary to ensure efficient and balanced tree operations.

## Part 5 - Sudoku Problem Solver

This repository contains a Sudoku solver implemented in C++. The solver is designed to efficiently solve Sudoku puzzles of various sizes, including 9x9 and 16x16 grids. The solver employs a combination of logical deduction, search strategies, and heuristics to efficiently find solutions to Sudoku puzzles.

## Testing

1. Clone this repository to your local machine:
```
git clone https://github.com/XEZ1/C++Code.git
```
2. Navigate to the relevant directory:
```
cd C++Code
```
3. Compile the program using the following command:
```
g++ -std=c++11 -o TestCountdownSolver BasicCovidTest.cpp CovidPrintTest.cpp CovidDistanceTest.cpp TestEval.cpp TestCountdown.cpp
g++ -std=c++11 -o CovidProblemExtensionTest CovidCaseMapTest1.cpp CovidCaseMapTest2.cpp TestCovidExt.cpp TestStringCons.cpp
g++ -std=c++11 -o TestListAndNodeClasses TestNode.cpp TestList.cpp TestListD.cpp
g++ -std=c++11 -o TestTrees TestTreeNode.cpp TestTree.cpp TestTreeMap.cpp TestTreeD.cpp
g++ -std=c++11 -o TestSudokuSolver TestSudokuSquare.cpp BasicSudoku.cpp BestFSSudoku.cpp BreadthFSSudoku.cpp 
```
4. Run the compiled program to test COVID case data handling, RPN expression evaluation, and Countdown problem solving:
```
./TestCountdownSolver
./CovidProblemExtensionTest
./TestListAndNodeClasses
./TestTrees
./TestSudokuSolver
```
