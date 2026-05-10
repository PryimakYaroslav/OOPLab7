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

    T& acces_by_index(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds");
        }

        SingleNode<T>* current = head.get();
        for (int i = 0; i < index; ++i) {
            current = current->next.get();
        }
        return current->data;
    }

    void remove_by_index(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds");
        }

        if (index == 0) {
            head = std::move(head->next);
        } else {
            SingleNode<T>* current = head.get();
            for (int i = 0; i < index - 1; ++i) {
                current = current->next.get();
            }

            current->next = std::move(current->next->next);
        }
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

    bool is_empty() const {
        return size == 0;
    }

    T* find(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("No element by this index"); 
        }

        SingleNode<T>* current = head.get();
        for (int i = 0; i < index; ++i) {
            current = current->next.get();
        }
        return &(current->data);
    }
};