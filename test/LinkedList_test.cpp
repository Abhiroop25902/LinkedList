#include "../src/lib/LinkedList/LinkedList.h"
#include "../src/lib/LinkedList/LinkedList.cpp"
#include <gtest/gtest.h>

TEST(LinkedListTest, EmptyListTest) {
    LinkedList<int> ll;

    stringstream ss;
    ss << ll;
    string actual = ss.str();

    string expected = "NULL";

    EXPECT_EQ(expected, actual);
}

TEST(LinkedListTest, OneElementListTest) {
    LinkedList<int> ll;
    ll.push_back(1);

    stringstream ss;
    ss << ll;
    string actual = ss.str();

    string expected = "1->NULL";

    EXPECT_EQ(expected, actual);
}

TEST(LinkedListTest, MultipleElementsListTest) {
    LinkedList<int> ll;
    for (int i = 1; i <= 5; i++)
        ll.push_back(i);

    stringstream ss;
    ss << ll;
    string actual = ss.str();

    string expected = "1->2->3->4->5->NULL";

    EXPECT_EQ(expected, actual);
}

TEST(LinkedListTest, PushFrontTest) {
    LinkedList<long> ll;
    for (int i = 1; i <= 3; i++)
        ll.push_back(i);
    for (int i = 4; i <= 6; i++)
        ll.push_front(i);

    stringstream ss;
    ss << ll;
    string actual = ss.str();

    string expected = "6->5->4->1->2->3->NULL";

    EXPECT_EQ(expected, actual);
}

TEST(LinkedListTest, ThrowErrorIfListEmptyAndFrontCalled) {
    LinkedList<long> ll;

    EXPECT_THROW(
            try {
                long frontData = ll.front();
                FAIL() << "expected out_of_range";
            } catch (const out_of_range &e) {
                string expectedErrorMsg = "Error: LinkedList is Empty";
                string actualErrorMsg = e.what();

                EXPECT_EQ(expectedErrorMsg, actualErrorMsg);
                throw e;
            }, out_of_range
    );


}

TEST(LinkedListTest, ListNotEmptyAndFrontCalled) {
    LinkedList<long> ll;
    vector<long> numbersGenerated;

    for (int i = 0; i < 5; i++) {
        auto num = random();
        numbersGenerated.push_back(num);
        ll.push_back(num);
    }

    auto expected = numbersGenerated.front();
    auto actual = ll.front();

    EXPECT_EQ(expected, actual);


}

TEST(LinkedListTest, ThrowErrorIfListEmptyAndBackCalled) {
    LinkedList<long> ll;

    EXPECT_THROW(
            try {
                long frontData = ll.back();
                FAIL() << "expected out_of_range";
            } catch (const out_of_range &e) {
                string expectedErrorMsg = "Error: LinkedList is Empty";
                string actualErrorMsg = e.what();

                EXPECT_EQ(expectedErrorMsg, actualErrorMsg);
                throw e;
            }, out_of_range
    );
}

TEST(LinkedListTest, ListNotEmptyAndBackCalled) {
    LinkedList<long> ll;
    vector<long> numbersGenerated;

    for (int i = 0; i < 5; i++) {
        auto num = random();
        numbersGenerated.push_back(num);
        ll.push_back(num);
    }

    auto expected = numbersGenerated.back();
    auto actual = ll.back();

    EXPECT_EQ(expected, actual);
}

TEST(LinkedListTest, ListNotEmptyAndPopBackCalled) {
    LinkedList<long> ll;
    vector<long> numbers;
    for (int i = 0; i < 5; i++) {
        long randNum = random();

        numbers.push_back(randNum);
        ll.push_back(randNum);
    }

    ll.pop_back();
    numbers.pop_back();

    stringstream ssExpected;
    for (auto e: numbers)
        ssExpected << e << "->";
    ssExpected << "NULL";

    string expectedResult = ssExpected.str();

    stringstream ssActual;
    ssActual << ll;

    string actualResult = ssActual.str();

    EXPECT_EQ(expectedResult, actualResult);
}

TEST(LinkedListTest, ListEmptyAfterPopBackCalled) {
    LinkedList<long> ll;
    vector<long> numbers;

    ll.push_back(random());
    ll.pop_back();

    string expectedResult = "NULL";

    stringstream ssActual;
    ssActual << ll;

    string actualResult = ssActual.str();

    EXPECT_EQ(expectedResult, actualResult);
}

