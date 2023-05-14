//------------------------------------------------------------------------------
// wk15_binary_tree_sample.cpp
// 
//		- builds a binary tree with int node values
//		- demos traversal inorder, preorder, and postorder traversal
// 
// Author: Gaddis 9E Pr21-1, Pr21-2
//------------------------------------------------------------------------------
#include "IntBinaryTree.h"

#include <iostream>
using std::cout;

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {
	//int nodeValues[] = { 4, 2, 6 };
	int nodeValues[] = { 4, 2, 6, 5 };

	IntBinaryTree tree;

	for (int data : nodeValues) {
		cout << "Inserting node with data " << data << '\n';
		tree.insertNode(data);
	}

	// Display inorder.
	cout << "\nInorder traversal:\n";
	tree.displayInOrder();

	// Display preorder.
	cout << "\nPreorder traversal:\n";
	tree.displayPreOrder();

	// Display postorder.
	cout << "\nPostorder traversal:\n";
	tree.displayPostOrder();

	return 0;
}