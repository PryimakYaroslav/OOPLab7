#include <iostream>
#include "SingleLinkedList.h"

int main() {
    SingleLinkedList<int> list;

    if (list.is_empty()) {
        std::cout << "Список порожній, додаємо дані..." << std::endl;
    }

    list.push_front(100);
    list.push_front(200);

    int search_idx = 1;
    int* found_val = list.find(search_idx);

    if (found_val != nullptr) {
        std::cout << "Знайдено за індексом " << search_idx << ": " << *found_val << std::endl;
    } else {
        std::cout << "Нічого не знайдено за таким індексом!" << std::endl;
    }

    return 0;
}