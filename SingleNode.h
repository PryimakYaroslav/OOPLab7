#pragma once
#include <memory>

template <typename T>
struct SingleNode {
    T data;
    std::unique_ptr<SingleNode<T>> next;

    SingleNode(T val) : data(val), next(nullptr) {}
    SingleNode() : next(nullptr) {}
};