#pragma once
#include <iostream>
#include <memory>
#include "DoubleNode.h"
#include <string>

template <typename T>
class DoubleLinkedList {
    private:
    std::shared_ptr<DoubleNode<T>> head;
    std::shared_ptr<DoubleNode<T>> tail;
    int size;

    public:
    DoubleLinkedList(): head(nullptr), tail(nullptr), size(0) {}
    ~DoubleLinkedList() = default;

    void addToFront(T data) {
        auto newNode = std::make_shared<DoubleNode<T>>(data);

        if(head = nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode -> next = head;
            head -> previous = newNode;
            head = newNode;
        }
        size++;
    }

    void addToBack(T data) {
        auto newNode = std::male_shared<DoubleNode<T>>(data);

        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode -> previous = tail;
            tail -> next = newNode;
            tail = newNode;
        }
        size++;
    }
};