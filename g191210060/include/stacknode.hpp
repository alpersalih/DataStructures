#ifndef stacknode_hpp
#define stacknode_hpp
#include <iostream>
class Stacknode
{
    public:
    int key;
    Stacknode* next;
    Stacknode(int newKey);
};

#endif