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

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main()
{
    //int nodeValues[] = { 4, 2, 6 };
    int nodeValues[] = { 4, 2, 6, 5 };

    IntBinaryTree tree;

    for (int data : nodeValues)
    {
        std::cout << "Inserting node with data " << data << '\n';
        tree.insertNode(data);
    }

    // Display inorder.
    std::cout << "\nInorder traversal:\n";
    tree.displayInOrder();

    // Display preorder.
    std::cout << "\nPreorder traversal:\n";
    tree.displayPreOrder();

    // Display postorder.
    std::cout << "\nPostorder traversal:\n";
    tree.displayPostOrder();

    return 0;
}