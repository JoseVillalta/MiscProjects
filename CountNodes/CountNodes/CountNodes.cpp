// CountNodes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BFSBinaryTree.h"
#include <ostream>
#include <iostream>

using namespace std;
void CreateBST()
{
   
    auto bfsTree = new BFSBinaryTree();
    auto root = bfsTree->InsertNode(nullptr, 5);
    bfsTree->InsertNode(root, 2);
    bfsTree->InsertNode(root, 7);
    bfsTree->InsertNode(root, 6);
    bfsTree->InsertNode(root, 9);
    bfsTree->InsertNode(root, 8);
    cout << "*** Path 6 to 8 ***" << endl;
    bfsTree->InitSearch();
    bfsTree->BFSearch(6);
    bfsTree->CountJumps(6,8);
    std::cout << std::endl;
    cout << "*** Path 2 to 6 ***" << endl;
    bfsTree->InitSearch();
    bfsTree->BFSearch(2);
    bfsTree->CountJumps(2, 6);
    cout << endl;
    cout << "*** Path 2 to 8 ***" << endl;
    bfsTree->InitSearch();
    bfsTree->BFSearch(2);
    bfsTree->CountJumps(2, 8);
    cout << endl;
}


int _tmain(int argc, _TCHAR* argv[])
{
    CreateBST();
    return 0;
}

