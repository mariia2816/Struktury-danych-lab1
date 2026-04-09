#include "../headers/SinglyLinkedList.h"

#include <iostream>

SinglyLinkedList::SinglyLinkedList() : head(nullptr), tail(nullptr), count(0) {}

SinglyLinkedList::~SinglyLinkedList() {
    clear();
}

SinglyLinkedList::Node* SinglyLinkedList::get_node(unsigned int index) const {
    if (index >= count) {
        return nullptr;
    }

    Node* p = head;
    for (unsigned int i = 0; i < index; ++i) {
        p = p->next;
    }

    return p;
}

void SinglyLinkedList::push_front(int value) {
    Node* node = new Node(value);
    node->next = head;
    head = node;

    if (tail == nullptr) {
        tail = node;
    }

    ++count;
}

void SinglyLinkedList::push_back(int value) {
    Node* node = new Node(value);

    if (tail == nullptr) {
        head = node;
        tail = node;
    } else {
        tail->next = node;
        tail = node;
    }

    ++count;
}

bool SinglyLinkedList::insert(unsigned int index, int value) {
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

    Node* prev = get_node(index - 1);
    if (prev == nullptr) {
        return false;
    }

    Node* node = new Node(value);
    node->next = prev->next;
    prev->next = node;
    ++count;
    return true;
}

bool SinglyLinkedList::pop_front() {
    if (head == nullptr) {
        return false;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
    --count;

    if (head == nullptr) {
        tail = nullptr;
    }

    return true;
}

bool SinglyLinkedList::pop_back() {
    if (tail == nullptr) {
        return false;
    }

    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
        count = 0;
        return true;
    }

    Node* p = head;
    while (p->next != tail) {
        p = p->next;
    }

    delete tail;
    tail = p;
    tail->next = nullptr;
    --count;
    return true;
}

bool SinglyLinkedList::remove_at(unsigned int index) {
    if (index >= count) {
        return false;
    }

    if (index == 0) {
        return pop_front();
    }

    if (index == count - 1) {
        return pop_back();
    }

    Node* prev = get_node(index - 1);
    if (prev == nullptr || prev->next == nullptr) {
        return false;
    }

    Node* temp = prev->next;
    prev->next = temp->next;
    delete temp;
    --count;
    return true;
}

int SinglyLinkedList::find(int value) const {
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

int SinglyLinkedList::get(unsigned int index) const {
    Node* p = get_node(index);
    if (p == nullptr) {
        return 0;
    }
    return p->value;
}

void SinglyLinkedList::clear() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    tail = nullptr;
    count = 0;
}

void SinglyLinkedList::display(unsigned int limit) const {
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

unsigned int SinglyLinkedList::size() const {
    return count;
}

bool SinglyLinkedList::empty() const {
    return count == 0;
}

const char* SinglyLinkedList::name() const {
    return "SinglyLinkedList";
}
