//
// Created by genuine on 11/9/23.
//

#include "skiena/ch3/3.8.h"

#include <iostream>

TicTacToe::TicTacToe(int size) : size_(size), board_(size * size, 0) {}

TicTacToe::~TicTacToe() = default;

void TicTacToe::move(int row, int col, int value) {
    board_[(row - 1) * size_ + (col - 1)] = value;
}

bool TicTacToe::check(int currValue) {
    int sum{};
    for (int row = 0; row < size_; row++) {
        sum = 0;
        for (int col = 0; col < size_; col++) {
            sum += board_[col + row * size_];
        }

        if (sum == currValue * size_) {
            return true;
        }
    }

    for (int col = 0; col < size_; ++col) {
        sum = 0;
        for (int row = 0; row < size_; row++) {
            sum += board_[row * size_ + col];
        }

        if (sum == currValue * size_) {
            return true;
        }
    }

    sum = 0;
    for (int row = 0; row < size_; row++) {
        for (int col = 0; col < size_; col++) {
            if (row == col) {
                sum += board_[row * size_ + col];
            }
        }
    }

    if (sum == currValue * size_) {
        return true;
    }

    sum = 0;
    for (int row = 0; row < size_; row++) {
        for (int col = 0; col < size_; col++) {
            if (row + col == size_ + 1) {
                sum += board_[row * size_ + col];
            }
        }
    }

    if (sum == currValue * size_) {
        return true;
    }

    return false;
}

std::vector<int> TicTacToe::get() const {
    return board_;
}

void TicTacToe::print() const {
    for (int row = 0; row < size_; row++) {
        std::cout << "[";
        for (int col = 0; col < size_; col++) {
            std::cout << board_[row * 3 + col] << " ";
        }
        std::cout << "]";
    }
}