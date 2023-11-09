//
// Created by genuine on 11/9/23.
//

#ifndef ALGORITHMS_DATASTRUCTURES_3_8_H
#define ALGORITHMS_DATASTRUCTURES_3_8_H

#include <vector>

class TicTacToe {
public:
    explicit TicTacToe(int size);

    ~TicTacToe();

    void move(int row, int col, int value);

    bool check(int currValue);

    void print() const;

    [[nodiscard]] std::vector<int> get() const;

private:
    int size_;
    std::vector<int> board_;
};

#endif //ALGORITHMS_DATASTRUCTURES_3_8_H