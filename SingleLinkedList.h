#pragma once
#include <iostream>
#include <memory>
#include "SingleNode.h"
#include <string>

template <typename T>
class SingleLinkedList {
private:
    std::unique_ptr<SingleNode<T>> head;
    int size;

public:
    SingleLinkedList() : head(nullptr), size(0) {};
    
    ~SingleLinkedList() {
        while (head) {
            head = std::move(head->next);
        }
    }

    void addToFront(T data) {
        auto newNode = std::make_unique<SingleNode<T>>(data);
        newNode->next = std::move(head);
        head = std::move(newNode);
        size++;
    }

    void addToBack(T data) {
        auto newNode = std::make_unique<SingleNode<T>>(data);
        if (head == nullptr) {
            head = std::move(newNode);
        } else {
            SingleNode<T>* current = head.get();
            while (current->next != nullptr) {
                current = current->next.get();
            }
            current->next = std::move(newNode);
        }
        size++;
    }

    void deleteFromFront() {
        if (head == nullptr) {
            throw std::string("List is empty, there is nothing to delete");
        } else {
            head = std::move(head->next);
            size--;
        }
    }

    void deleteFromBack() {
        if (head == nullptr) {
            throw std::string("List is empty, there is nothing to delete");
        } else {
            if (head->next == nullptr) {
                head = nullptr;
            } else {
                SingleNode<T>* current = head.get();
                while (current->next->next != nullptr) {
                    current = current->next.get();
                }
                current->next = nullptr;
            }
            size--;
        }
    }

    void accessByIndex(int index) {
        if (index < 0 || index >= size) {
            throw std::string("Incorect index");
        } else {
            SingleNode<T>* current = head.get();
            for (int i = 0; i < index; i++) {
                current = current->next.get();
            }
            std::cout << "Element at index " << index << ": " << current->data << std::endl;
        }
    }

    void addByIndex(int index, T data) {
        if (index < 0 || index > size) {
            throw std::string("Incorect index");
        } else if (index == 0) {
            addFront(data);
        } else if (index == size) {
            addBack(data);
        } else {
            auto newNode = std::make_unique<SingleNode<T>>(data);
            SingleNode<T>* current = head.get();
            for (int i = 0; i < index - 1; i++) {
                current = current->next.get();
            }
            newNode->next = std::move(current->next);
            current->next = std::move(newNode);
            size++;
        }
    }

    void deleteByIndex(int index) {
        if (index < 0 || index >= size) {
            throw std::string("Incorect index");
        } else if (index == 0) {
            deleteFront();
        } else if (index == size - 1) {
            deleteBack();
        } else {
            SingleNode<T>* current = head.get();
            for (int i = 0; i < index - 1; i++) {
                current = current->next.get();
            }
            current->next = std::move(current->next->next);
            size--;
        }
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

    void find(T data) {
        SingleNode<T>* current = head.get();
        int index = 0;
        while (current != nullptr) {
            if (current->data == data) {
                std::cout << "Element " << data << " found at index: " << index << std::endl;
                return;
            }
            current = current->next.get();
            index++;
        }
        std::cout << "Element " << data << " not found in the list." << std::endl;
    }

    void printList() {
        SingleNode<T>* current = head.get();
        std::cout << "List elements: ";
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next.get();
        }
        std::cout << std::endl;
    }
};