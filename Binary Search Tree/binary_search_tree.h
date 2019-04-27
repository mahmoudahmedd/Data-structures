/**
 *  @file    binary_search_tree.h
 *  @author  Mahmoud Ahmed Tawfik (@mahmoudahmedd)
 *  @date    27/04/2019
 *  @version 1.0
 */
#pragma once

#ifndef BINARYSEARCHTREE_H_INCLUDED
#define BINARYSEARCHTREE_H_INCLUDED

#include <iostream>

using namespace std;

enum Type {PREORDER, INORDER, POSTORDER};

template <class T>
class BinarySearchTree
{
private:
    struct Node
    {
        T data;
        Node *leftChild;
        Node *rightChild;

        Node()
        {
            leftChild = rightChild = NULL;
        }

        Node(T _value)
        {
            data = _value;
            leftChild = rightChild = NULL;
        }
    };

    Node *root;
    int count;       // Current size of the BinarySearchTree

public:
    // Constructors
    BinarySearchTree();
    BinarySearchTree(T, int);

    // Operations
    bool find(T);
    int  getHeight(Node*);
    Node *getParent(T);
    Node *getRoot();

    // Unformatted output
    void print(Type, Node*);
    void printLevelOrder(Node*);
    void printInRange(T, T, Node*);
    void printGivenLevel(Node*, int);

    // Modifiers
    void insert(T);
    void remove();
    void destroy(Node*);

    // Min/max
    T max();
    T min();

    // Capacity
    int size();
    bool empty();

    // Destructor
    ~BinarySearchTree();
};

/**
 * Default constructor
 */
template <class T>
BinarySearchTree<T>::BinarySearchTree()
{
    this->root = NULL;
    this->count = 0;
}

/**
 * Constructs a BinarySearchTree having ‘_intialSize’ elements whose values are ‘_value’
 */
template <class T>
BinarySearchTree<T>::BinarySearchTree(T _value, int _intialSize)
{
    this->root = NULL;
    this->count = 0;

    for(int i = 0; i < _intialSize; i++)
        this->insert(_value);
}

/**
 * Constructs a BinarySearchTree having ‘_intialSize’ elements whose values are ‘_value’
 * @return bool
 */
template <class T>
bool BinarySearchTree<T>::find(T _value)
{
    Node *r = root;

    while(r != NULL && r->data != _value)
    {
        if(_value < r->data)
            r = r->leftChild;
        else
            r = r->rightChild;
    }

    return (r != NULL);
}

/**
 * ---------------------------------------------------------
 * @param  Node
 * @return int
 */
template <class T>
int BinarySearchTree<T>::getHeight(Node* node)
{
    if (node == NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = getHeight(node->leftChild);
        int rheight = getHeight(node->rightChild);

        /* use the larger one */
        if (lheight > rheight)
            return(lheight + 1);
        else
            return(rheight + 1);
    }
}

/**
 * Returns the largest value in the BinarySearchTree
 * @return T
 */
template <class T>
T BinarySearchTree<T>::max()
{
    Node *cur = root;
    Node *parent = NULL;

    while (cur != NULL)
    {
        parent = cur;
        cur = cur->rightChild;
    }

    if(parent != NULL)
    {
        return parent->data;
    }
    else
    {
        cerr << "BinarySearchTree::max() - Out Of Range."  << endl;
        exit(EXIT_FAILURE); // Exit the program
    }
}

/**
 * Returns the smallest value in the BinarySearchTree
 * @return T
 */
template <class T>
T BinarySearchTree<T>::min()
{
    Node *cur = root;
    Node *parent = NULL;

    while (cur != NULL)
    {
        parent = cur;
        cur = cur->leftChild;
    }

    if(parent != NULL)
    {
        return parent->data;
    }
    else
    {
        cerr << "BinarySearchTree::min() - Out Of Range."  << endl;
        exit(EXIT_FAILURE); // Exit the program
    }
}

/**
 * Insert element
 */
