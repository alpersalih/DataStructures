#ifndef stack_hpp
#define stack_hpp
#include "stacknode.hpp"
class Stack
{
    public:
    Stack();
    void Insert(int key);
    void PrintElements();
    Stacknode* getBottomNode();
    void DeleteTop();
    int getTopKey();
    ~Stack();
    private:
    Stacknode* bottom;
};

#endif