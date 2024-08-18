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

template<typename T>
void LinkedList<T>::push_front(const T &data) {
    auto *dataNode = new Node<T>(data);

    if (this->root == nullptr) {
        this->root = dataNode;
        return;
    }

    dataNode->setNext(this->root);
    this->root = dataNode;
}

template<typename T>
T LinkedList<T>::front() {
    if (this->root == nullptr)
        throw out_of_range("Error: LinkedList is Empty");

    return this->root->getData();
}

template<typename T>
T LinkedList<T>::back() {
    Node<T> *curr = this->root;

    if (curr == nullptr)
        throw out_of_range("Error: LinkedList is Empty");

    while (curr->getNext() != nullptr) {
        curr = curr->getNext();
    }

    return curr->getData();
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
