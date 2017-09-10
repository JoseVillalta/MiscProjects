
#include "stdafx.h"
#include "BFSBinaryTree.h"
#include <queue>
using namespace std;

BFSBinaryTree::BFSBinaryTree()
{
    for (int i = 0; i < MAXV; i++)
    {
        nodes[i] = nullptr;
    }
}


TreeNode* BFSBinaryTree::InsertNode(TreeNode* root, int val)
{

    if (root == nullptr)
    {
        root = new TreeNode(val);
        nodes[val] = root;
        return root;
    }
    else if (root->data < val)
    {
        if (root->right == nullptr)
        {
            auto node = new TreeNode(val);
            nodes[val] = node;
            root->right = node;
            node->parent = root;
            return node;
        }
        else
        {
            return InsertNode(root->right, val);
        }        
    }
    else
    {
        if (root->left == nullptr)
        {
            auto node = new TreeNode(val);
            nodes[val] = node;
            root->left = node;
            node->parent = root;
            return node;
        }
        else
        {
            return InsertNode(root->left, val);
        }
       
    }
}

void BFSBinaryTree::InitSearch()
{
    for (int i = 0; i < MAXV; i++)
    {
        processed[i] = false;
        discovered[i] = false;
        parent[i] = -1;
    }
}

int BFSBinaryTree::CountJumps(int x, int y)
{
    
}

int BFSBinaryTree::CountNodes(int x, int y)
{
    auto start = nodes[x];

    auto q = new queue<TreeNode*>();
    q->push(start->left);
    q->push(start->parent);
    q->push(start->right);
    discovered[x] = true;
    processed[x] = true;

    if (start->left != nullptr)
    {
        parent[start->left->data] = start->data;
    }

    while (!q->empty())
    {
        auto v = q->front();
        q->pop();

        if (v != nullptr)
        {
            processed[v->data];
        }
        
        
    }


}

