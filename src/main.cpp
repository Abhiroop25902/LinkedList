#include <iostream>
#include <vector>
#include <numeric>
#include <chrono>
#include "lib/LinkedList/LinkedList.h"
#include "lib/LinkedList/LinkedList.cpp"


using namespace std;

const long SIZE = 100000;
const long PROBE_COUNT = 10000;

double average(vector<long> &timeList) {
    auto sum = accumulate(timeList.begin(), timeList.end(), (long long) 0);
    return ((double) sum) / ((double) timeList.size());
}

void LLStressTest() {
    LinkedList<long> ll;
    vector<long> generatedData;

    vector<long> timeList;

    for (long i = 0; i < SIZE; i++) {
        cout << "\rAdding Elements: " << i << "/" << SIZE;
        auto randNum = random();

        ll.push_back(randNum);
        generatedData.push_back(randNum);
    }
    cout << "\nElements Added\n";

    for (long j = 0; j < PROBE_COUNT; j++) {
        long randomIdx = random() % SIZE;

        cout << "\r" << j << "/" << PROBE_COUNT << ": Finding Element with Idx " << randomIdx << ": ";
        const auto startTime = clock();
        auto nodePtr = ll.find(generatedData[randomIdx]);
        const auto endTime = clock();

        if (nodePtr == nullptr) {
            cout << "Error: nodePtr is null";
            throw;
        }
        if (nodePtr->getData() != generatedData[randomIdx]) {
            cout << "Error: Data does not match" << endl;
            cout << "nodePtr->getData(): " << nodePtr->getData() << endl;
            cout << "generatedData[randomIdx]: " << generatedData[randomIdx] << endl;
        }

        const auto timeTaken = endTime - startTime;
        cout << timeTaken << " ms";

        timeList.push_back(timeTaken);
    }

    auto avgTimeTaken = average(timeList);

    cout << "\nAverage Time Taken for a LL with " << SIZE << " elements: " << avgTimeTaken << " ms\n";
}

int main() {
    LLStressTest();
}
