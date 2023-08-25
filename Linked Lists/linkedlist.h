#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"
#include <initializer_list>
#include <utility>


template <typename T>
class LinkedList
{
private:
    Node<T> * head;
    Node<T> * tail;
    int sizeOfTheList;

public:
    //creates an empty list
    LinkedList()
            : head(nullptr), tail(nullptr), sizeOfTheList(0) {

    }
    LinkedList(const std::initializer_list<T>& elements) {
        sizeOfTheList = 0;
        for (T element : elements) {
            push_back(element);
        }
    }
    ~LinkedList() {
        if (head != nullptr) {
            while (head != nullptr && head->next != nullptr) {
                Node<T> *temporaryNode = head;
                head = head->next;
                delete temporaryNode;
            }
            delete head;
        }
        else {
            delete head;
            delete tail;
        }
    }

    void push_front(const T& item) {
        Node<T> * newNode = new Node<T>(item);
        if (sizeOfTheList == 0) {
            head = newNode;
            tail = newNode;
            newNode=nullptr;
            ++sizeOfTheList;
        }
        else {
            newNode->next = head;
            head->previous = newNode;
            head = newNode;
            ++sizeOfTheList;
        }
    }

    T& front() {
        return head->data;
    }

    void push_back(const T& item) {
        Node<T> * newNode = new Node<T>(item);
        if (sizeOfTheList == 0) {
            head = newNode;
            tail = newNode;
            newNode=nullptr;
            ++sizeOfTheList;
        }
        else {
            newNode->previous = tail;
            tail->next = newNode;
            tail = newNode;
            ++sizeOfTheList;
        }
    }

    T & back() {
        return tail->data;
    }

    int size() const {
        return sizeOfTheList;
    }

    NodeIterator<T> begin() {
        return NodeIterator<T>(head);
    }

    NodeIterator<T> end() {
        return NodeIterator<T>(tail->next);
    }

    const NodeIteratorConst<T> begin() const {
        return NodeIteratorConst<T>(head);
    }

    const NodeIteratorConst<T> end() const {
        return NodeIteratorConst<T>(tail->next);
    }

    void reverse() {
        Node<T> * currentNode = head;
        Node<T> * previousNode = nullptr;
        for (int i = 0; i < sizeOfTheList; ++i) {
            previousNode = currentNode->previous;
            currentNode->previous = currentNode->next;
            currentNode->next = previousNode;
            currentNode = currentNode->previous;
            //notDone = false;
        }
        auto temp = head;
        head = tail;
        tail = temp;
    }

    NodeIterator<T> insert(const NodeIterator<T>& whereToInsert, const T& element) {
        NodeIterator<T> whereToInsertNew = whereToInsert;
        Node<T> * newNode = new Node<T>(element);
        newNode->next = whereToInsertNew.getCurrent();
        newNode->previous = whereToInsertNew.getCurrent()->previous;
        if (whereToInsertNew.getCurrent()->previous != nullptr)
            whereToInsertNew.getCurrent()->previous->next = newNode;
        if (whereToInsertNew.getCurrent() == tail)
            tail = newNode;
        if (whereToInsertNew.getCurrent() == head)
            head = newNode;
        whereToInsertNew.getCurrent()->previous = newNode;
        whereToInsertNew = newNode;
        ++sizeOfTheList;
        return whereToInsertNew;
    }


    NodeIterator<T> erase(const NodeIterator<T>& whatToErase) {
        NodeIterator<T> whatToEraseNew = whatToErase;
        if (head->data == whatToEraseNew.getCurrent()->data) {
            whatToEraseNew.getCurrent()->next->previous = nullptr;
            auto * toDelete = head;
            head = whatToEraseNew.getCurrent()->next;
            ++whatToEraseNew;
            delete toDelete;
            --sizeOfTheList;
            return whatToEraseNew;
        }
        else if (tail->data == whatToEraseNew.getCurrent()->data){
            whatToEraseNew.getCurrent()->previous->next = nullptr;
            auto * toDelete = tail;
            tail = whatToEraseNew.getCurrent()->previous;
            --whatToEraseNew;
            delete toDelete;
            --sizeOfTheList;
            return whatToEraseNew;
        }
        else {
            whatToEraseNew.getCurrent()->previous->next = whatToEraseNew.getCurrent()->next;
            whatToEraseNew.getCurrent()->next->previous = whatToEraseNew.getCurrent()->previous;
            auto * toDelete = whatToEraseNew.getCurrent();
            whatToEraseNew = whatToEraseNew.getCurrent()->next;
            delete toDelete;
            --sizeOfTheList;
            return whatToEraseNew;
        }
    }
};


#endif



