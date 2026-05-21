//------------------------------------------------------------------------------
// IntBinaryTree.h : class declaration
// 
// Author: Gaddis 9E Ch.21
// Modified by: Prof. Linda C
//------------------------------------------------------------------------------
#pragma once

//------------------------------------------------------------------------------
// TreeNode structure: defines the nodes in a binary tree
//------------------------------------------------------------------------------
struct TreeNode
{
    int data;           // The value in the node
    TreeNode* pLeft;    // Pointer to left child node
    TreeNode* pRight;   // Pointer to right child node

    TreeNode() : data(0), pLeft(nullptr), pRight(nullptr) { }
};

//------------------------------------------------------------------------------
// IntBinaryTree
//------------------------------------------------------------------------------
class IntBinaryTree
{
private:
    TreeNode* pRoot;        // Pointer to the root node

public:
    // constructor
    IntBinaryTree();

    // destructor
    ~IntBinaryTree();

    // binary tree operations
    void insertNode(int value);
    // iterative search
    bool searchNode(int value);
    // recursive search
    bool rSearchNode(int value);

    void remove(int value);

    // display node values in inorder, preorder and postorder
    void displayInOrder() const;
    void displayPreOrder() const;
    void displayPostOrder() const;

private:
    void _rInsert(TreeNode*& pNode, TreeNode*& pNewNode);
    void _destroySubTree(TreeNode* pNode);
    void _deleteNode(int value, TreeNode*& pNode);
    void _makeDeletion(TreeNode*& pNode);
    void _displayInOrder(TreeNode* pNode) const;
    void _displayPreOrder(TreeNode* pNode) const;
    void _displayPostOrder(TreeNode* pNode) const;

    bool _rSearchNode(int value, TreeNode* pRoot);
};
