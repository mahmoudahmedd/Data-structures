/**
 *  @file    stack.h
 *  @author  Mahmoud Ahmed Tawfik (@mahmoudahmedd)
 *  @date    09/04/2019
 *  @version 1.0
 */

#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>

using namespace std;

template <class T>
class Stack
{
private:
    T *arr;   	     // array to store stack elements
    int capacity;    // maximum capacity of the stack
    int topIndex;    // top points to top element in the stack
    int count;       // current size of the stack

public:
    Stack();
    Stack(T, int);

    T& top();
    void pop();
    void push(T);
    int size();
    bool empty();

    ~Stack();
};

/**
 * Default constructor
 */
template <class T>
Stack<T>::Stack()
{
    this->arr = NULL;
    this->capacity = 0;
    this->topIndex = -1;
    this->count = 0;
}

/**
 * Constructs a stack having ‘_intialSize’ elements whose values are ‘_value’
 * @param  T, int
 */
template <class T>
Stack<T>::Stack(T _value, int _intialSize)
{
    this->arr = new T[_intialSize];
    this->capacity = _intialSize;
    this->topIndex = _intialSize - 1;
    this->count = _intialSize;

    for(int i = 0; i < this->count; i++)
        this->arr[i] = _value;
}

/**
 * Returns the top element by reference
 * @return T
 */
template <class T>
T& Stack<T>::top()
{
    if(this->topIndex < 0)
    {
        cerr << "Stack<T>::top() - Out Of Range."  << endl;
        exit(EXIT_FAILURE); // Exit the program
    }

    return arr[this->topIndex];
}

/**
 * Removes the top element
 */
template <class T>
void Stack<T>::pop()
{
    if(this->topIndex < 0)
    {
        cerr << "Stack<T>::pop() - Out Of Range."  << endl;
        exit(EXIT_FAILURE); // Exit the program
    }

    this->topIndex--;
    this->count--;
}

/**
 * Adds an element to the top of the stack
 * @param T
 */
template <class T>
void Stack<T>::push(T _value)
{
    if(this->topIndex == this->capacity - 1)
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

    this->arr[++this->topIndex] = _value;
    this->count++;
}

/**
 * Returns the number of elements in the stack
 * @return int
 */
template <class T>
int Stack<T>::size()
{
    return this->count;
}

/**
 * Returns whether the stack is empty
 * @return bool
 */
template <class T>
bool Stack<T>::empty()
{
    return size() == 0;
}

/**
 * A destructor to clear the stack and leave no memory leaks
 */
template <class T>
Stack<T>::~Stack()
{
    if(this->capacity > 0)
        delete[] this->arr;
}

#endif // STACK_H_INCLUDED
