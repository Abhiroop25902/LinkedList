#include <iostream>
#include "lib/LinkedList/LinkedList.h"
#include "lib/LinkedList/LinkedList.cpp"

using namespace std;

int main() {
    LinkedList<int> ll;
    ll.push_back(1);
    ll.push_back(2);

    cout << ll << endl;
}
