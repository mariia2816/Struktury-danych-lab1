#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include "List.h"

// Prosta lista jednokierunkowa.
// Każdy element zna tylko następny element.
class SinglyLinkedList : public List {
private:
    struct Node {
        int value;
        Node* next;

        Node(int v) : value(v), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    unsigned int count;

    // Zwraca węzeł o danym indeksie.
    Node* get_node(unsigned int index) const;

public:
    SinglyLinkedList();
    ~SinglyLinkedList() override;

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
