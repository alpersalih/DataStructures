
/** 
* @file stack.cpp
* @description Stack classi. Bagli lise seklinde tutuluyor. 
* @course 2.Ogretim B grubu
* @assignment 2. Odev
* @date 12/22/2023
* @author Alper Salih Aktaş
*/

#include "../include/stack.hpp"

Stack::Stack()
{
    this->bottom = NULL;
}
void Stack::Insert(int key)
{
    Stacknode* newStacknode = new Stacknode(key);
    if(bottom == NULL)
    {
        bottom = newStacknode;
        return;
    }
    Stacknode* tmp = bottom;
    while(tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = newStacknode;
}
void Stack::PrintElements()
{
    if(bottom == NULL)
        return;
    Stacknode* tmp = bottom;
    while(tmp != NULL)
    {
        std::cout << tmp->key << "\n";
        tmp = tmp->next;
    }
}
Stacknode* Stack::getBottomNode()
{
    return this->bottom;
}
void Stack::DeleteTop()
{
    if(bottom == NULL)
        return;
    Stacknode* tmp = bottom;
    //Getting error down here
    if(tmp->next == NULL)
    {
        bottom = NULL;
        delete(tmp);
        return;
    }
    while(tmp->next->next != NULL)
        tmp = tmp->next;
    tmp->next = NULL;
    delete(tmp->next);
}
//If returns negative number, it means that the stack is empty.
int Stack::getTopKey()
{
    if(bottom == NULL)
        return -1;
    Stacknode* tmp = bottom;
    while(tmp->next != NULL)
        tmp = tmp->next;
    return tmp->key;
}
Stack::~Stack()
{
    Stacknode* tmp = this->bottom;
    while(tmp != NULL)
    {
        Stacknode* del = tmp;
        tmp = tmp->next;
        delete del;
    }
}