#include <iostream>
#include "SingleLinkedList.h"

int main() {
    SingleLinkedList<int> list(10);
    list.push_front(20);
    list.push_front(30);
    
    std::cout << "List contents: ";
    list.print();

    list.pop_back();
    std::cout << "After pop_back: ";
    list.print();
    std::cout << list.get_size();

    return 0;
}