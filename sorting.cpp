#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <locale>

using namespace std;

struct Criterion {
    int size;
    int bubble_comp;
    int bubble_swap;
    int selection_comp;
    int selection_swap;
};

void print_array(const vector<int>& arr, const string& label) {
    cout << label << " (n=" << arr.size() << "):" << endl;

    for (int value : arr) {
        cout << value << " ";
    }

    cout << endl << endl;
}

void bubble_sort(vector<int>& arr, int& comparisons, int& swaps) {
    comparisons = 0;
    swaps = 0;

    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;

            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swaps++;
            }
        }
    }
}

void selection_sort(vector<int>& arr, int& comparisons, int& swaps) {
    comparisons = 0;
    swaps = 0;

    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;

        for (int j = i + 1; j < n; j++) {
            comparisons++;

            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        if (min_idx != i) {
            swap(arr[i], arr[min_idx]);
            swaps++;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    vector<int> sizes = {14, 2, 3, 4, 5};
    vector<Criterion> criterion(sizes.size());

    srand(static_cast<unsigned int>(time(nullptr)));

    for (int i = 0; i < sizes.size(); i++) {
        int n = sizes[i];
        criterion[i].size = n;

        vector<int> original_arr(n);

        for (int j = 0; j < n; j++) {
            original_arr[j] = rand() % 201 - 100;
        }

        cout << endl << "=== Размер массива: " << n << " ===" << endl;
        print_array(original_arr, "Исходный");

        vector<int> bubble_arr = original_arr;
        vector<int> selection_arr = original_arr;

        bubble_sort(
            bubble_arr,
            criterion[i].bubble_comp,
            criterion[i].bubble_swap
        );

        print_array(bubble_arr, "Пузырьковая");

        selection_sort(
            selection_arr,
            criterion[i].selection_comp,
            criterion[i].selection_swap
        );

        print_array(selection_arr, "Выбором");
    }

    cout << endl << endl << "=== Все значения ===" << endl;

    for (int i = 0; i < criterion.size(); i++) {
        cout << "Размер: " << criterion[i].size << endl;
        cout << "  Пузырьковая: сравнений="
             << criterion[i].bubble_comp
             << ", перестановок="
             << criterion[i].bubble_swap << endl;

        cout << "  Выбором:     сравнений="
             << criterion[i].selection_comp
             << ", перестановок="
             << criterion[i].selection_swap << endl << endl;
    }

    return 0;
}
