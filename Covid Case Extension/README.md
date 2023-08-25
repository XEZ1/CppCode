# Practical C++ Problem-Solving

## Overview

This repository showcases a series of practical C++ problem-solving tasks that involve working with fundamental programming concepts such as vectors, functions, classes, and pointers. 

## Features

- **Covid Cases Class Extensions**: Enhance the CovidCase class introduced in the previous part (**Countdown Problem Solver**) by implementing equality operators, getter functions, and additional constructors. This exercise mirrors real-world scenarios where class functionalities are extended to meet evolving requirements.

- **Covid Case Map**: Build the CovidCaseMap class to manage a vector of CovidCases. The class allows you to add CovidCases and analyse active cases over time, emulating practical data analysis tasks.

- **Covid Support Visit Route Planning**: Solve the Covid support visit route planning challenge (typical **travelling salesman problem**) by implementing a solution for efficient route planning to visit Covid-positive patients and return to the starting location. This exercise addresses real-world logistical challenges.

- **String Construction**: Tackle a string construction problem that reflects common software engineering tasks. Solution calculates the most cost-effective way to construct a target string using append and clone operations, showcasing algorithmic problem-solving skills.

## Testing

1. Clone this repository to your local machine:
```
git clone https://github.com/XEZ1/C++Code
```
2. Navigate to the relevant directory:
```
cd C++Code/Covid Case Extension
```
3. Compile the program using the following command:
```
g++ -std=c++11 -o CovidProblemExtensionTest CovidCaseMapTest1.cpp CovidCaseMapTest2.cpp TestCovidExt.cpp TestStringCons.cpp
```
4. Run the compiled program:
```
./CovidProblemExtensionTest
```

## Notes

- The program assumes that the necessary libraries (string, iostream, cmath and vector) are available for use. It avoids using any other external libraries to ensure simplicity and control.
