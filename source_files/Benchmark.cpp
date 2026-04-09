#include "../headers/Benchmark.h"

#include <chrono>
#include <cstdlib>
#include <fstream>
#include <iostream>

using Clock = std::chrono::high_resolution_clock;
using Micro = std::chrono::duration<double, std::micro>;

Benchmark::Benchmark() : reps(20) {
    sizes[0] = 5000;
    sizes[1] = 8000;
    sizes[2] = 10000;
    sizes[3] = 16000;
    sizes[4] = 20000;
    sizes[5] = 40000;
    sizes[6] = 60000;
    sizes[7] = 100000;
}

void Benchmark::make_data(int* data, unsigned int n, int min_value, int max_value) const {
    for (unsigned int i = 0; i < n; ++i) {
        data[i] = min_value + (std::rand() % (max_value - min_value + 1));
    }
}

void Benchmark::fill_list(List& list, const int* data, unsigned int n) const {
    list.clear();
    for (unsigned int i = 0; i < n; ++i) {
        list.push_back(data[i]);
    }
}

double Benchmark::measure_push_back(List& list, int value, const int* data, unsigned int n) const {
    fill_list(list, data, n);
    auto start = Clock::now();
    list.push_back(value);
    auto stop = Clock::now();
    return Micro(stop - start).count();
}

double Benchmark::measure_push_front(List& list, int value, const int* data, unsigned int n) const {
    fill_list(list, data, n);
    auto start = Clock::now();
    list.push_front(value);
    auto stop = Clock::now();
    return Micro(stop - start).count();
}

double Benchmark::measure_insert_mid(List& list, int value, const int* data, unsigned int n) const {
    fill_list(list, data, n);
    auto start = Clock::now();
    list.insert(n / 2, value);
    auto stop = Clock::now();
    return Micro(stop - start).count();
}

double Benchmark::measure_pop_front(List& list, const int* data, unsigned int n) const {
    fill_list(list, data, n);
    auto start = Clock::now();
    list.pop_front();
    auto stop = Clock::now();
    return Micro(stop - start).count();
}

double Benchmark::measure_pop_back(List& list, const int* data, unsigned int n) const {
    fill_list(list, data, n);
    auto start = Clock::now();
    list.pop_back();
    auto stop = Clock::now();
    return Micro(stop - start).count();
}

double Benchmark::measure_remove_mid(List& list, const int* data, unsigned int n) const {
    fill_list(list, data, n);
    auto start = Clock::now();
    list.remove_at(n / 2);
    auto stop = Clock::now();
    return Micro(stop - start).count();
}

double Benchmark::measure_find(List& list, int value, const int* data, unsigned int n) const {
    fill_list(list, data, n);
    auto start = Clock::now();
    list.find(value);
    auto stop = Clock::now();
    return Micro(stop - start).count();
}

void Benchmark::run_all() const {
    ArrayList a;
    SinglyLinkedList s;
    DoublyLinkedList d;

    std::ofstream f1("results/append.csv");
    std::ofstream f2("results/prepend.csv");
    std::ofstream f3("results/insert.csv");
    std::ofstream f4("results/pop_front.csv");
    std::ofstream f5("results/pop_back.csv");
    std::ofstream f6("results/remove.csv");
    std::ofstream f7("results/search.csv");

    f1 << "size,ArrayList,SinglyLinkedList,DoublyLinkedList\n";
    f2 << "size,ArrayList,SinglyLinkedList,DoublyLinkedList\n";
    f3 << "size,ArrayList,SinglyLinkedList,DoublyLinkedList\n";
    f4 << "size,ArrayList,SinglyLinkedList,DoublyLinkedList\n";
    f5 << "size,ArrayList,SinglyLinkedList,DoublyLinkedList\n";
    f6 << "size,ArrayList,SinglyLinkedList,DoublyLinkedList\n";
    f7 << "size,ArrayList,SinglyLinkedList,DoublyLinkedList\n";

    for (int i = 0; i < N; ++i) {
        unsigned int n = sizes[i];

        double a1 = 0, s1 = 0, d1 = 0;
        double a2 = 0, s2 = 0, d2 = 0;
        double a3 = 0, s3 = 0, d3 = 0;
        double a4 = 0, s4 = 0, d4 = 0;
        double a5 = 0, s5 = 0, d5 = 0;
        double a6 = 0, s6 = 0, d6 = 0;
        double a7 = 0, s7 = 0, d7 = 0;

        for (int r = 0; r < reps; ++r) {
            int* data = new int[n];
            make_data(data, n);

            int add_value = 123456789;
            int find_value = data[n / 2];

            // W jednym powtórzeniu wszystkie struktury dostają te same dane.
            a1 += measure_push_back(a, add_value, data, n);
            s1 += measure_push_back(s, add_value, data, n);
            d1 += measure_push_back(d, add_value, data, n);

            a2 += measure_push_front(a, add_value, data, n);
            s2 += measure_push_front(s, add_value, data, n);
            d2 += measure_push_front(d, add_value, data, n);

            a3 += measure_insert_mid(a, add_value, data, n);
            s3 += measure_insert_mid(s, add_value, data, n);
            d3 += measure_insert_mid(d, add_value, data, n);

            a4 += measure_pop_front(a, data, n);
            s4 += measure_pop_front(s, data, n);
            d4 += measure_pop_front(d, data, n);

            a5 += measure_pop_back(a, data, n);
            s5 += measure_pop_back(s, data, n);
            d5 += measure_pop_back(d, data, n);

            a6 += measure_remove_mid(a, data, n);
            s6 += measure_remove_mid(s, data, n);
            d6 += measure_remove_mid(d, data, n);

            a7 += measure_find(a, find_value, data, n);
            s7 += measure_find(s, find_value, data, n);
            d7 += measure_find(d, find_value, data, n);

            delete[] data;
        }

        f1 << n << ',' << a1 / reps << ',' << s1 / reps << ',' << d1 / reps << '\n';
        f2 << n << ',' << a2 / reps << ',' << s2 / reps << ',' << d2 / reps << '\n';
        f3 << n << ',' << a3 / reps << ',' << s3 / reps << ',' << d3 / reps << '\n';
        f4 << n << ',' << a4 / reps << ',' << s4 / reps << ',' << d4 / reps << '\n';
        f5 << n << ',' << a5 / reps << ',' << s5 / reps << ',' << d5 / reps << '\n';
        f6 << n << ',' << a6 / reps << ',' << s6 / reps << ',' << d6 / reps << '\n';
        f7 << n << ',' << a7 / reps << ',' << s7 / reps << ',' << d7 / reps << '\n';

        std::cout << "Finished size: " << n << "\n";
    }

    std::cout << "Benchmark finished. Results saved to results/*.csv\n";
}
