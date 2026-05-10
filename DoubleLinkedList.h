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
};