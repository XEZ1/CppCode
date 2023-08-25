# Linked Lists

Welcome to this repository showcasing Linked List implementation in C++. 

## Introduction

In this repository, you will find a C++ implementation of a Linked List template class. 

## Motivation

This project was undertaken to enhance proficiency in working with Linked Lists and data structure manipulation. By implementing a Linked List template class, the goal was to showcase the ability to build efficient and effective data structures from scratch, without relying on existing libraries.

## Node Implementation

The **Node** class represents a node in a doubly-linked list. It has been designed to include the data stored in the node, a pointer to the next node, and a pointer to the previous node. The class has been carefully crafted to ensure seamless integration within the Linked List.

## Iterator Implementation

The **NodeIterator** class is a template class that enables traversal through the Linked List. It supports functions such as incrementing the iterator, checking for equality, and comparing iterators. This essential tool ensures smooth navigation within the Linked List.

## Linked List Class Implementation

The **LinkedList** class is the heart of this project, encapsulating the entire Linked List functionality. It provides methods to push elements to the front and back, access the front and back elements, determine the size of the list, and iterate through the elements. The class is designed for optimal memory management and performance.

## Additional Features

The implementation goes beyond the basics to provide advanced features. It includes constructors that accept an initialiser list, allowing for convenient list initialisation. Moreover, it offers capabilities to insert and erase elements at specific positions within the Linked List, enhancing its versatility and usability.

## Testing

A comprehensive testing suite has been developed to ensure the correctness and robustness of the implementation. The provided test files validate the functionality of the Linked List and cover various scenarios, including edge cases and corner cases.

To compile and run the tests, simply execute the provided Makefiles or compile commands. This thorough testing approach demonstrates the reliability and stability of the Linked List implementation.

1. Clone this repository to your local machine:
```
git clone https://github.com/XEZ1/C++Code
```
2. Navigate to the relevant directory:
```
cd C++Code/Linked Lists
```
3. Compile the program using the following command:
```
g++ -std=c++11 -o TestListAndNodeClasses TestNode.cpp TestList.cpp TestListD.cpp
```
4. Run the compiled program:
```
./TestListAndNodeClasses
```
