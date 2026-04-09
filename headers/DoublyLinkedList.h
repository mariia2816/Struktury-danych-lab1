#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "List.h"

// Prosta lista dwukierunkowa.
// Każdy element ma wskaźnik na poprzedni i następny element.
class DoublyLinkedList : public List {
private:
    struct Node {
        int value;
        Node* prev;
        Node* next;

        Node(int v) : value(v), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    unsigned int count;

    // Dla prostoty przechodzimy od początku listy.
    Node* get_node(unsigned int index) const;

public:
    DoublyLinkedList();
    ~DoublyLinkedList() override;

    void push_front(int value) override;
    void push_back(int value) override;
    bool insert(unsigned int index, int value) override;

    bool pop_front() override;
    bool pop_back() override;
    bool remove_at(unsigned int index) override;

    int find(int value) const override;
    int get(unsigned int index) const override;

    void clear() override;
    void display(unsigned int limit = 50) const override;
    unsigned int size() const override;
    bool empty() const override;
    const char* name() const override;
};

#endif
