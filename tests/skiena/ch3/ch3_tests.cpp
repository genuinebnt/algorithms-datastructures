//
// Created by genuine on 11/2/23.
//

#include <skiena/ch3/ch3.h>
#include <gtest/gtest.h>

#include <array>

using namespace chapter3;

TEST(matchingParentheses, chapter3) {
    std::array<std::pair<std::string, int>, 7> testCases{
            {
                    {"((()))", -1}, {"", -1}, {"(", 0}, {")", 0}, {"(()", 0}, {"((())))", 6}, {"((()", 0}
            }
    };

    for (const auto &[first, second]: testCases) {
        EXPECT_EQ(second, matchingParentheses(first));
    }
}

TEST(longestParentheses, chapter3) {
    std::array<std::pair<std::string, int>, 5> testCases{
            {
                    {")()(())()()))())))(", 12}, {"(())", 4}, {"(((", 0}, {"))))", 0}, {"", 0}
            }
    };

    for (const auto &[first, second]: testCases) {
        EXPECT_EQ(second, longestMatchingParenthesis(first));
    }
}

TEST(linkedList, chapter3) {
    LinkedList list{};

    list.push_back(3);
    list.push_front(1);
    list.insert(5, 0);
    list.insert(9, 10);
    list.insert(11, 1);
    list.erase(1);
    list.insert(15, 1);
    list.pop_back();
    list.pop_front();
    list.insert(12, 0);
    list.erase(2);
    list.erase(3);
    list.push_back(31);
    list.push_front(9);

    EXPECT_EQ(4, list.size());

    std::vector<int> expectedResult{9, 12, 15, 31};
    EXPECT_EQ(expectedResult, list.traverse());
}