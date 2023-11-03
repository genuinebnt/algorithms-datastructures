//
// Created by genuine on 11/2/23.
//

#include <skiena/ch3/ch3.h>
#include <gtest/gtest.h>

#include <array>

using namespace chapter3;

TEST(matchingParentheses, matching) {
    std::array<std::pair<std::string, int>, 7> testCases{
            {
                    {"((()))", -1}, {"", -1}, {"(", 0}, {")", 0}, {"(()", 0}, {"((())))", 6}, {"((()", 0}
            }
    };

    for (const auto &[first, second]: testCases) {
        EXPECT_EQ(second, matchingParentheses(first));
    }
}