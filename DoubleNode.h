#pragma once
#include <memory>

template <typename T>
struct DoubleNode {
    T data;
    std::shared_ptr<DoubleNode<T>> next;
    std::weak_ptr<DoubleNode<T>> previous;
    DoubleNode(T val) : data(val), next(nullptr) {}
};