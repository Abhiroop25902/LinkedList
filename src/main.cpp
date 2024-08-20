#include <iostream>
#include <sstream>
#include "lib/LinkedList/LinkedList.h"
#include "lib/LinkedList/LinkedList.cpp"

using namespace std;

int main() {
    LinkedList<long> ll;
    auto nodePtr = ll.find(1);


    cout << (nodePtr == nullptr ? "Nullptr" : "Not");
}
