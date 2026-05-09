#include "SingleNode.h"

template <typename T>
class SingleLinkedList {
    std::unique_ptr<SingleNode<T>> head;
    int size = 0;

    public:
    SingleLinkedList(T data);
    ~SingleLinkedList();
};