/**
 * @brief Give algorithm that returns true if string contains properly nested and balanced parentheses. False otherwise.
 * Identify position of first offending parentheses
 */

#include "skiena/ch3/ch3.h"
#include <vector>

using std::vector;

bool chapter3::matchingParentheses(std::string_view string) {
    vector<char> stack{};
    for (const auto &c: string) {
        if (c == '(') {
            stack.push_back(c);
        } else if (c == ')') {
            if (!stack.empty()) {
                stack.pop_back();
            }
        }
    }

    return stack.empty();
}