// CountNodes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BFSBinaryTree.h"



void CreateBST()
{
   
    auto bfsTree = new BFSBinaryTree();
    auto root = bfsTree->InsertNode(nullptr, 5);
    bfsTree->InsertNode(root, 2);
    bfsTree->InsertNode(root, 7);
    bfsTree->InsertNode(root, 6);
    bfsTree->InsertNode(root, 9);
    bfsTree->InsertNode(root, 8);

}


int _tmain(int argc, _TCHAR* argv[])
{
    return 0;
}

