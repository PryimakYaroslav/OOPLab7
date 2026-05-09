#include "SingleLinkedList.h"

template <typename T>
SingleLinkedList<T>::SingleLinkedList(T data) {
    head = std::make_unique<SingleNode<T>>(data);
    size = 1;
}

template <typename T>
SingleLinkedList<T>::~SingleLinkedList() {
    head.reset();
    size = 0;
}