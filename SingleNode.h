#include <memory>
template <typename T>

struct SingleNode {
    T data;
    std::unique_ptr<SingleNode<T>> next;
};