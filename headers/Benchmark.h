#ifndef BENCHMARK_H
#define BENCHMARK_H

#include "ArrayList.h"
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"

// Klasa do pomiarów czasu.
// Zapisuje wyniki do plików CSV.
class Benchmark {
private:
    static const int N = 8;
    unsigned int sizes[N];
    int reps;

    void make_data(int* data, unsigned int n, int min_value = 0, int max_value = 99999) const;

    // Każda z tych metod mierzy jedną operację.
    double measure_push_back(List& list, int value, const int* data, unsigned int n) const;
    double measure_push_front(List& list, int value, const int* data, unsigned int n) const;
    double measure_insert_mid(List& list, int value, const int* data, unsigned int n) const;
    double measure_pop_front(List& list, const int* data, unsigned int n) const;
    double measure_pop_back(List& list, const int* data, unsigned int n) const;
    double measure_remove_mid(List& list, const int* data, unsigned int n) const;
    double measure_find(List& list, int value, const int* data, unsigned int n) const;

    // Pomocniczo wypełnia strukturę tym samym zestawem danych.
    void fill_list(List& list, const int* data, unsigned int n) const;

public:
    Benchmark();
    void run_all() const;
};

#endif
