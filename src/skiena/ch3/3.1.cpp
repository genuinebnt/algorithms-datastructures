/**
 * @brief Give algorithm that returns true if string contains properly nested and balanced parentheses. False otherwise.
 * Identify position of first offending parentheses
 */

#include "skiena/ch3/ch3.h"
#include <vector>

using std::vector;

/** @brief Idea is to push the index into the stack rather than the element
 * if ( is the first element then immediately return the index by checking if stack is empty
 * if after popping stack is not empty then return the first element which is index of first unmatched element
 * */
int chapter3::matchingParentheses(std::string_view string) {
    vector<int> stack{};
    for (int i = 0; i < string.size(); i++) {
        if (string[i] == '(') {
            stack.push_back(i);
        } else if (string[i] == ')') {
            if (stack.empty()) {
                return i;
            }
            stack.pop_back();
        }
    }

    if (!stack.empty()) {
        return stack.front();
    }
    return -1;
}