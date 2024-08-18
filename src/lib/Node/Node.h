//
// Created by abhir on 18-Aug-24.
//

#ifndef BTREE_FUNCTION_H
#define BTREE_FUNCTION_H

#include <iostream>

using namespace std;

template<typename T>
class Node {
    T data;
    Node *nextNode;

public:
    explicit Node(T const &data, Node<T> *nextNode = nullptr);

    template<typename U>
    friend ostream &operator<<(ostream &os, const Node<U> &node);
};

#endif //BTREE_FUNCTION_H
