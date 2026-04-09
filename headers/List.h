#ifndef LIST_H
#define LIST_H

#include <string>

// Wspólny interfejs dla wszystkich struktur.
// Dzięki temu menu i benchmark mogą pracować na jednym typie.
class List {
public:
    virtual ~List() {}

    // Dodawanie.
    virtual void push_front(int value) = 0;
    virtual void push_back(int value) = 0;
    virtual bool insert(unsigned int index, int value) = 0;

    // Usuwanie.
    virtual bool pop_front() = 0;
    virtual bool pop_back() = 0;
    virtual bool remove_at(unsigned int index) = 0;

    // Odczyt i wyszukiwanie.
    virtual int find(int value) const = 0;
    virtual int get(unsigned int index) const = 0;

    // Operacje pomocnicze.
    virtual void clear() = 0;
    virtual void display(unsigned int limit = 50) const = 0;
    virtual unsigned int size() const = 0;
    virtual bool empty() const = 0;
    virtual const char* name() const = 0;

    // Metody wspólne dla wszystkich struktur.
    virtual bool load_from_file(const std::string& file_name);
    virtual void fill_random(unsigned int count, int min_value = 0, int max_value = 99999);
};

#endif
