#include "LinkedList.h"
#include "Node/Node.h"
#include "Node/Node.cpp"

template<typename T>
LinkedList<T>::LinkedList(): root(nullptr), length(0) {}

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
        this->length++;
        return;
    }

    Node<T> *curr = this->root;

    while (curr->getNext() != nullptr)
        curr = curr->getNext();

    curr->setNext(dataNode);

    this->length++;
}

template<typename T>
void LinkedList<T>::push_front(const T &data) {
    auto *dataNode = new Node<T>(data);

    if (this->root == nullptr) {
        this->root = dataNode;
        this->length++;
        return;
    }

    dataNode->setNext(this->root);
    this->root = dataNode;

    this->length++;
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

template<typename T>
void LinkedList<T>::pop_back() {
    if (this->root == nullptr)
        throw length_error("Error: LinkedList is Empty");

    if (this->root->getNext() == nullptr) {
        delete this->root;
        this->root = nullptr;
        this->length--;
        return;
    }

    Node<T> *curr = this->root;
    Node<T> *back;

    while (curr->getNext() != nullptr) {
        back = curr;
        curr = curr->getNext();
    }

    back->setNext(nullptr);
    delete curr;

    this->length--;
}

template<typename T>
void LinkedList<T>::pop_front() {
    if (this->root == nullptr)
        throw length_error("Error: LinkedList is Empty");

    if (this->root->getNext() == nullptr) {
        delete this->root;
        this->root = nullptr;
        this->length--;
        return;
    }

    Node<T> *curr = this->root;
    this->root = this->root->getNext();
    delete curr;
    this->length--;
}

template<typename T>
size_t LinkedList<T>::size() {
    return length;
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
