
/** 
* @file treeparent.cpp
* @description Treeparent agaclari tutan class. Bizden istenilen cozumun de gerceklendigi class. Agaclarin silinmesi, stacklerin doluluk kontrolu
* vs. burada kontrol ediliyor. "solution" fonksiyonunda da "isMin" degerine bagli olarak bir en kucuk bir en buyuk deger stacklerden ayrilarak
* fonksiyon sonda kalan agaci buluyor.
* @course 2.Ogretim B grubu
* @assignment 2. Odev
* @date 12/22/2023
* @author Alper Salih Aktaş
*/

#include "../include/treeparent.hpp"
#define MAXINT 2147483647;
#define MININT (-2147483647 - 1);

TreeParent::TreeParent()
{
    headTree = NULL;
    isMin = true;
}
void TreeParent::InsertTree(Tree* newTree)
{
    if(headTree == NULL)
    {
        headTree = newTree;
        return;
    }
    Tree* tmp = headTree;
    while(tmp->nextTree != NULL)
        tmp = tmp->nextTree;
    tmp->nextTree = newTree;
    newTree->prewTree = tmp;
}
void TreeParent::deleteTree(Tree* deleteTree)
{
    Tree* beforeTmp = deleteTree->prewTree;
    Tree* afterTmp = deleteTree->nextTree;
    if(beforeTmp == NULL && afterTmp == NULL)
    {
        Tree* tmp = deleteTree;
        delete deleteTree;
        headTree = NULL;
    }
    if(beforeTmp != NULL)
        beforeTmp->nextTree = afterTmp;
    else
        headTree = headTree->nextTree;
    if(afterTmp != NULL)
        afterTmp->prewTree = beforeTmp;
    delete deleteTree;
}
void TreeParent::solution()
{
    while(countTrees() > 1)
    {
        if(isMin == true)
        {
            int tmpMaxInt = MAXINT;
            Tree* tmp = headTree;
            Tree* willRemove;
            while(tmp != NULL)
            {
                if(tmpMaxInt > tmp->stack->getTopKey())
                {
                    tmpMaxInt = tmp->stack->getTopKey();
                    willRemove = tmp;
                }
                tmp = tmp->nextTree;
            }
            willRemove->deleteFromStack();
            isMin = false;
            if(willRemove->isStackEmpty())
            { 
                Tree* tmp = headTree;
                while(tmp != NULL)
                {
                    std::cout << tmp->ascii;
                    tmp = tmp->nextTree;
                }
                deleteTree(willRemove);
                returnToOrigin();
                isMin = true;
                system("cls");
            }
        }
        else if(isMin == false)
        {
            
            int tmpMinInt = MININT;
            Tree* tmp = headTree;
            Tree* willRemove;
            while(tmp != NULL)
            {
                if(tmpMinInt < tmp->stack->getTopKey())
                {
                    tmpMinInt = tmp->stack->getTopKey();
                    willRemove = tmp;
                }
                tmp = tmp->nextTree;
            }
            willRemove->deleteFromStack();
            if(willRemove->isStackEmpty())
            {
                Tree* tmp = headTree;
                while(tmp != NULL)
                {
                    std::cout << tmp->ascii;
                    tmp = tmp->nextTree;
                }
                deleteTree(willRemove);
                returnToOrigin();
                isMin = true;
                system("cls");
            }
            isMin = true;
        }
        
    }
    std::cout << "The last avl tree is  :" << headTree->returnTreeCount() << "\n";
    std::cout << "The ascii character is:" << headTree->ascii << "\n";
}
void TreeParent::returnToOrigin()
{
    Tree* tmp = headTree;
    while(tmp != NULL)
    {
        delete tmp->stack ;
        tmp->stack = new Stack();
        tmp->setStack();
        tmp = tmp->nextTree;
    }
}
int TreeParent::countTrees()
{
    int count = 0;
    Tree* tmp = headTree;
    while(tmp != NULL)
    {
        tmp = tmp->nextTree;
        count++;
    }
    return count;
}
TreeParent::~TreeParent()
{
    Tree* tmpTree = headTree;
    while(tmpTree != NULL)
    {
        Tree* del = tmpTree;
        tmpTree = tmpTree->nextTree;
        delete del;
    }
}