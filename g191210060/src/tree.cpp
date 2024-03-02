
/** 
* @file tree.cpp
* @description Dengeli agac classi. Eleman eklerken surekli dengeli kalmasi icin dondurme islemi yapiliyor. Her bir agac icinde stack de 
* tutuluyor. Stack icinde sadece agacin yapraklari tutuluyor.
* @course 2.Ogretim B grubu
* @assignment 2. Odev
* @date 12/22/2023
* @author Alper Salih Aktaş
*/

#include "../include/tree.hpp"

Tree::Tree(int count) 
{
    root = NULL;
    nextTree = NULL;
    prewTree = NULL;
    AvlCount = count;
    stack = new Stack();
}
int Tree::height(Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int Tree::balanceFactor(Node* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

void Tree::updateHeight(Node* node) {
    if (node != NULL) {
        node->height = 1 + std::max(height(node->left), height(node->right));
    }
}

Node* Tree::rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

Node* Tree::rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

Node* Tree::insert(Node* node, int key) {
    if (node == NULL)
        return new Node(key);

    if (key < node->Key())
        node->left = insert(node->left, key);
    else if (key > node->Key())
        node->right = insert(node->right, key);
    else
        return node; // Duplicate keys are not allowed

    // Update height of the current node
    updateHeight(node);

    // Perform rotation to maintain AVL property
    int balance = balanceFactor(node);

    // Left Heavy
    if (balance > 1) {
        if (key < node->left->Key()) {
            // Left-Left case
            return rotateRight(node);
        } else {
            // Left-Right case
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
    }

    // Right Heavy
    if (balance < -1) {
        if (key > node->right->Key()) {
            // Right-Right case
            return rotateLeft(node);
        } else {
            // Right-Left case
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
    }

    return node;
}
void Tree::getLeafNodesToStack(Node* node)
{
    if (node != NULL) {
        getLeafNodesToStack(node->left);
        getLeafNodesToStack(node->right);
        if(node->left == NULL && node->right == NULL)
        {
            stack->Insert(node->Key());
        }
    }
}

void Tree::insert(int key) {
    root = insert(root, key);
}
void Tree::deleteFromStack()
{
    this->stack->DeleteTop();
}
bool Tree::isStackEmpty()
{
    return (this->stack->getBottomNode() == NULL ? true : false);
}
char Tree::setAsciiChar()
{
    ascii = char((GetNonLeafValue(root) % 26) + 65);
}
int Tree::returnTreeCount()
{
    return this->AvlCount;
}
int Tree::GetNonLeafValue(Node* node)
{
    if (node == nullptr) {
        return 0;
    }
    if(node->left == NULL && node->right == NULL)
        return 0;

    // Recursively calculate the sum of left and right subtrees
    int leftSum = GetNonLeafValue(node->left);
    int rightSum = GetNonLeafValue(node->right);

    // Add the current node's value to the sum
    return node->Key() + leftSum + rightSum;
}
void Tree::deleteTree(Node* node)
{
    if(node->left != NULL)
        deleteTree(node->left);

    if(node->right != NULL)
        deleteTree(node->right);
    delete node;
}

void Tree::setStack()
{
    this->getLeafNodesToStack(this->root);
}
Tree::~Tree()
{
    delete stack;
    this->deleteTree(this->root);
}