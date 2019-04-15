/**
 *  @file    queue.h
 *  @author  Mahmoud Ahmed Tawfik (@mahmoudahmedd)
 *  @date    13/04/2019
 *  @version 1.0
 */

#pragma once

#ifndef PRIORITYQUEUE_H_INCLUDED
#define PRIORITYQUEUE_H_INCLUDED

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

template <class T>
struct Element
{
    T value;
    int priority;

	Element(){}

    Element(T _value, int _priority)
    {
        this->value = _value;
        this->priority = _priority;
    }
	
};

template <class T>
class PriorityQueue
{
private:
    Element<T> *arr; // array to store queue elements
    int capacity;    // maximum capacity of the queue
    int frontIndex;  // front points to front element in the queue
    int rearIndex;   // rear points to last element in the queue
    int count;       // current size of the queue

	static bool priorityComparison(const Element<T> &e1, const Element<T> &e2)
    {
        return e1.priority > e2.priority;
    }

public:
    PriorityQueue();

    T dequeue();
    void enqueue(T, int);
    int size();
    bool empty();

    ~PriorityQueue();
};

/**
 * Default constructor
 */
template <class T>
PriorityQueue<T>::PriorityQueue()
{
    this->arr = NULL;
    this->capacity = 0;
    this->frontIndex = 0;
    this->rearIndex  = -1;
    this->count = 0;
}


/**
 * Dequeue according to the priority
 * @return T
 */
template <class T>
T PriorityQueue<T>::dequeue()
{
    if (this->count == 0)
    {
        cerr << "PriorityQueue<T>::dequeue() - Out Of Range."  << endl;
        exit(EXIT_FAILURE); // Exit the program
    }

    this->frontIndex = (this->frontIndex + 1) % capacity;
    this->count--;

	return arr[this->frontIndex - 1].value;
}

/**
 * Adds an element to the the queue based on the priority.
 * @param T
 */
template <class T>
void PriorityQueue<T>::enqueue(T _value, int _priority)
{
    if(this->count == this->capacity)
    {
        Element<T> *temp = new Element<T>[this->capacity];

        for (int i = 0; i < this->capacity; i++)
            temp[i] = this->arr[i];

        if(this->capacity > 0)
            delete[] this->arr;
		
        this->capacity = this->capacity * 2 + 10; // Doubling the Size
        this->arr = new Element<T>[this->capacity];

        for(int i = 0; i < (this->capacity - 10) / 2; i++)
		{
			this->arr[i].value    = temp[i].value;
			this->arr[i].priority = temp[i].priority;
		}
    }

    this->rearIndex = (this->rearIndex + 1) % capacity;

	this->arr[this->rearIndex].value = _value;
	this->arr[this->rearIndex].priority = _priority;

	sort(arr + frontIndex, arr + rearIndex + 1, priorityComparison);

    this->count++;
}

/**
 * Returns the number of elements in the queue
 * @return int
 */
template <class T>
int PriorityQueue<T>::size()
{
    return this->count;
}

/**
 * Returns whether the queue is empty
 * @return bool
 */
template <class T>
bool PriorityQueue<T>::empty()
{
    return size() == 0;
}

/**
 * A destructor to clear the queue and leave no memory leaks
 */
template <class T>
PriorityQueue<T>::~PriorityQueue()
{
    if(this->capacity > 0)
        delete[] this->arr;
}

#endif // PRIORITYQUEUE_H_INCLUDED
