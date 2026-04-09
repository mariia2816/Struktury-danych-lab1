#include "../headers/ArrayList.h"

#include <iostream>

ArrayList::ArrayList() : arr(nullptr), count(0), cap(1) {
    arr = new int[cap];
}

ArrayList::~ArrayList() {
    delete[] arr;
}

void ArrayList::resize(unsigned int new_cap) {
    if (new_cap < 1) {
        new_cap = 1;
    }

    int* new_arr = new int[new_cap];

    for (unsigned int i = 0; i < count; ++i) {
        new_arr[i] = arr[i];
    }

    delete[] arr;
    arr = new_arr;
    cap = new_cap;
}

void ArrayList::push_front(int value) {
    if (count == cap) {
        resize(cap * 2);
    }

    // Robimy miejsce na początku.
    for (unsigned int i = count; i > 0; --i) {
        arr[i] = arr[i - 1];
    }

    arr[0] = value;
    ++count;
}

void ArrayList::push_back(int value) {
    if (count == cap) {
        resize(cap * 2);
    }

    arr[count] = value;
    ++count;
}

bool ArrayList::insert(unsigned int index, int value) {
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

    if (count == cap) {
        resize(cap * 2);
    }

    // Przesuwamy elementy w prawo od końca do miejsca wstawienia.
    for (unsigned int i = count; i > index; --i) {
        arr[i] = arr[i - 1];
    }

    arr[index] = value;
    ++count;
    return true;
}

bool ArrayList::pop_front() {
    if (count == 0) {
        return false;
    }

    // Po usunięciu pierwszego elementu przesuwamy resztę w lewo.
    for (unsigned int i = 0; i + 1 < count; ++i) {
        arr[i] = arr[i + 1];
    }

    --count;

    // Dla prostoty zostawiam aktualną pojemność.
    return true;
}

bool ArrayList::pop_back() {
    if (count == 0) {
        return false;
    }

    --count;
    return true;
}

bool ArrayList::remove_at(unsigned int index) {
    if (index >= count) {
        return false;
    }

    if (index == 0) {
        return pop_front();
    }

    if (index == count - 1) {
        return pop_back();
    }

    for (unsigned int i = index; i + 1 < count; ++i) {
        arr[i] = arr[i + 1];
    }

    --count;
    return true;
}

int ArrayList::find(int value) const {
    for (unsigned int i = 0; i < count; ++i) {
        if (arr[i] == value) {
            return static_cast<int>(i);
        }
    }

    return -1;
}

int ArrayList::get(unsigned int index) const {
    if (index >= count) {
        return 0;
    }

    return arr[index];
}

void ArrayList::clear() {
    delete[] arr;
    cap = 1;
    count = 0;
    arr = new int[cap];
}

void ArrayList::display(unsigned int limit) const {
    std::cout << name() << " [size=" << count << ", cap=" << cap << "]\n";

    unsigned int how_many = count;
    if (how_many > limit) {
        how_many = limit;
    }

    for (unsigned int i = 0; i < how_many; ++i) {
        std::cout << arr[i] << ' ';
    }

    if (count > limit) {
        std::cout << "...";
    }

    std::cout << "\n";
}

unsigned int ArrayList::size() const {
    return count;
}

bool ArrayList::empty() const {
    return count == 0;
}

const char* ArrayList::name() const {
    return "ArrayList";
}
