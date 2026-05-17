//------------------------------------------------------------------------------
// IntBinaryTree.cpp: class definition
// 
// Author: Gaddis 9E Ch.21
// Modified by: Prof. Linda C
//------------------------------------------------------------------------------
#include "IntBinaryTree.h"

#include <iostream>

// constructor
IntBinaryTree::IntBinaryTree() : pRoot(nullptr) { }

// destructor
IntBinaryTree::~IntBinaryTree() { _destroySubTree(pRoot); }

//------------------------------------------------------------------------------
// - accepts a TreeNode pointer and a pointer to a node.
// - inserts the node into the tree pointed to by the TreeNode pointer.
// 
// This function is called recursively.
//------------------------------------------------------------------------------
void IntBinaryTree::_rInsert(TreeNode*& pNode, TreeNode*& pNewNode)
{
    if (!pNode)
        pNode = pNewNode;                  // Insert the node.

    else if (pNewNode->data < pNode->data)
        _rInsert(pNode->pLeft, pNewNode);     // Search the left branch

    else
        _rInsert(pNode->pRight, pNewNode);    // Search the right branch
}

//------------------------------------------------------------------------------
// - creates a new node to hold passed value,
// - passes this new node to the insert function.
//------------------------------------------------------------------------------
void IntBinaryTree::insertNode(int value)
{
    TreeNode* pNewNode = nullptr;	// Pointer to a new node.

    // Create a new node and store num in it.
    pNewNode = new TreeNode;
    pNewNode->data = value;
    pNewNode->pLeft = pNewNode->pRight = nullptr;

    // Insert the node.
    _rInsert(pRoot, pNewNode);
}

//------------------------------------------------------------------------------
// - called by the destructor
// - deletes all nodes in the tree
//------------------------------------------------------------------------------
void IntBinaryTree::_destroySubTree(TreeNode* pNode)
{
    if (pNode)
    {

        if (pNode->pLeft)
            _destroySubTree(pNode->pLeft);

        if (pNode->pRight)
            _destroySubTree(pNode->pRight);

        delete pNode;
    }
}

//------------------------------------------------------------------------------
// - determines if the passed data value is present in the tree
// - returns true if found, false otherwise
//------------------------------------------------------------------------------
bool IntBinaryTree::searchNode(int value)
{
    TreeNode* pNode = pRoot;

    while (pNode)
    {
        if (pNode->data == value)
            return true;

        if (value < pNode->data)
            pNode = pNode->pLeft;
        else
            pNode = pNode->pRight;
    }

    return false;
}

//------------------------------------------------------------------------------
// calls deleteNode to delete the node with passed data value
//------------------------------------------------------------------------------
void IntBinaryTree::remove(int value) { _deleteNode(value, pRoot); }

//------------------------------------------------------------------------------
// displays nodes in inorder
//------------------------------------------------------------------------------
void IntBinaryTree::displayInOrder() const { _displayInOrder(pRoot); }

//------------------------------------------------------------------------------
// displays nodes in preorder
//------------------------------------------------------------------------------
void IntBinaryTree::displayPreOrder() const { _displayPreOrder(pRoot); }

//------------------------------------------------------------------------------
// displays nodes in postorder
//------------------------------------------------------------------------------
void IntBinaryTree::displayPostOrder() const { _displayPostOrder(pRoot); }

//------------------------------------------------------------------------------
// - deletes the node with passed data value
//------------------------------------------------------------------------------
void IntBinaryTree::_deleteNode(int value, TreeNode*& pNode)
{
    if (value < pNode->data)
        _deleteNode(value, pNode->pLeft);

    else if (value > pNode->data)
        _deleteNode(value, pNode->pRight);

    else
        _makeDeletion(pNode);
}

//------------------------------------------------------------------------------
// - accepts a reference to a pointer to the node that will be deleted
// - removes the node
// - reattaches the branches of the tree below the deleted node
//------------------------------------------------------------------------------
void IntBinaryTree::_makeDeletion(TreeNode*& pNode)
{
    // Define a temporary pointer to use in reattaching
    // the left subtree.
    TreeNode* pTemp = nullptr;

    if (!pNode)
        std::cout << "Cannot delete empty node.\n";

    else if (!pNode->pRight)
    {
        pTemp = pNode;
        pNode = pNode->pLeft;   // Reattach the left child
        delete pTemp;
    }

    else if (!pNode->pLeft)
    {
        pTemp = pNode;
        pNode = pNode->pRight;  // Reattach the right child
        delete pTemp;
    }

    // If the node has two children.
    else
    {
        // Move one node the right.
        pTemp = pNode->pRight;

        // Go to the end left node.
        while (pTemp->pLeft)
            pTemp = pTemp->pLeft;

        // Reattach the left subtree.
        pTemp->pLeft = pNode->pLeft;
        pTemp = pNode;

        // Reattach the right subtree.
        pNode = pNode->pRight;
        delete pTemp;
    }
}

//------------------------------------------------------------------------------
// - displays node values in the subtree pointed to by pNode
// - via inorder traversal
//------------------------------------------------------------------------------
void IntBinaryTree::_displayInOrder(TreeNode* pNode) const
{
    if (pNode)
    {
        _displayInOrder(pNode->pLeft);

        std::cout << pNode->data << '\n';

        _displayInOrder(pNode->pRight);
    }
}

//------------------------------------------------------------------------------
// - displays node values in the subtree pointed to by pNode
// - via preorder traversal
//------------------------------------------------------------------------------
void IntBinaryTree::_displayPreOrder(TreeNode* pNode) const
{
    if (pNode)
    {
        std::cout << pNode->data << '\n';

        _displayPreOrder(pNode->pLeft);
        _displayPreOrder(pNode->pRight);
    }
}

//------------------------------------------------------------------------------
// - displays node values in the subtree pointed to by pNode
// - via postorder traversal
//------------------------------------------------------------------------------
void IntBinaryTree::_displayPostOrder(TreeNode* pNode) const
{
    if (pNode)
    {
        _displayPostOrder(pNode->pLeft);
        _displayPostOrder(pNode->pRight);

        std::cout << pNode->data << '\n';
    }
}