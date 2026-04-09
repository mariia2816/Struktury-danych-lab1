#include "../headers/ArrayList.h"
#include "../headers/SinglyLinkedList.h"
#include "../headers/DoublyLinkedList.h"
#include "../headers/Benchmark.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

// Proste menu dla jednej struktury.
static void list_menu(List& list) {
    int choice = -1;

    while (choice != 0) {
        std::cout << "\n=== " << list.name() << " ===\n";
        std::cout << "1. Fill with random data\n";
        std::cout << "2. Load from file\n";
        std::cout << "3. Push front\n";
        std::cout << "4. Push back\n";
        std::cout << "5. Insert at index\n";
        std::cout << "6. Pop front\n";
        std::cout << "7. Pop back\n";
        std::cout << "8. Remove at index\n";
        std::cout << "9. Find value\n";
        std::cout << "10. Display\n";
        std::cout << "11. Clear\n";
        std::cout << "0. Back\n";
        std::cout << "Choice: ";
        std::cin >> choice;

        int value = 0;
        unsigned int index = 0;
        unsigned int count = 0;
        std::string file_name;

        switch (choice) {
            case 1:
                std::cout << "How many elements? ";
                std::cin >> count;
                list.fill_random(count);
                std::cout << "Created.\n";
                break;

            case 2:
                std::cout << "File path: ";
                std::cin >> file_name;
                if (list.load_from_file(file_name)) {
                    std::cout << "Loaded.\n";
                } else {
                    std::cout << "Cannot open file.\n";
                }
                break;

            case 3:
                std::cout << "Value: ";
                std::cin >> value;
                list.push_front(value);
                std::cout << "Done.\n";
                break;

            case 4:
                std::cout << "Value: ";
                std::cin >> value;
                list.push_back(value);
                std::cout << "Done.\n";
                break;

            case 5:
                std::cout << "Index: ";
                std::cin >> index;
                std::cout << "Value: ";
                std::cin >> value;
                if (list.insert(index, value)) {
                    std::cout << "Done.\n";
                } else {
                    std::cout << "Wrong index.\n";
                }
                break;

            case 6:
                if (list.pop_front()) {
                    std::cout << "Done.\n";
                } else {
                    std::cout << "Structure is empty.\n";
                }
                break;

            case 7:
                if (list.pop_back()) {
                    std::cout << "Done.\n";
                } else {
                    std::cout << "Structure is empty.\n";
                }
                break;

            case 8:
                std::cout << "Index: ";
                std::cin >> index;
                if (list.remove_at(index)) {
                    std::cout << "Done.\n";
                } else {
                    std::cout << "Wrong index.\n";
                }
                break;

            case 9:
                std::cout << "Value: ";
                std::cin >> value;
                std::cout << "Index: " << list.find(value) << "\n";
                break;

            case 10:
                list.display();
                break;

            case 11:
                list.clear();
                std::cout << "Cleared.\n";
                break;

            case 0:
                break;

            default:
                std::cout << "Wrong choice.\n";
                break;
        }
    }
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    ArrayList arr;
    SinglyLinkedList sll;
    DoublyLinkedList dll;
    Benchmark bench;

    int choice = -1;

    while (choice != 0) {
        std::cout << "\n===== DATA STRUCTURES PROJECT =====\n";
        std::cout << "1. ArrayList\n";
        std::cout << "2. SinglyLinkedList\n";
        std::cout << "3. DoublyLinkedList\n";
        std::cout << "4. Run benchmark\n";
        std::cout << "0. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                list_menu(arr);
                break;
            case 2:
                list_menu(sll);
                break;
            case 3:
                list_menu(dll);
                break;
            case 4:
                bench.run_all();
                break;
            case 0:
                break;
            default:
                std::cout << "Wrong choice.\n";
                break;
        }
    }

    return 0;
}
