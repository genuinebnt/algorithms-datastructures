//
// Created by genuine on 11/4/23.
//

#ifndef ALGORITHMS_DATASTRUCTURES_3_3_H
#define ALGORITHMS_DATASTRUCTURES_3_3_H

#include <vector>
#include <memory>

namespace chapter3 {

    template<typename T>
    struct Node {
        T elem;
        std::shared_ptr<Node> next_;
    };

    template<typename T>
    class LinkedList {
    public:
        LinkedList() = default;

        ~LinkedList() = default;

        void push_front(T elem) {
            insert(elem, 0);
        }

        void push_back(T elem) {
            insert(elem, size_);
        }

        void pop_back() {
            erase(size_ - 1);
        }

        void pop_front() {
            erase(0);
        }

        void insert(T elem, int index) {
            if (index < 0 || index > size_) {
                return;
            }

            std::shared_ptr<Node<int>> node{std::make_shared<Node<int>>(elem, nullptr)};
            std::shared_ptr<Node<int>> curr{head_};

            if (index == 0) {
                node->next_ = head_;
                head_ = node;
                if (size_ == 0) {
                    tail_ = node;
                }
            } else if (index == size_) {
                tail_->next_ = node;
                tail_ = node;
            } else {
                for (int i = 0; i < index - 1; i++) {
                    curr = curr->next_;
                }

                node->next_ = curr->next_;
                curr->next_ = node;
            }

            size_ += 1;
        }

        void erase(T index) {
            if (index < 0 || index > size_ - 1) {
                return;
            }

            std::shared_ptr<Node<T>> curr = head_;

            if (size_ == 1) {
                head_ = nullptr;
                tail_ = nullptr;
            } else if (index == 0) {
                std::shared_ptr<Node<T>> firstNode = head_;
                head_ = head_->next_;
                firstNode->next_ = nullptr;
            } else {
                for (int i = 0; i < index - 1; i++) {
                    curr = curr->next_;
                }

                std::shared_ptr<Node<T>> nextNode = curr->next_->next_;
                curr->next_->next_ = nullptr;
                curr->next_ = nextNode;
                if (nextNode == nullptr) {
                    tail_ = curr;
                }
            }

            size_ -= 1;
        }

        void reverse() {
            if (size_ == 0 || size_ == 1) {
                return;
            }

            std::shared_ptr<Node<T>> curr = head_;
            std::shared_ptr<Node<T>> prev = nullptr;

            std::shared_ptr<Node<T>> lastNode = tail_;
            tail_ = head_;
            head_ = lastNode;

            while (curr) {
                std::shared_ptr<Node<T>> next = curr->next_;
                curr->next_ = prev;
                prev = curr;
                curr = next;
            }

        }

        [[nodiscard]] std::vector<T> traverse() const {
            std::vector<int> elems{};
            std::shared_ptr<Node<T>> curr{head_};
            while (curr) {
                elems.push_back(curr->elem);
                curr = curr->next_;
            }

            return elems;
        }

        [[nodiscard]] int size() const {
            return size_;
        };

    private:
        std::shared_ptr<Node<T>> head_{};
        std::shared_ptr<Node<T>> tail_{};
        int size_{0};
    };

} // chapter3

#endif //ALGORITHMS_DATASTRUCTURES_3_3_H