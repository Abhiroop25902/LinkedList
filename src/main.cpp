#include "lib/Node/Node.h"
#include "lib/Node/Node.cpp"
#include <iostream>

using namespace std;

int main() {
    auto *a = new Node<int>(1, new Node<int>(2));
    cout << *a << endl;
    return 0;
}