template <class T>
void BinarySearchTree<T>::insert(T _value)
{
    Node *tmp = root;

    while (tmp != NULL && tmp->data != _value)
    {
        if (_value < tmp->data)
            tmp = tmp->leftChild;
        else
            tmp = tmp->rightChild;
    }


    if (tmp != NULL)
        return;

    Node *inserted = new Node(_value);
    Node *parent = getParent(_value);

    if (parent == NULL)
    {
        root = inserted;
        this->count++;
        return;
    }

    if (_value < parent->data)
    {
        parent->leftChild = inserted;
        this->count++;
    }
    else if (_value > parent->data)
    {
        parent->rightChild = inserted;
        this->count++;
    }

}

/**
 * Get parent
 */
template <class T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::getParent(T _value)
{
    Node *cur = root;
    Node *parent = NULL;

    while (cur != NULL && cur->data != _value)
    {
        parent = cur;

        if (_value < cur->data)
            cur = cur->leftChild;
        else
            cur = cur->rightChild;
    }

    return parent;
}

/**
 * Prints the BinarySearchTree values on the screen
 * @param Type
 */
template <class T>
void BinarySearchTree<T>::print(Type _t, Node* cur)
{
    if(_t == PREORDER)
    {
        if (cur == NULL)
            return;

        cout << cur->data << " ";
        print(_t, cur->leftChild);
        print(_t, cur->rightChild);

    }
    else if(_t == INORDER)
    {
        if (cur == NULL)
            return;

        print(_t, cur->leftChild);
        cout << cur->data << " ";
        print(_t, cur->rightChild);
    }
    else if(_t == POSTORDER)
    {
        if (cur == NULL)
            return;

        print(_t, cur->leftChild);
        print(_t, cur->rightChild);
        cout << cur->data << " ";
    }

}

/**
 * ADD com-------------------------
 * @param Node
 */
template <class T>
void BinarySearchTree<T>::printLevelOrder(Node *root)
{
    int h = getHeight(this->root);

    for (int i = 1; i <= h; i++)
    {
        cout << "LEVEL (" << i << ") ";
        printGivenLevel(root, i);
        cout << endl;
    }
}

/**
 * ADD com-------------------------
 * @param T, T, Node
 */
template <class T>
void BinarySearchTree<T>::printInRange(T _low, T _high, Node* _cur)
{
    if (_cur == NULL)
        return;

    printInRange(_low, _high, _cur->leftChild);

    if(_low <= _cur->data && _high >= _cur->data)
        cout << _cur->data << " ";

    printInRange(_low, _high, _cur->rightChild);
}

/**
 * Print nodes at a given level
 * @param T, T, Node
 */
template <class T>
void BinarySearchTree<T>::printGivenLevel(Node* root, int level)
{
    if (root == NULL)
        return;

    if (level == 1)
        cout << root->data << " ";
    else if (level > 1)
    {
        printGivenLevel(root->leftChild, level-1);
        printGivenLevel(root->rightChild, level-1);
    }
}

/**
 * ADD com-------------------------
 * @param Node
 */
template <class T>
void BinarySearchTree<T>::destroy(Node *_node)
{
    if (_node == NULL)
        return;

    destroy(_node->leftChild);
    destroy(_node->rightChild);
    delete _node;
}

/**
 * Returns the root of BinarySearchTree
 * @return int
 */
template <class T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::getRoot()
{
    return this->root;
}

/**
 * Returns the number of elements in the BinarySearchTree
 * @return int
 */
template <class T>
int BinarySearchTree<T>::size()
{
    return this->count;
}

/**
 * Returns whether the BinarySearchTree is empty
 * @return bool
 */
template <class T>
bool BinarySearchTree<T>::empty()
{
    return size() == 0;
}

/**
 * A destructor to clear the BinarySearchTree and leave no memory leaks
 */
template <class T>
BinarySearchTree<T>::~BinarySearchTree()
{
    this->destroy(this->root);
    this->root = NULL;
}

#endif // BINARYSEARCHTREE_H_INCLUDED
