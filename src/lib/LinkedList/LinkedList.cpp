#include "LinkedList.h"
#include "Node/Node.h"
#include "Node/Node.cpp"

template<typename T>
LinkedList<T>::LinkedList(): root(nullptr) {}

template<typename T>
LinkedList<T>::~LinkedList() {
    Node<T> *curr = this->root;

    while (curr != nullptr) {
        Node<T> *temp = curr;
        curr = curr->getNext();
        delete temp;
    }
}

template<typename T>
void LinkedList<T>::push_back(const T &data) {
    auto *dataNode = new Node<T>(data);

    if (this->root == nullptr) {
        this->root = dataNode;
        return;
    }

    Node<T> *curr = this->root;

    while (curr->getNext() != nullptr)
        curr = curr->getNext();

    curr->setNext(dataNode);
}

template<typename U>
ostream &operator<<(ostream &os, const LinkedList<U> &ll) {
    auto *node = ll.root;

    while (node != nullptr) {
        os << node->getData() << "->";
        node = node->getNext();
    }

    os << "NULL";

    return os;
}
