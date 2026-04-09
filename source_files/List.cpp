#include "../headers/List.h"

#include <cstdlib>
#include <fstream>

bool List::load_from_file(const std::string& file_name) {
    std::ifstream file(file_name.c_str());
    if (!file.is_open()) {
        return false;
    }

    // Najpierw czyścimy strukturę, żeby nie mieszać starych danych z nowymi.
    clear();

    int x = 0;
    while (file >> x) {
        // Dodajemy na koniec, żeby zachować kolejność z pliku.
        push_back(x);
    }

    return true;
}

void List::fill_random(unsigned int count, int min_value, int max_value) {
    clear();

    if (min_value > max_value) {
        int temp = min_value;
        min_value = max_value;
        max_value = temp;
    }

    for (unsigned int i = 0; i < count; ++i) {
        int x = min_value + (std::rand() % (max_value - min_value + 1));
        push_back(x);
    }
}
