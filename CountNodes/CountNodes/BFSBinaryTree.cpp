
#include "stdafx.h"
#include "BFSBinaryTree.h"
#include <queue>
#include <iostream>
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

void BFSBinaryTree::CountJumps(int start, int end)
{
    if (start == end || end == -1)
    {
        cout << endl;
    }
    else
    {
        CountJumps(start, parent[end]);
        cout << " " << end;
    }
}

void BFSBinaryTree::BFSearch(int x)
{
    auto start = nodes[x];

    auto q = new queue<TreeNode*>();
    q->push(start->left);
    q->push(start->parent);
    q->push(start->right);
    discovered[x] = true;
    if (start->left != nullptr)
    {
        parent[start->left->data] = start->data;
        discovered[start->left->data] = true;
    }
    if (start->right != nullptr)
    {
        parent[start->right->data] = start->data;
        discovered[start->right->data] = true;
    }
    if (start->parent != nullptr)
    {
        parent[start->parent->data] = start->data;
        discovered[start->parent->data] = true;
    }

    TreeNode * p;
    
    while (!q->empty())
    {
        p = q->front();
        q->pop();

        if (p != nullptr)
        {
            processed[p->data] = true;
            auto l = p->left;
            if (l != nullptr)
            {  
                if (!discovered[l->data])
                {
                    q->push(l);
                    discovered[l->data] = true;
                    parent[l->data] = p->data;
                }
            }
           
            auto dad = p->parent;
            if (dad != nullptr)
            {
                if (!discovered[dad->data])
                {
                    q->push(dad);
                    discovered[dad->data] = true;
                    parent[dad->data] = p->data;
                }
            }

            auto r = p->right;
            if (r != nullptr)
            {
                if (!discovered[r->data])
                {
                    q->push(r);
                    discovered[r->data] = true;
                    parent[r->data] = p->data;
                }
            }
        }
        
        
    }


}

