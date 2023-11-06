//
// Created by genuine on 11/6/23.
//

#include <cstddef>
#include <vector>

template<typename T>
class Stack {
public:
    explicit Stack() = default;

    ~Stack() = default;

    void push(T elem) {
        top_ += 1;
        stack_[top_] = elem;
        if (min_.empty() || elem <= min_.back()) {
            min_.push_back(elem);
        }
    }

    T pop() {
        auto elem = stack_[top_];
        if (!min_.empty() && elem == min_.back()) {
            min_.pop_back();
        }
        top_ -= 1;
        return elem;
    }

    T top() {
        return stack_[top_];
    }

    T getMin() {
        return min_.back();
    }

private:
    std::array<T, 100> stack_{};
    int top_{-1};
    std::vector<T> min_{};
};