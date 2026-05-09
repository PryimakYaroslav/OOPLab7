#pragma once
#include <iostream>
#include <memory>
#include "SingleNode.h"

template <typename T>
class SingleLinkedList {
    std::unique_ptr<SingleNode<T>> head;
    int size = 0;

public:
    SingleLinkedList() : head(nullptr), size(0) {}

    SingleLinkedList(T data) {
        head = std::make_unique<SingleNode<T>>(data);
        size = 1;
    }

    ~SingleLinkedList() {
        while (head) {
            head = std::move(head->next);
        }
    }

    void push_front(T data) {
        auto newNode = std::make_unique<SingleNode<T>>(data);
        newNode->next = std::move(head);
        head = std::move(newNode);
        size++;
    }

    void pop_back() {
        if (!head) return;
        if (!head->next) {
            head.reset();
            size = 0;
            return;
        }
        auto* current = head.get();
        while (current->next && current->next->next) {
            current = current->next.get();
        }
        current->next.reset();
        size--;
    }

    int get_size() const { return size; }
    
    void print() const {
        auto* current = head.get();
        while (current) {
            std::cout << current->data << " -> ";
            current = current->next.get();
        }
        std::cout << "nullptr" << std::endl;
    }
};