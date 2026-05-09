#include <iostream>
#include "SingleLinkedList.h"

int main() {
    SingleLinkedList<int> list(10);
    list.push_front(20);
    list.push_front(30);
    list.push_front(40);
    list.push_front(50);
    
    std::cout << "List contents: ";
    list.print();

    list.pop_back();
    std::cout << "After pop_back: ";
    list.print();

    list.remove_by_index(1);
    list.print();

    return 0;
}