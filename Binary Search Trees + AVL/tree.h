#ifndef TREE_H
#define TREE_H

#include "treenode.h"


template<typename T>
class BinarySearchTree
{
private:
	unique_ptr<TreeNode<T>> root;
public:
	BinarySearchTree()
		:root(nullptr) {

	}

	BinarySearchTree(const BinarySearchTree& treeToCopy)
		:root(new TreeNode<T>(*treeToCopy.root)) {
	}

	void operator=(const BinarySearchTree& rhs) {
		BinarySearchTree toReturn(rhs);
		root = std::move(toReturn.root);
	}

	void write(ostream& o) const {
		root->write(o);
	}

	TreeNode<T>* insert(const T& dataToCheck) {
		TreeNode<T>* inserted;
		TreeNode<T>* new_root = insertRecursiveHelper(dataToCheck, root.get(), nullptr, inserted);

		if (root.get() != new_root)
			root = unique_ptr<TreeNode<T>>(new_root);

		balance(inserted);

		return inserted;
	}

	void balance(TreeNode<T>* inserted)
	{
		TreeNode<T>* parent = inserted->parent;

		if (parent == nullptr)
			return;

		TreeNode<T>* grandparent = parent->parent;

		if (grandparent == nullptr)
			return;

		int balanceFactor = grandparent->leftChild->maxDepth() - grandparent->rightChild->maxDepth();

		if (balanceFactor != -2 && balanceFactor != 2)
			return;

		if (inserted == parent->rightChild.get() && parent == grandparent->rightChild.get())
			leftRotation(parent, grandparent);
		else if (inserted == parent->leftChild.get() && parent == grandparent->leftChild.get())
			rightRotation(parent, grandparent);
		else if (inserted == parent->rightChild.get() && parent == grandparent->leftChild.get())
			LeftRightRotation(inserted, parent, grandparent);
		else if (inserted == parent->leftChild.get() && parent == grandparent->rightChild.get())
			RightLeftRotation(inserted, parent, grandparent);
	}

	void LeftRightRotation(TreeNode<T>* inserted, TreeNode<T>* parent, TreeNode<T>* grandparent)
	{
		inserted->leftChild = std::move(grandparent->leftChild);
		grandparent->leftChild = std::move(parent->rightChild);

		TreeNode<T>* buffer = inserted;
		inserted = parent;
		parent = buffer;

		inserted->parent = parent;
		parent->parent = grandparent;

		rightRotation(parent, grandparent);
	}

	void RightLeftRotation(TreeNode<T>* inserted, TreeNode<T>* parent, TreeNode<T>* grandparent)
	{
		inserted->rightChild = std::move(grandparent->rightChild);
		grandparent->rightChild = std::move(parent->leftChild);

		TreeNode<T>* buffer = inserted;
		inserted = parent;
		parent = buffer;

		inserted->parent = parent;
		parent->parent = grandparent;

		leftRotation(parent, grandparent);
	}

	void leftRotation(TreeNode<T>* parent, TreeNode<T>* grandparent)
	{
		unique_ptr<TreeNode<T>>& owner = grandparent->parent == nullptr ? root :
			(grandparent->parent->rightChild.get() == grandparent ? grandparent->parent->rightChild : grandparent->parent->leftChild);

		TreeNode<T>* grandgrandparent = grandparent->parent;

		parent->leftChild = std::move(owner);
		grandparent->parent = parent;

		owner = std::move(grandparent->rightChild);
		parent->parent = grandgrandparent;
	}

	void rightRotation(TreeNode<T>* parent, TreeNode<T>* grandparent)
	{
		unique_ptr<TreeNode<T>>& owner = grandparent->parent == nullptr ? root :
			(grandparent->parent->leftChild.get() == grandparent ? grandparent->parent->leftChild : grandparent->parent->rightChild);

		TreeNode<T>* grandgrandparent = grandparent->parent;

		parent->rightChild = std::move(owner);
		grandparent->parent = parent;

		owner = std::move(grandparent->leftChild);
		parent->parent = grandgrandparent;
	}

	TreeNode<T>* insertRecursiveHelper(const T& dataToCheck, TreeNode<T>* currentNode, TreeNode<T>* previousNode, TreeNode<T>*& inserted) { //??? why not private
		if (currentNode == nullptr) {
			TreeNode<T>* newNodeToPut = new TreeNode<T>(dataToCheck);
			newNodeToPut->parent = previousNode; //??? constructor

			inserted = newNodeToPut;

			return newNodeToPut;
		}

		if (dataToCheck < currentNode->data) { //left
			TreeNode<T>* new_left_root = insertRecursiveHelper(dataToCheck, currentNode->leftChild.get(), currentNode, inserted);

			if (currentNode->leftChild.get() == nullptr)
				currentNode->leftChild = unique_ptr<TreeNode<T>>(new_left_root);
		}
		else if (currentNode->data < dataToCheck) { //right
			TreeNode<T>* new_right_root = insertRecursiveHelper(dataToCheck, currentNode->rightChild.get(), currentNode, inserted);

			if (currentNode->rightChild.get() == nullptr)
				currentNode->rightChild = unique_ptr<TreeNode<T>>(new_right_root);
		}
		else
			inserted = currentNode;

		return currentNode;
	}

	TreeNode<T>* find(const T& dataToCheck) {

		return findHelper(root.get(), dataToCheck);
	}

	TreeNode<T>* findHelper(TreeNode<T>* currentNode, const T& dataToCheck)
	{
		if (currentNode == nullptr)
			return nullptr;

		if (!(currentNode->data < dataToCheck) && !(dataToCheck < currentNode->data)) // currentNode->data == dataToCheck
			return currentNode;

		//left
		if (dataToCheck < currentNode->data)
			return findHelper(currentNode->leftChild.get(), dataToCheck);

		//right
		return findHelper(currentNode->rightChild.get(), dataToCheck);
	}

	TreeNodeIterator<T> begin() {
		if (root != nullptr) {
			//the leftest of toReturn
			TreeNode<T>* toReturn = root.get(); //??? separate task
			while (toReturn->leftChild != nullptr) {
				toReturn = toReturn->leftChild.get();
			}
			return TreeNodeIterator<T>(toReturn);
		}
		return TreeNodeIterator<T>(nullptr);
	}

	TreeNodeIterator<T> end() {
		return TreeNodeIterator<T>(nullptr);
	}


	int maxDepth() const {
		return root->maxDepth();
	}
};


#endif

