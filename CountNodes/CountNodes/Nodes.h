#pragma once

class TreeNode
{
public:
    int data;
    TreeNode * parent;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int val = 0)
    {
        data = val;
        parent = nullptr;
        left = nullptr;
        right = nullptr;
    }
};