TEST(LinkedListTest, ThrowErrorIfListEmptyAndPopBackCalled) {
    LinkedList<long> ll;

    EXPECT_THROW(
            try {
                ll.pop_back();
                FAIL() << "expected length_error";
            } catch (const out_of_range &e) {
                string expectedErrorMsg = "Error: LinkedList is Empty";
                string actualErrorMsg = e.what();

                EXPECT_EQ(expectedErrorMsg, actualErrorMsg);
                throw e;
            }, length_error
    );
}

TEST(LinkedListTest, ListNotEmptyAndPopFrontCalled) {
    LinkedList<long> ll;
    vector<long> numbers;
    for (int i = 0; i < 5; i++) {
        long randNum = random();

        numbers.push_back(randNum);
        ll.push_back(randNum);
    }

    ll.pop_front();
    numbers.erase(numbers.begin());

    stringstream ssExpected;
    for (auto e: numbers)
        ssExpected << e << "->";
    ssExpected << "NULL";

    string expectedResult = ssExpected.str();

    stringstream ssActual;
    ssActual << ll;

    string actualResult = ssActual.str();

    EXPECT_EQ(expectedResult, actualResult);
}

TEST(LinkedListTest, ListEmptyAfterPopFrontCalled) {
    LinkedList<long> ll;
    vector<long> numbers;

    ll.push_back(random());
    ll.pop_front();

    string expectedResult = "NULL";

    stringstream ssActual;
    ssActual << ll;

    string actualResult = ssActual.str();

    EXPECT_EQ(expectedResult, actualResult);
}

TEST(LinkedListTest, ThrowErrorIfListEmptyAndPopFrontCalled) {
    LinkedList<long> ll;

    EXPECT_THROW(
            try {
                ll.pop_front();
                FAIL() << "expected length_error";
            } catch (const out_of_range &e) {
                string expectedErrorMsg = "Error: LinkedList is Empty";
                string actualErrorMsg = e.what();

                EXPECT_EQ(expectedErrorMsg, actualErrorMsg);
                throw e;
            }, length_error
    );
}

TEST(LinkedListTest, SizeTestPushBack) {
    LinkedList<long> ll;
    size_t expectedSize = 0;

    for (int i = 0; i < 10; i++) {
        ll.push_back(random());
        expectedSize++;

        EXPECT_EQ(ll.size(), expectedSize);
    }
}

TEST(LinkedListTest, SizeTestPushFront) {
    LinkedList<long> ll;
    size_t expectedSize = 0;

    for (int i = 0; i < 10; i++) {
        ll.push_front(random());
        expectedSize++;

        EXPECT_EQ(ll.size(), expectedSize);
    }
}

TEST(LinkedListTest, SizeTestPopBack) {
    LinkedList<long> ll;
    size_t expectedSize = 0;

    for (int i = 0; i < 10; i++) {
        ll.push_front(random());
        expectedSize++;
    }

    for (int i = 0; i < 10; i++) {
        ll.pop_back();
        expectedSize--;

        EXPECT_EQ(ll.size(), expectedSize);
    }
}

TEST(LinkedListTest, SizeTestPopFront) {
    LinkedList<long> ll;
    size_t expectedSize = 0;

    for (int i = 0; i < 10; i++) {
        ll.push_front(random());
        expectedSize++;
    }

    for (int i = 0; i < 10; i++) {
        ll.pop_front();
        expectedSize--;

        EXPECT_EQ(ll.size(), expectedSize);
    }
}

TEST(LinkedListTest, FindGivesNullWhenLLEmpty) {
    LinkedList<long> ll;
    auto nodePtr = ll.find(1);

    EXPECT_TRUE(nodePtr == nullptr);
}

TEST(LinkedListTest, FindGivesCorrectPtr) {
    LinkedList<long> ll;
    vector<long> generatedNumbers;

    for (int i = 0; i < 10; i++) {
        auto randomNumber = random();
        ll.push_back(randomNumber);
        generatedNumbers.push_back(randomNumber);
    }

    auto idx = random() % generatedNumbers.size();

    auto expected = generatedNumbers[idx];

    auto ptrIdx = ll.find(expected);

    if (ptrIdx == nullptr) {
        FAIL() << "ptrIdx should not be nullptr";
    }

    auto actual = ptrIdx->getData();
    EXPECT_EQ(expected, actual);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
