//
// Created by genuine on 11/2/23.
//

#include <skiena/ch3/ch3.h>
#include <gtest/gtest.h>

TEST(matchingParentheses, matching) {
    std::string_view string = "(((())))";
    std::string_view string2 = "(()))()(()";

    EXPECT_EQ(true, chapter3::matchingParentheses(string));
    EXPECT_EQ(false, chapter3::matchingParentheses(string2));
}