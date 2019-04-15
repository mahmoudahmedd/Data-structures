/**
 *  @file    queue.h
 *  @author  Mahmoud Ahmed Tawfik (@mahmoudahmedd)
 *  @date    13/04/2019
 *  @version 1.0
 */

#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <iostream>

using namespace std;

template <class T>
class Queue
{
private:
    T *arr;   	     // array to store queue elements
    int capacity;    // maximum capacity of the queue
    int frontIndex;  // front points to front element in the queue
    int rearIndex;   // rear points to last element in the queue
    int count;       // current size of the queue

public:
    Queue();
    Queue(T, int);

    T& front();
    void pop();
    void push(T);
    int size();
    bool empty();

    ~Queue();
};

/**
 * Default constructor
 */
template <class T>
Queue<T>::Queue()
{
    this->arr = NULL;
    this->capacity = 0;
    this->frontIndex = 0;
    this->rearIndex  = -1;
    this->count = 0;
}

/**
 * Constructs a queue having ‘_intialSize’ elements whose values are ‘_value’
 * @param  T, int
 */
template <class T>
Queue<T>::Queue(T _value, int _intialSize)
{
    this->arr = new T[_intialSize];
    this->capacity = _intialSize;
    this->frontIndex = 0;
    this->rearIndex  = _intialSize - 1;
    this->count = _intialSize;

    for(int i = 0; i < this->count; i++)
        this->arr[i] = _value;
}

/**
 * Returns the first element by reference
 * @return T
 */
template <class T>
T& Queue<T>::front()
{
    if(this->count == 0)
    {
        cerr << "Queue<T>::front() - Out Of Range."  << endl;
        exit(EXIT_FAILURE); // Exit the program
    }

    return arr[this->frontIndex];
}

/**
 * Removes the first element
 */
template <class T>
void Queue<T>::pop()
{
    if (this->count == 0)
    {
        cerr << "Queue<T>::pop() - Out Of Range."  << endl;
        exit(EXIT_FAILURE); // Exit the program
    }

    this->frontIndex = (this->frontIndex + 1) % capacity;
    this->count--;
}

/**
 * Adds an element to the back of the queue.
 * @param T
 */
template <class T>
void Queue<T>::push(T _value)
{
    if(this->count == this->capacity)
    {
        T *temp = new T[this->capacity];

        for (int i = 0; i < this->capacity; i++)
            temp[i] = this->arr[i];

        if(this->capacity > 0)
            delete[] this->arr;

        this->capacity = this->capacity * 2 + 10; // Doubling the Size
        this->arr = new T[this->capacity]();

        for(int i = 0; i < (this->capacity - 10) / 2; i++)
            this->arr[i] = temp[i];
    }

    this->rearIndex = (this->rearIndex + 1) % capacity;
    this->arr[this->rearIndex] = _value;
    this->count++;
}

/**
 * Returns the number of elements in the queue
 * @return int
 */
template <class T>
int Queue<T>::size()
{
    return this->count;
}

/**
 * Returns whether the queue is empty
 * @return bool
 */
template <class T>
bool Queue<T>::empty()
{
    return size() == 0;
}

/**
 * A destructor to clear the queue and leave no memory leaks
 */
template <class T>
Queue<T>::~Queue()
{
    if(this->capacity > 0)
        delete[] this->arr;
}

#endif // QUEUE_H_INCLUDED
