#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
#include <memory>
#include <utility>

using std::cout;
using std::cerr;
using std::endl;
using std::ostream;
using std::unique_ptr;
using std::pair;


template<typename T>
class TreeNode
{
private:
    //pass
public:
    T data;
    unique_ptr<TreeNode> leftChild;
    unique_ptr<TreeNode> rightChild;
    TreeNode* parent;

    TreeNode(const T& dataIn)
            : data(dataIn), parent(nullptr) {

    }

    TreeNode(const TreeNode<T>& toCopy)
            : data(toCopy.data), parent(nullptr) {

        if (toCopy.leftChild != nullptr) {
            setLeftChild(new TreeNode<T>(*toCopy.leftChild));
        }
        if (toCopy.rightChild != nullptr) {
            setRightChild(new TreeNode<T>(*toCopy.rightChild));
        }
    }

    void setLeftChild(TreeNode* child) {
        child->parent = this;
        leftChild = unique_ptr<TreeNode>(child);
    }

    void setRightChild(TreeNode* child) {
        child->parent = this;
        rightChild = unique_ptr<TreeNode>(child);
    }

    void write(ostream& o) const {
        if (leftChild != nullptr) {
            leftChild->write(o);
        }

        o << " ";
        o << data;
        o << " ";

        if (rightChild != nullptr) {
            rightChild->write(o);
        }
    }

    int maxDepth() {
        return maxDepthHelper(this);
    }

private:
    int maxDepthHelper(TreeNode<T>* currentNode) {
        if (currentNode == nullptr)
            return 0;

        int leftDepth = maxDepthHelper(currentNode->leftChild.get());
        int rightDepth = maxDepthHelper(currentNode->rightChild.get());

        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
};

template<typename T>
class TreeNodeIterator
{
private:
    TreeNode<T>* current;

public:
    TreeNodeIterator(TreeNode<T>* currentIN)
            :current(currentIN) {

    }

    T& operator*() const {
        return current->data;
    }

    bool operator==(TreeNodeIterator rhs) const {
        return current == rhs.current;
    }

    bool operator!=(TreeNodeIterator rhs) const {
        return current != rhs.current;
    }

    TreeNodeIterator operator++() {
        if (current->data == 17)
        {
            int a = 15;
            a++;

        }
        //bool notDoneAtLeastOnce = true;
        if (current->rightChild != nullptr) {
            //the leftest of current's right
            current = current->rightChild.get();
            while (current->leftChild != nullptr) {
                current = current->leftChild.get();
            }
            return TreeNodeIterator<T>(current);
        }

        //if rigth doesn't exist

        if (current->parent == nullptr)
            return TreeNodeIterator<T>(nullptr);

        //if parent exists

        //if current is the left
        if (current == current->parent->leftChild.get()) {
            current = current->parent;
            return TreeNodeIterator<T>(current);
        }

        //if (current == current->parent->rightChild.get())
        while (current->parent != nullptr && current != current->parent->leftChild.get())
            current = current->parent;

        current = current->parent;

        return TreeNodeIterator<T>(current);
    }
};


#endif

