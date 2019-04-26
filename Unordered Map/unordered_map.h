/**
 *  @file    unordered_map.h
 *  @author  Mahmoud Ahmed Tawfik (@mahmoudahmedd)
 *  @date    25/04/2019
 *  @version 1.0
 */
#pragma once

#ifndef UNORDEREDMAP_H_INCLUDED
#define UNORDEREDMAP_H_INCLUDED

#include <iostream>
#include <unordered_map> // UnorderedMap<K, V>::hashFunction(K) - return hash<K>()(key)

using namespace std;

template <class K, class V>
class UnorderedMap
{
private:
    struct Element
    {
        K key;
        V value;

        Element() {}

        Element(K _key, V _value)
        {
            this->key   = _key;
            this->value = _value;
        }
    };

    Element **table;
    Element *dummy;
    int capacity;
    int count;       // Current size of pairs
public:
    // Constructor
    UnorderedMap();

    // Member functions
    void print();

    // Hash policy
    int hashFunction(K);

    // Modifiers
    void insert(K, V);
    V remove(K);

    // Element access
    V& operator[](const K);
    V& at(K);

    // Capacity
    int size();
    bool empty();

    // Destructor
    ~UnorderedMap();
};

/**
 * Default constructor
 */
template <class K, class V>
UnorderedMap<K, V>::UnorderedMap()
{
    this->dummy = new Element();
    this->capacity = 10069;
    this->count = 0;

    this->table = new Element*[capacity];

    for (int i = 0; i < this->capacity; i++)
        this->table[i] = NULL;
}

/**
 * Prints the UnorderedMap values to a screen
 */
template <class K, class V>
void UnorderedMap<K, V>::print()
{
    for(int i = 0 ; i < this->capacity ; i++)
        if(this->table[i] != NULL)
            cout << "key = " << this->table[i]->key << "  value = " << this->table[i]->value << endl;
}

/**
 * That takes an object of type K as argument and returns a unique value of type int based on it
 * @return int
 */
template <class K, class V>
int UnorderedMap<K, V>::hashFunction(K _key)
{
    return hash<K>()(_key) % this->capacity;
}

/**
 * Inserts new elements in the UnorderedMap
 * @param K, V
 */
template <class K, class V>
void UnorderedMap<K, V>::insert(K _key, V _value)
{
    Element *temp = new Element(_key, _value);

    int hashIndex = this->hashFunction(_key);

    while(this->table[hashIndex] != NULL && this->table[hashIndex]->key != _key)
        hashIndex = (hashIndex + 1) % capacity;

    if(table[hashIndex] == NULL )
        this->count++;

    this->table[hashIndex] = temp;
}

/**
 * Removes from the UnorderedMap table
 * @param K
 * @return V
 */
template <class K, class V>
V UnorderedMap<K, V>::remove(K _key)
{
    int hashIndex = this->hashFunction(_key);

    while(this->table[hashIndex] != NULL)
    {
        if(this->table[hashIndex]->key == _key)
        {
            Element *temp = table[hashIndex];

            this->table[hashIndex] = NULL;

            this->count--;

            return temp->value;
        }

        hashIndex = (hashIndex + 1) % capacity;
    }

    // If not found return dummy
    return this->dummy->value;
}

/**
 * Returns a reference to the mapped value of the element with K _key in the UnorderedMap
 * @param K
 * @return V
 */
template <class K, class V>
V& UnorderedMap<K, V>::operator[](const K _key)
{
    int hashIndex = this->hashFunction(_key);
    int counter   = 0;

    while(this->table[hashIndex] != NULL)
    {
        if(counter++ > this->capacity)
            return this->dummy->value;

        if(this->table[hashIndex]->key == _key)
        {
            return this->table[hashIndex]->value;
        }

        hashIndex = (hashIndex + 1) % this->capacity;
    }

    // If not found return dummy
    return this->dummy->value;
}

/**
 * Returns a reference to the mapped value of the element with K _key in the UnorderedMap
 * @param K
 * @return V
 */
template <class K, class V>
V& UnorderedMap<K, V>::at(K _key)
{
    int hashIndex = this->hashFunction(_key);
    int counter   = 0;

    while(this->table[hashIndex] != NULL)
    {
        if(counter++ > this->capacity)
            return this->dummy->value;

        if(this->table[hashIndex]->key == _key)
            return this->table[hashIndex]->value;

        hashIndex = (hashIndex + 1) % this->capacity;
    }

    // If not found return dummy
    return this->dummy->value;
}

/**
 * Returns the number of elements in the UnorderedMap
 * @return int
 */
template <class K, class V>
int UnorderedMap<K, V>::size()
{
    return this->count;
}

/**
 * Returns whether the UnorderedMap is empty
 * @return bool
 */
template <class K, class V>
bool UnorderedMap<K, V>::empty()
{
    return size() == 0;
}

/**
 * A destructor to clear the UnorderedMap and leave no memory leaks
 */
template <class K, class V>
UnorderedMap<K, V>::~UnorderedMap()
{
    for (int i = 0; i < capacity; i++)
        if (table[i] != NULL)
            delete table[i];

    delete[] table;
}

#endif // UNORDEREDMAP_H_INCLUDED
