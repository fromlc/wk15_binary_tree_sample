//------------------------------------------------------------------------------
// Implementation file for the IntBinaryTree class
// 
// Author: Gaddis 9E Ch.21
//------------------------------------------------------------------------------
#include "IntBinaryTree.h"

#include <iostream>
using std::cout;

//------------------------------------------------------------------------------
// - accepts a TreeNode pointer and a pointer to a node.
// - inserts the node into the tree pointed to by the TreeNode pointer.
// 
// This function is called recursively.
//------------------------------------------------------------------------------
void IntBinaryTree::insert(TreeNode*& nodePtr, TreeNode*& newNode) {

	if (nodePtr == nullptr)
		nodePtr = newNode;                  // Insert the node.

	else if (newNode->data < nodePtr->data)
		insert(nodePtr->left, newNode);     // Search the left branch

	else
		insert(nodePtr->right, newNode);    // Search the right branch
}

//------------------------------------------------------------------------------
// - creates a new node to hold num as its value,
// - passes this new node to the insert function.
//------------------------------------------------------------------------------
void IntBinaryTree::insertNode(int num) {
	TreeNode* newNode = nullptr;	// Pointer to a new node.

	// Create a new node and store num in it.
	newNode = new TreeNode;
	newNode->data = num;
	newNode->left = newNode->right = nullptr;

	// Insert the node.
	insert(root, newNode);
}

//------------------------------------------------------------------------------
// - called by the destructor
// - deletes all nodes in the tree
//------------------------------------------------------------------------------
void IntBinaryTree::destroySubTree(TreeNode* nodePtr) {

	if (nodePtr) {

		if (nodePtr->left)
			destroySubTree(nodePtr->left);

		if (nodePtr->right)
			destroySubTree(nodePtr->right);

		delete nodePtr;
	}
}

//------------------------------------------------------------------------------
// - determines if the passed value num is present in the tree
// - returns true if found, false otherwise
//------------------------------------------------------------------------------
bool IntBinaryTree::searchNode(int num) {

	TreeNode* nodePtr = root;

	while (nodePtr) {

		if (nodePtr->data == num)
			return true;

		if (num < nodePtr->data)
			nodePtr = nodePtr->left;
		else
			nodePtr = nodePtr->right;
	}

	return false;
}

//------------------------------------------------------------------------------
// - calls deleteNode to delete the node with value equal to num
//------------------------------------------------------------------------------
void IntBinaryTree::remove(int num) {
	deleteNode(num, root);
}

//------------------------------------------------------------------------------
// - deletes the node with value equal to num
//------------------------------------------------------------------------------
void IntBinaryTree::deleteNode(int num, TreeNode*& nodePtr) {

	if (num < nodePtr->data)
		deleteNode(num, nodePtr->left);

	else if (num > nodePtr->data)
		deleteNode(num, nodePtr->right);

	else
		makeDeletion(nodePtr);
}

//------------------------------------------------------------------------------
// - accepts a reference to a pointer to the node that will be deleted
// - removes the node
// - reattaches the branches of the tree below the deleted node
//------------------------------------------------------------------------------
void IntBinaryTree::makeDeletion(TreeNode*& nodePtr) {

	// Define a temporary pointer to use in reattaching
	// the left subtree.
	TreeNode* tempNodePtr = nullptr;

	if (nodePtr == nullptr)
		cout << "Cannot delete empty node.\n";

	else if (nodePtr->right == nullptr) {
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->left;   // Reattach the left child
		delete tempNodePtr;
	}

	else if (nodePtr->left == nullptr) {
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right;  // Reattach the right child
		delete tempNodePtr;
	}

	// If the node has two children.
	else {
		// Move one node the right.
		tempNodePtr = nodePtr->right;

		// Go to the end left node.
		while (tempNodePtr->left) {
			tempNodePtr = tempNodePtr->left;
		}

		// Reattach the left subtree.
		tempNodePtr->left = nodePtr->left;
		tempNodePtr = nodePtr;

		// Reattach the right subtree.
		nodePtr = nodePtr->right;
		delete tempNodePtr;
	}
}

//------------------------------------------------------------------------------
// - displays node values in the subtree pointed to by nodePtr
// - via inorder traversal
//------------------------------------------------------------------------------
void IntBinaryTree::displayInOrder(TreeNode* nodePtr) const {

	if (nodePtr) {
		displayInOrder(nodePtr->left);
		cout << nodePtr->data << '\n';
		displayInOrder(nodePtr->right);
	}
}

//------------------------------------------------------------------------------
// - displays node values in the subtree pointed to by nodePtr
// - via preorder traversal
//------------------------------------------------------------------------------
void IntBinaryTree::displayPreOrder(TreeNode* nodePtr) const {

	if (nodePtr) {
		cout << nodePtr->data << '\n';
		displayPreOrder(nodePtr->left);
		displayPreOrder(nodePtr->right);
	}
}

//------------------------------------------------------------------------------
// - displays node values in the subtree pointed to by nodePtr
// - via postorder traversal
//------------------------------------------------------------------------------
void IntBinaryTree::displayPostOrder(TreeNode* nodePtr) const {

	if (nodePtr) {
		displayPostOrder(nodePtr->left);
		displayPostOrder(nodePtr->right);
		cout << nodePtr->data << '\n';
	}
}