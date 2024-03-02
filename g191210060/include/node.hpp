#ifndef Node_hpp
#define Node_hpp

#include <iostream>
class Node
{
    public: 
    Node* left;
    Node* right;
    int height;
    Node(int newKey);
    int Key();
    private:
    int key;
};

#endif