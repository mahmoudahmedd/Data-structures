/**
 *  @file    binary_search_tree.h
 *  @author  Mahmoud Ahmed Tawfik (@mahmoudahmedd)
 *  @date    25/04/2019
 *  @version 1.0
 */
#pragma once

#ifndef BINARYSEARCHTREE_H_INCLUDED
#define BINARYSEARCHTREE_H_INCLUDED

#include <iostream>

using namespace std;

enum Type{PREORDER, INORDER, POSTORDER};

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
	Node* getParent(T);

	// Member functions
	void print(Type);


    // Modifiers
    void insert(T);
    void remove();

    // Element Access
    T max();
	T min();
    Node *getRoot();

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

}

/**
 * Constructs a BinarySearchTree having ‘_intialSize’ elements whose values are ‘_value’
 */
template <class T>
bool BinarySearchTree<T>::find(T _value)
{
	Node *r = root;

	while(r != NULL && r->data != _value)
	{
		if(_value < r->data)
			r = r->left;
		else
			r = r->right;
	}

	return (r != NULL);
}

/**
 * Insert element
 */
template <class T>
void BinarySearchTree<T>::insert(T _value)
{
	Node *n = new Node(_value);
	Node *parent = this->getParent(_value);

	if(parent == NULL)
	{
		this->root = parent;
		this->count++;
		return;
	}

	if(_value < parent->data)
	{
		parent->leftChild = n;
		this->count++;
	}
	else if(_value > parent->data)
	{
		parent->rightChild = n;
		this->count++;
	}
	
}

/**
 * Get parent
 */
template <class T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::getParent(T _value)
{
	Node *cur = this->root;
	Node *parent = NULL;

	while(cur != NULL && cur->data != _value)
	{
		parent = cur;

		if(_value < cur->data)
			cur = cur->leftChild;
		else
			cur = cur->rightChild;
	}

	return parent; 
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
	
}

#endif // BINARYSEARCHTREE_H_INCLUDED