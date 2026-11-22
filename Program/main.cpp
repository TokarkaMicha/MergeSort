#include <iostream>
#include <vector>
#include "MergeSort.h"

template <typename T>
void printVector(const std::string& label, const std::vector<T>& arr) {
    std::cout << label << ": ";
    for (const auto& el : arr) {
        std::cout << el << " ";
    }
    std::cout << "\n";
}

int main() {
    // Instancja 1: int
    std::vector<int> intArr = {38, 27, 43, 3, 9, 82, 10};
    printVector("int przed", intArr);
    MergeSort<int>::sort(intArr);
    printVector("int po   ", intArr);

    std::cout << "\n";

    // Instancja 2: double
    std::vector<double> doubleArr = {12.5, -3.14, 0.0, 8.75, -15.2, 4.5};
    printVector("double przed", doubleArr);
    MergeSort<double>::sort(doubleArr);
    printVector("double po   ", doubleArr);

    return 0;
}