//
// Created by abhir on 18-Aug-24.
//

#ifndef BTREE_LINKEDLIST_H
#define BTREE_LINKEDLIST_H

#include "Node/Node.h"

template<typename T>
class LinkedList {
    Node<T> *root;
    size_t length;
public:
    explicit LinkedList();

    ~LinkedList();

    template<typename U>
    friend ostream &operator<<(ostream &os, const LinkedList<U> &ll);

    void push_back(const T &data);

    void push_front(const T &data);

    T front();

    T back();

    void pop_back();

    void pop_front();

    size_t size();

};

#endif //BTREE_LINKEDLIST_H
