//------------------------------------------------------------------------------
// IntBinaryTree.h : class declaration
// 
// Author: Gaddis 9E Ch.21
// Modified by: Prof. Linda C
//------------------------------------------------------------------------------
#pragma once

//------------------------------------------------------------------------------
// IntBinaryTree
//------------------------------------------------------------------------------
class IntBinaryTree
{
private:
    struct TreeNode
    {
        int data;           // The value in the node
        TreeNode* pLeft;    // Pointer to left child node
        TreeNode* pRight;   // Pointer to right child node
    };

    TreeNode* pRoot;        // Pointer to the root node

    // Private member functions
    void _rInsert(TreeNode*& pNode, TreeNode*& pNewNode);
    void _destroySubTree(TreeNode* pNode);
    void _deleteNode(int value, TreeNode*& pNode);
    void _makeDeletion(TreeNode*& pNode);
    void _displayInOrder(TreeNode* pNode) const;
    void _displayPreOrder(TreeNode* pNode) const;
    void _displayPostOrder(TreeNode* pNode) const;

public:
    // constructor
    IntBinaryTree();

    // destructor
    ~IntBinaryTree();

    // binary tree operations
    void insertNode(int value);
    bool searchNode(int value);
    void remove(int value);

    // display in inorder, preorder and postorder
    void displayInOrder() const;
    void displayPreOrder() const;
    void displayPostOrder() const;
};
