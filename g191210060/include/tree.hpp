#ifndef tree_hpp
#define tree_hpp
#include "node.hpp"
#include "stack.hpp"

class Tree {
public:
    Stack* stack;
    char ascii;
    Tree* nextTree;
    Tree* prewTree;
    Tree(int count);
    int height(Node* node);
    int balanceFactor(Node* node);
    void updateHeight(Node* node);
    Node* rotateRight(Node* y);
    Node* rotateLeft(Node* x);
    Node* insert(Node* node, int key);
    void insert(int key);
    void deleteFromStack();
    bool isStackEmpty();
    char setAsciiChar();
    int GetNonLeafValue(Node* node);
    void setStack();
    int returnTreeCount();
    ~Tree();
private:
    int AvlCount;
    Node* root;
    void deleteTree(Node* TMP);
    void getLeafNodesToStack(Node* node);
};

#endif