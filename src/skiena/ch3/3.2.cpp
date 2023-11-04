/**
* @brief Give an algorithm that takes a string
* consisting of opening and closing parentheses, say )()(())()()))())))(, and finds the length of the longest
* balanced parentheses in , which is 12 in the example above. (Hint: The solution is not necessarily a
* contiguous run of parenthesis from .)
**/
#include "skiena/ch3/3.2.h"

#include <vector>

int chapter3::longestMatchingParenthesis(std::string_view string) {
    std::vector<char> stack{};
    int count{0};
    for (const auto &ch: string) {
        if (ch == '(') {
            stack.push_back(ch);
        } else if (ch == ')' && !stack.empty()) {
            if (stack.back() == '(') {
                count += 2;
            }
            stack.pop_back();
        }
    }

    return count;
}