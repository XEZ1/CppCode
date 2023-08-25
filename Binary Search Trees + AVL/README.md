# Binary Search Trees

Welcome to this repository showcasing Binary Search Tree implementation in C++. 

## Introduction

In this repository, you will find a C++ implementation of a Binary Search Tree template class. The purpose of this implementation is to demonstrate a solid understanding of binary tree structures, balancing techniques, and efficient data retrieval.

## Motivation

This project was undertaken to enhance proficiency in working with Binary Search Trees and advanced data structure manipulation. By implementing a Binary Search Tree template class and AVL tree balancing mechanisms.

## TreeNode Implementation

The **TreeNode** class represents a node in a binary search tree. It includes the stored data, left and right child nodes pointers as `std::unique_ptr`, and a parent pointer. The class ensures proper linkage within the binary search tree structure. The **setLeftChild** and **setRightChild** functions establish these connections seamlessly. Additionally, the **write** function facilitates tree visualisation.

## BinarySearchTree Class Implementation

The **BinarySearchTree** class encapsulates the Binary Search Tree's functionality. It includes a private member variable for the root node, implemented as a `std::unique_ptr`. The class supports essential methods such as **insert** for adding data, **find** for data retrieval, **write** for tree visualisation, **maxDepth** for calculating tree depth, and AVL tree balancing operations to maintain optimal tree structure.

## TreeMap Class Implementation

The **TreeMap** class utilises the **KeyValuePair** class to create a map-like structure using a Binary Search Tree. It provides the ability to insert and find key-value pairs, allowing efficient data storage and retrieval. This class demonstrates the versatility of binary trees for various data structures.

## Tree Iterator Implementation

The **TreeNodeIterator** class is an iterator designed for traversing the binary search tree in ascending order. It facilitates seamless navigation through tree nodes. The extended functionality of **begin** and **end** iterators in the **BinarySearchTree** class ensures straightforward tree traversal.

## AVL Trees

The project goes beyond basic Binary Search Trees to implement AVL tree balancing techniques. AVL trees automatically maintain a balanced structure, preventing degeneration into linked lists. The four rotation operations (**left**, **right**, **left-right**, and **right-left**) are applied when necessary to ensure efficient and balanced tree operations.

To evaluate the correctness of the implementation, an extensive testing suite has been provided. The **TestTreeNode.cpp**, **TestTree.cpp**, **TestTreeD.cpp**, and **TestTreeMap.cpp** files validate the functionality and robustness of the Binary Search Tree and TreeMap implementations.

## Testing

A comprehensive testing suite has been developed to ensure the correctness and robustness of the implementation. The provided test files validate the functionality of the Binary Search Tree, AVL and cover various scenarios, including edge cases and corner cases.

To compile and run the tests, simply execute the provided Makefiles or compile commands. This thorough testing approach demonstrates the reliability and stability of the Linked List implementation.

1. Clone this repository to your local machine:
```
git clone https://github.com/XEZ1/C++Code
```
2. Navigate to the relevant directory:
```
cd C++Code/Binary Search Trees + AVL
```
3. Compile the program using the following command:
```
g++ -std=c++11 -o TestTrees TestTreeNode.cpp TestTree.cpp TestTreeMap.cpp TestTreeD.cpp
```
4. Run the compiled program:
```
./TestTrees
```
