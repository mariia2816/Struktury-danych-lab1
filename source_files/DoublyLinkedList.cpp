#include "../headers/DoublyLinkedList.h"

#include <iostream>

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr), count(0) {}

DoublyLinkedList::~DoublyLinkedList() {
    clear();
}

DoublyLinkedList::Node* DoublyLinkedList::get_node(unsigned int index) const {
    if (index >= count) {
        return nullptr;
    }

    Node* p = head;
    for (unsigned int i = 0; i < index; ++i) {
        p = p->next;
    }

    return p;
}

void DoublyLinkedList::push_front(int value) {
    Node* node = new Node(value);
    node->next = head;

    if (head != nullptr) {
        head->prev = node;
    }

    head = node;

    if (tail == nullptr) {
        tail = node;
    }

    ++count;
}

void DoublyLinkedList::push_back(int value) {
    Node* node = new Node(value);
    node->prev = tail;

    if (tail != nullptr) {
        tail->next = node;
    }

    tail = node;

    if (head == nullptr) {
        head = node;
    }

    ++count;
}

bool DoublyLinkedList::insert(unsigned int index, int value) {
    if (index > count) {
        return false;
    }

    if (index == 0) {
        push_front(value);
        return true;
    }

    if (index == count) {
        push_back(value);
        return true;
    }

    Node* next = get_node(index);
    if (next == nullptr) {
        return false;
    }

    Node* prev = next->prev;
    Node* node = new Node(value);

    node->prev = prev;
    node->next = next;
    prev->next = node;
    next->prev = node;
    ++count;
    return true;
}

bool DoublyLinkedList::pop_front() {
    if (head == nullptr) {
        return false;
    }

    Node* temp = head;
    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }

    delete temp;
    --count;
    return true;
}

bool DoublyLinkedList::pop_back() {
    if (tail == nullptr) {
        return false;
    }

    Node* temp = tail;
    tail = tail->prev;

    if (tail != nullptr) {
        tail->next = nullptr;
    } else {
        head = nullptr;
    }

    delete temp;
    --count;
    return true;
}

bool DoublyLinkedList::remove_at(unsigned int index) {
    if (index >= count) {
        return false;
    }

    if (index == 0) {
        return pop_front();
    }

    if (index == count - 1) {
        return pop_back();
    }

    Node* p = get_node(index);
    if (p == nullptr) {
        return false;
    }

    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
    --count;
    return true;
}

int DoublyLinkedList::find(int value) const {
    Node* p = head;
    unsigned int index = 0;

    while (p != nullptr) {
        if (p->value == value) {
            return static_cast<int>(index);
        }
        p = p->next;
        ++index;
    }

    return -1;
}

int DoublyLinkedList::get(unsigned int index) const {
    Node* p = get_node(index);
    if (p == nullptr) {
        return 0;
    }
    return p->value;
}

void DoublyLinkedList::clear() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    tail = nullptr;
    count = 0;
}

void DoublyLinkedList::display(unsigned int limit) const {
    std::cout << name() << " [size=" << count << "]\n";

    Node* p = head;
    unsigned int shown = 0;

    while (p != nullptr && shown < limit) {
        std::cout << p->value << ' ';
        p = p->next;
        ++shown;
    }

    if (p != nullptr) {
        std::cout << "...";
    }

    std::cout << "\n";
}

unsigned int DoublyLinkedList::size() const {
    return count;
}

bool DoublyLinkedList::empty() const {
    return count == 0;
}

const char* DoublyLinkedList::name() const {
    return "DoublyLinkedList";
}
