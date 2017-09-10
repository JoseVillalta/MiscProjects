#include "Nodes.h"
#define MAXV 100

class BFSBinaryTree
{
public:
    TreeNode * nodes[MAXV + 1];
    int nvertices;
    int nedges;
    bool discovered[MAXV + 1];
    bool processed[MAXV + 1];
    int parent[MAXV + 1];

    TreeNode * InsertNode(TreeNode * root, int val);
    int CountNodes(int x, int y);
    BFSBinaryTree();
private:
    void InitSearch();
    int CountJumps(int x, int y);
    
};