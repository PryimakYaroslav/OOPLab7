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

        if(head == nullptr) {
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
        auto newNode = std::make_shared<DoubleNode<T>>(data);

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

    void printList() {
    std::shared_ptr<DoubleNode<T>> current = head;
    std::cout << "List: ";
    while (current != nullptr) {
        std::cout << current->data;
        current = current->next;
        if (current != nullptr) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

    void deleteFromFront() {
        if (!head) throw std::string("List is empty");

        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = head -> next;
            head -> previous.reset();
        }
        size--;
    }

    void deleteFromBack() {
        if (!tail) throw std::string("List is empty");

        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            std::shared_ptr<DoubleNode<T>> newTail = tail -> previous.lock();
            tail = newTail;
            tail -> next = nullptr;
        }
        size--;
    }

    void printSize() {
        std::cout << "Size of the list: " << size << std::endl;
    }

    void isEmpty() {
        if (size == 0) {
            std::cout << "The list is empty." << std::endl;
        } else {
            std::cout << "The list is not empty." << std::endl;
        }
    }
};