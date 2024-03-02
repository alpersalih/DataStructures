
/** 
* @file node.cpp
* @description Agac elemanlari.
* @course 2.Ogretim B grubu
* @assignment 2. Odev
* @date 12/22/2023
* @author Alper Salih Aktaş
*/

#include "../include/Node.hpp"

Node::Node(int newKey)
{
    this->key = newKey;
    this->left = NULL;
    this-> right = NULL;
    this->height = 1;
}
int Node::Key()
{
    return this->key;
}