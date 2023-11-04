//
// Created by genuine on 11/4/23.
//

#include "skiena/ch3/3.3.h"

namespace chapter3 {
    LinkedList::LinkedList() = default;

    LinkedList::~LinkedList() = default;

    void LinkedList::insert(int elem, int index) {
        if (index < 0 || index > size_) {
            return;
        }

        Node *node = new Node(elem, nullptr);

        Node *curr = head_;

        if (index == 0) {
            node->next = head_;
            head_ = node;
            if (size_ == 0) {
                tail_ = node;
            }
        } else if (index == size_) {
            tail_->next = node;
            tail_ = node;
        } else {
            for (int i = 0; i < index - 1; i++) {
                curr = curr->next;
            }

            node->next = curr->next;
            curr->next = node;
        }

        size_ += 1;
    }

    void LinkedList::push_front(int elem) {
        insert(elem, 0);
    }

    void LinkedList::push_back(int elem) {
        insert(elem, size_);
    }

    int LinkedList::size() const {
        return size_;
    }

    std::vector<int> LinkedList::traverse() const {
        std::vector<int> elems{};
        Node *curr{head_};
        while (curr) {
            elems.push_back(curr->elem);
            curr = curr->next;
        }

        return elems;
    }

    void LinkedList::erase(int index) {
        if (index < 0 || index > size_ - 1) {
            return;
        }

        Node *curr = head_;

        if (size_ == 1) {
            head_ = nullptr;
            tail_ = nullptr;
        } else if (index == 0) {
            Node *firstNode = head_;
            head_ = head_->next;
            firstNode->next = nullptr;
        } else {
            for (int i = 0; i < index - 1; i++) {
                curr = curr->next;
            }

            Node *nextNode = curr->next->next;
            curr->next->next = nullptr;
            curr->next = nextNode;
            if (nextNode == nullptr) {
                tail_ = curr;
            }
        }

        size_ -= 1;
    }

    void LinkedList::pop_back() {
        erase(size_ - 1);
    }

    void LinkedList::pop_front() {
        erase(0);
    }
} // chapter3