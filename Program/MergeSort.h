#ifndef MERGESORT_H
#define MERGESORT_H
/**
 * @file MergeSort.h
 * @brief Implementacja szablonu klasy sortowania przez scalanie (MergeSort).
 */
#include <vector>

/**
 * @class MergeSort
 * @brief Szablon klasy realizującej algorytm sortowania przez scalanie.
 * @tparam T Typ danych przechowywanych w sortowanym wektorze (np. int, double).
 */
template <typename T>
class MergeSort {
public:
    /**
 * @brief Główna metoda sortująca wektor rosnąco.
 * @param arr Referencja do wektora, który ma zostać posortowany.
 */
    static void sort(std::vector<T>& arr) {
        if (arr.size() <= 1) return;
        mergeSortRecursive(arr, 0, arr.size() - 1);
    }

private:
    /**
 * @brief Rekurencyjnie dzieli tablicę na dwie połowy i wywołuje ich scalanie.
 * @param arr Referencja do sortowanego wektora.
 * @param left Indeks lewego krańca podtablicy.
 * @param right Indeks prawego krańca podtablicy.
 */
    static void mergeSortRecursive(std::vector<T>& arr, int left, int right) {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        
        mergeSortRecursive(arr, left, mid);
        mergeSortRecursive(arr, mid + 1, right);
        
        merge(arr, left, mid, right);
    }

    /**
 * @brief Scala dwie posortowane podtablice w jedną posortowaną całość.
 * @param arr Referencja do sortowanego wektora.
 * @param left Indeks początku lewej podtablicy.
 * @param mid Indeks środka dzielącego podtablice.
 * @param right Indeks końca prawej podtablicy.
 */
    static void merge(std::vector<T>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        std::vector<T> L(n1);
        std::vector<T> R(n2);

        for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
        for (int j = 0; j < n2; ++j) R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;
        
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }
        
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
};

#endif