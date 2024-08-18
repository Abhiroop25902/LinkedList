
#include <iostream>
#include "Node.h"

using namespace std;

template<typename T>
Node<T>::Node(T const &data): data(data), nextNode(nullptr) {}

template<typename T>
Node<T> *Node<T>::getNext() {
    return this->nextNode;
}

template<typename T>
T Node<T>::getData() {
    return this->data;
}

template<typename T>
void Node<T>::setNext(Node<T> *next) {
    this->nextNode = next;
}

template<typename U>
ostream &operator<<(ostream &os, const Node<U> &node) {
    os << node.data << "->";
    if (node.nextNode != nullptr)
        os << *node.nextNode;
    else
        os << "NULL";
    return os;
}


