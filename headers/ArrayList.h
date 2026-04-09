#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "List.h"

// Prosta tablica dynamiczna.
// Gdy zabraknie miejsca, zwiększamy pojemność 2 razy.
class ArrayList : public List {
private:
    int* arr;
    unsigned int count;
    unsigned int cap;

    // Tworzy nową tablicę i przepisuje dane.
    void resize(unsigned int new_cap);

public:
    ArrayList();
    ~ArrayList() override;

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
