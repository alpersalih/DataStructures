
/** 
* @file stacknode.cpp
* @description Stack elemanlari
* @course 2.Ogretim B grubu
* @assignment 2. Odev
* @date 12/22/2023
* @author Alper Salih Aktaş
*/

#include "../include/stacknode.hpp"

Stacknode::Stacknode(int newKey)
{
    this->key = newKey;
    this->next = NULL;
}