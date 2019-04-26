/**
 *  @file    linked_list.h
 *  @author  Mahmoud Ahmed Tawfik (@mahmoudahmedd)
 *  @date    24/04/2019
 *  @version 1.0
 */
#pragma once

#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include <iostream>

using namespace std;

template <class T>
class LinkedList
{
private:
	struct Node
	{
		T data;
		Node *next;

		Node()
		{
			next = NULL;
		}

		Node(T _value)
		{
			data = _value;
			next = NULL;
		}
	};

	Node *head;
	Node *tail;
	Node *dummy;
    int count;   // Current size of the list

public:
    LinkedList();
    LinkedList(T, int);
	
	// Member class
	class Iterator;

	// Member functions
	LinkedList<T>& operator=(LinkedList<T> &);
	void print();

	// Iterators
	Iterator begin();
	Iterator end();

	// Capacity
    int size();
	bool empty();

	// Modifiers
	void push_back(T);


    ~LinkedList();
};

/**
 * Default constructor
 */
template <class T>
LinkedList<T>::LinkedList()
{
	this->dummy = new Node;
    this->head = this->tail = this->dummy;
    this->count = 0;
}

/**
 * Constructs a LinkedList having ‘_intialSize’ elements whose values are ‘_value’
 */
template <class T>
LinkedList<T>::LinkedList(T _value, int _intialSize)
{
	this->dummy = new Node;
    this->head = this->tail = this->dummy;
    this->count = 0;

	for(int i = 0;i < _intialSize;i++)
		this->push_back(_value);
}

/**
 * Member class
 */
template <class T>
class LinkedList<T>::Iterator
{
private:
	Node *n;
public:
	Iterator(Node *_n)
	{
		n = _n;
	}

	Node *get()
	{
		return n;
	}

	void operator++()
	{
		if(n->next == NULL)
		{
			cerr << "LinkedList<T>::Iterator::operator++() - Out Of Range."  << endl;
			exit(EXIT_FAILURE); // Exit the program
		}

		n = n->next;
	}

	T &operator*()
	{
		return this->n->data;
	}

	bool operator==(const Iterator &_rhs)
	{
		return (this->n == _rhs.n);
	}

    bool operator!=(const Iterator &_rhs)
	{
		return (this->n != _rhs.n);
	}
};

/**
 * Assign content
 */
template <class T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T> &_l)
{
	Node *n = head;

	while(n->next != NULL)
	{
		Node *prev = n;
		n = n->next;

		delete prev;
	}

	delete this->dummy;

	this->dummy = new Node;
    this->head = this->tail = this->dummy;
    this->count = 0;

	n = _l.head;

	while(n->next != NULL)
	{
		this->push_back(n->data);
		n = n->next;
	}

	return *this;
}

/**
 * Prints the list values to a screen
 */
template <class T>
void LinkedList<T>::print()
{
	Node *n = head;

	while(n->next != NULL)
	{
		cout << n->data << endl;
		n = n->next;
	}
}

/**
 * Return iterator to beginning
 * @return Iterator
 */
template <class T>
typename LinkedList<T>::Iterator LinkedList<T>::begin()
{
    Iterator it(this->head);
    return it;
}

/**
 * Return iterator to end
 * @return Iterator
 */
template <class T>
typename LinkedList<T>::Iterator LinkedList<T>::end()
{
	Iterator it(this->dummy);
    return it;
}

/**
 * Returns the number of elements in the LinkedList
 * @return int
 */
template <class T>
int LinkedList<T>::size()
{
	return this->count;
} 

/**
 * Returns whether the LinkedList is empty
 * @return bool
 */
template <class T>
bool LinkedList<T>::empty()
{
    return size() == 0;
}

/**
 * Adds a new element at the end of the LinkedList
 * @param T
 */
template <class T>
void LinkedList<T>::push_back(T _value)
{
	Node *n = new Node(_value);
	
	if(this->count == 0)
	{
		this->head = this->tail = n;
	}
	else
	{
		this->tail->next = n;
		this->tail = n;
	}

	n->next = this->dummy;
	this->count++;
}


/**
 * A destructor to clear the LinkedList and leave no memory leaks
 */
template <class T>
LinkedList<T>::~LinkedList()
{
	Node *n = head;

	while(n->next != NULL)
	{
		Node *prev = n;
		n = n->next;

		delete prev;
	}

	delete this->dummy;
}

#endif // LINKEDLIST_H_INCLUDED
