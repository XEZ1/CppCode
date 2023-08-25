#ifndef NODE_H
#define NODE_H

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;


template<typename T>
class Node
{
public:
    T data;
    Node<T> * next;
    Node<T> * previous;

    Node(const T& dataIn)
    : data(dataIn), next(nullptr), previous(nullptr) {

    }

    /**
     * todo: THIS DISTRUCTOR!
     *
     *  ~Node() {
        while (next != nullptr) {
            Node<T> * temporaryNode = next;
            next = next->next;
            delete temporaryNode;
        }
        delete next;
        while (previous != nullptr) {
            Node<T> * temporaryNode = previous;
            previous = previous->previous;
            delete temporaryNode;
        }
        delete previous;

        //delelte this
    }
     */

};

// (Note the 'NodeIterator' class will report lots of errors until Node exists


template<typename T>
class NodeIterator
{
private:
    Node<T> * current;
    
public:
    NodeIterator(Node<T> * currentIn)
        : current(currentIn) {        
    }

    T & operator*() const {
        return current->data;
    }

    NodeIterator operator++() {
        current = current->next;
        return current;
    }

    NodeIterator operator--() {
        current = current->previous;
        return current;
    }

    const bool operator==(const NodeIterator<T>& rhs) const {
        return current == rhs.current;
    }

    const bool operator!=(const NodeIterator<T>& rhs) const {
        return current != rhs.current;
    }

    Node<T> * getCurrent() const {
        return current;
    }
    
};


template<typename T>
class NodeIteratorConst
{
private:
    Node<T> * current;

public:
    NodeIteratorConst(Node<T> * currentIn)
            : current(currentIn) {
    }

    const T & operator*() const{
        return current->data;
    }

    const NodeIteratorConst operator++() {
        current = current->next;
        return current;
    }

    const NodeIteratorConst operator--() {
        current = current->previous;
        return current;
    }

    const bool operator==(const NodeIteratorConst<T>& rhs) const {
        return current == rhs.current;
    }

    const bool operator!=(const NodeIteratorConst<T>& rhs) const {
        return current != rhs.current;
    }

    const Node<T> * getCurrent() const {
        return current;
    }

};


#endif



