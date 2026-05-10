#include <iostream>
#include <string>
#include "SingleLinkedList.h"
#include "DoubleLinkedList.h"

int main() {

    try {
    SingleLinkedList<int> list;
    std::cout << "======= SINGLE LINKED LIST =======\n" << std::endl;

    list.isEmpty();
    list.printList();
    std::cout << "-----Adding elements-----\n" << std::endl;
    std::cout << "Adding 5, 10, 15 to the front and 20, 25, 30 to the back\n" << std::endl;
    list.addToFront(5);
    list.addToFront(10);
    list.addToFront(15);
    list.addToBack(20);
    list.addToBack(25);
    list.addToBack(30);
    list.isEmpty();
    list.printList();
    list.printSize();

    std::cout << "-----Adding 17 by index 2-----\n" << std::endl;
    list.addByIndex(2, 17);
    list.printList();

    std::cout << "Finding and access\n" << std::endl;
    list.find(15);
    list.find(100);
    list.accessByIndex(5);

    std::cout << "-----Deleting elements-----\n" << std::endl;
    std::cout << "Deleting elements from the top and back\n" << std::endl;
    list.deleteFromBack();
    list.deleteFromFront();
    list.printList(); 

    std::cout << "-----Deleting elements by index 1-----\n" << std::endl;
    list.deleteByIndex(1);
    list.printList();

    DoubleLinkedList<std::string> list2;
    std::cout << "======= DOUBLE LINKED LIST =======\n" << std::endl;

    list2.isEmpty();
    list2.printList();

    std::cout << "-----Adding elements-----\n" << std::endl;
    std::cout << "Adding Bear, Fox, Hare to the front and Pike, Carp, Zander to the back\n" << std::endl;
    list2.addToFront("Bear");
    list2.addToFront("Fox");
    list2.addToFront("Hare");
    list2.addToBack("Pike");
    list2.addToBack("Carp");
    list2.addToBack("Zander");
    list2.isEmpty();
    list2.printList();
    list2.printSize();

    std::cout << "-----Adding Boar by index 2-----\n" << std::endl;
    list2.addByIndex(2, "Boar");
    list2.printList();

    std::cout << "-----Finding and access-----\n" << std::endl;
    list2.find("Pike");
    list2.find("Moose");
    list2.accessByIndex(2);

    std::cout << "-----Deleting elements by index 1-----\n" << std::endl;
    list2.deleteByIndex(1);
    list2.printList();

    std::cout << "-----Deleting elements-----\n" << std::endl;
    std::cout << "Deleting elements from the top and back\n" << std::endl;
    list2.deleteFromBack();
    list2.deleteFromFront();
    list2.printList();

    } catch (const std::string& e) {
        std::cerr << "Error: " << e;
    }
    return 0;
}