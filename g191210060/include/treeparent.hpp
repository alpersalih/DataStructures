#ifndef stackparent_hpp
#define stackparent_hpp
#include "tree.hpp"
#include "Windows.h"

class TreeParent
{
    public:
    TreeParent();
    void InsertTree(Tree* newTree);
    void deleteTree(Tree* deleteTree);
    void solution();
    void returnToOrigin();
    int countTrees();
    ~TreeParent();
    private:
    bool isMin;
    Tree* headTree;
};

#endif