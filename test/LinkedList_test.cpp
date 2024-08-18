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

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
