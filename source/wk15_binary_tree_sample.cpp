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

    // search for a value
    while (true)
    {
        std::cout << "\nValue to search for (0 quits)? ";

        int value;
        std::cin >> value;

        if (!value)
            break;

        if (tree.rSearchNode(value))
            std::cout << "Found " << value << " in the tree.\n";
        else
            std::cout << "Did not find " << value << " in the tree.\n";
    }

    return 0;
}

//------------------------------------------------------------------------------
// recursive search for value in tree
//------------------------------------------------------------------------------
bool rSearchValue(int value, TreeNode* pTree)
{
    if (pTree->data == value)
        return true;

    if (value < pTree->data)
    {
        if (!pTree->pLeft)
            return false;

        return rSearchValue(value, pTree->pLeft);
    }
    else
    {
        if (!pTree->pRight)
            return false;

        return rSearchValue(value, pTree->pRight);
    }
}
