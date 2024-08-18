
#include <iostream>
#include "Node.h"

using namespace std;

template<typename T>
Node<T>::Node(T const &data, Node<T> *nextNode): data(data), nextNode(nextNode) {}

template<typename U>
ostream &operator<<(ostream &os, const Node<U> &node) {
    os << node.data << "->";
    if (node.nextNode != nullptr)
        os << *node.nextNode;
    else
        os << "NULL";
    return os;
}


