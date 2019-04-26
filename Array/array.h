/**
 *  @file    array.h
 *  @author  Mahmoud Ahmed Tawfik (@mahmoudahmedd)
 *  @date    24/04/2019
 *  @version 1.0
 */
#pragma once

#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#include <iostream>

using namespace std;

template <class T>
class Array
{
private:
    T *arr;   	     // Array to store array elements
    int capacity;    // Maximum capacity of the stack
    int topIndex;    // Top points to top element in the array
    int count;       // Current size of the stack

    void expand();   // To double the array size

public:
    // Constructors
    Array();
    Array(T, int);

    // Modifiers
    void push_back(T);
    void pop_back();

    // Element Access
    T &back();
    T &operator[](const int);
    T &at(const int);
    T *data();

    // Capacity
    int size();
    bool empty();

    // Destructor
    ~Array();
};

/**
 * To double the array size
 */
template <class T>
void Array<T>::expand()
{
    T *temp = new T[this->capacity * 2 + 10];

    for (int i = 0; i < this->capacity; i++)
        temp[i] = this->arr[i];

    if(this->capacity > 0)
        delete[] this->arr;

    this->capacity = this->capacity * 2 + 10; // Doubling the Size
    this->arr = temp;
}

/**
 * Default constructor
 */
template <class T>
Array<T>::Array()
{
    this->arr = NULL;
    this->capacity = 0;
    this->topIndex = -1;
    this->count = 0;
}

/**
 * Constructs a array having ‘_intialSize’ elements whose values are ‘_value’
 * @param  T, int
 */
template <class T>
Array<T>::Array(T _value, int _intialSize)
{
    this->arr = new T[_intialSize];
    this->capacity = _intialSize;
    this->topIndex = _intialSize - 1;
    this->count = _intialSize;

    for(int i = 0; i < this->count; i++)
        this->arr[i] = _value;
}

/**
 * Adds a new element at the end of the array
 * @param T
 */
template <class T>
void Array<T>::push_back(T _value)
{
    if(this->topIndex == this->capacity - 1)
    {
        this->expand();
    }

    this->arr[++this->topIndex] = _value;
    this->count++;
}

/**
 * Removes a element at the end of the array
 */
template <class T>
void Array<T>::pop_back()
{
    if(this->topIndex < 0)
    {
        cerr << "Array<T>::pop_back() - Out Of Range."  << endl;
        exit(EXIT_FAILURE); // Exit the program
    }

    this->topIndex--;
    this->count--;
}

/**
 * Returns the end of the array by reference
 * @return T
 */
template <class T>
T& Array<T>::back()
{
    if(this->topIndex < 0)
    {
        cerr << "Array<T>::back() - Out Of Range."  << endl;
        exit(EXIT_FAILURE); // Exit the program
    }

    return this->arr[this->topIndex];
}

/**
 * Returns a reference to the element at position _n in the array container
 * @return T
 */
template <class T>
T& Array<T>::operator[](const int _n)
{
    if(_n < 0 || _n > (this->count - 1))
    {
        cerr << "Array<T>::operator[] - Out Of Range."  << endl;
        exit(EXIT_FAILURE); // Exit the program
    }

    return this->arr[_n];
}

/**
 * Returns a reference to the element at position _n in the array container
 * @return T
 */
template <class T>
T& Array<T>::at(const int _n)
{
    if(_n < 0 || _n > (this->count - 1))
    {
        cerr << "Array<T>::at() - Out Of Range."  << endl;
        exit(EXIT_FAILURE); // Exit the program
    }

    return this->arr[_n];
}

/**
 * Returns a direct pointer to the memory array used internally by the array
 * @return T
 */
template <class T>
T* Array<T>::data()
{
    return this->arr;
}

/**
 * Returns the number of elements in the array
 * @return int
 */
template <class T>
int Array<T>::size()
{
    return this->count;
}

/**
 * Returns whether the array is empty
 * @return bool
 */
template <class T>
bool Array<T>::empty()
{
    return size() == 0;
}

/**
 * A destructor to clear the array and leave no memory leaks
 */
template <class T>
Array<T>::~Array()
{
    if(this->capacity > 0)
        delete[] this->arr;
}

#endif // ARRAY_H_INCLUDED
