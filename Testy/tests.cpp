#include <gtest/gtest.h>
#include <algorithm>
#include <random>
#include <vector>
#include "MergeSort.h"

// 1. Tablica już posortowana rosnąco
TEST(MergeSortTest, AlreadySorted) {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    std::vector<int> expected = {1, 2, 3, 4, 5};
    MergeSort<int>::sort(arr);
    EXPECT_EQ(arr, expected);
}

// 2. Tablica posortowana w odwrotnej kolejności
TEST(MergeSortTest, ReverseSorted) {
    std::vector<int> arr = {5, 4, 3, 2, 1};
    std::vector<int> expected = {1, 2, 3, 4, 5};
    MergeSort<int>::sort(arr);
    EXPECT_EQ(arr, expected);
}

// 3. Losowa tablica liczb
TEST(MergeSortTest, RandomArray) {
    std::vector<int> arr = {42, 7, 19, 3, 88, 12, 5};
    std::vector<int> expected = arr;
    std::sort(expected.begin(), expected.end());
    MergeSort<int>::sort(arr);
    EXPECT_EQ(arr, expected);
}

// 4. Tylko liczby ujemne
TEST(MergeSortTest, OnlyNegative) {
    std::vector<int> arr = {-5, -100, -1, -42, -17};
    std::vector<int> expected = {-100, -42, -17, -5, -1};
    MergeSort<int>::sort(arr);
    EXPECT_EQ(arr, expected);
}

// 5. Liczby ujemne i dodatnie
TEST(MergeSortTest, NegativeAndPositive) {
    std::vector<int> arr = {15, -30, 7, -1, 0, 22};
    std::vector<int> expected = {-30, -1, 0, 7, 15, 22};
    MergeSort<int>::sort(arr);
    EXPECT_EQ(arr, expected);
}

// 6. Pusta tablica (bez rzucania wyjątku)
TEST(MergeSortTest, EmptyArray) {
    std::vector<int> arr = {};
    EXPECT_NO_THROW(MergeSort<int>::sort(arr));
    EXPECT_TRUE(arr.empty());
}

// 7. Tablica jednoelementowa
TEST(MergeSortTest, SingleElement) {
    std::vector<int> arr = {42};
    MergeSort<int>::sort(arr);
    EXPECT_EQ(arr, std::vector<int>({42}));
}

// 8. Tablica z duplikatami
TEST(MergeSortTest, Duplicates) {
    std::vector<int> arr = {8, 3, 8, 1, 3, 8, 1};
    std::vector<int> expected = {1, 1, 3, 3, 8, 8, 8};
    MergeSort<int>::sort(arr);
    EXPECT_EQ(arr, expected);
}

// 9. Tablica ujemna z duplikatami
TEST(MergeSortTest, NegativeWithDuplicates) {
    std::vector<int> arr = {-4, -10, -4, -1, -10, -1};
    std::vector<int> expected = {-10, -10, -4, -4, -1, -1};
    MergeSort<int>::sort(arr);
    EXPECT_EQ(arr, expected);
}

// 10. Liczby ujemne, dodatnie oraz duplikaty
TEST(MergeSortTest, NegativePositiveDuplicates) {
    std::vector<int> arr = {0, -5, 12, -5, 0, 12, -1};
    std::vector<int> expected = {-5, -5, -1, 0, 0, 12, 12};
    MergeSort<int>::sort(arr);
    EXPECT_EQ(arr, expected);
}

// 11. Dwa elementy w kolejności rosnącej
TEST(MergeSortTest, TwoElementsAscending) {
    std::vector<int> arr = {10, 25};
    std::vector<int> expected = {10, 25};
    MergeSort<int>::sort(arr);
    EXPECT_EQ(arr, expected);
}

// 12. Duża tablica (>100 elementów)
TEST(MergeSortTest, LargeArrayOver100) {
    std::vector<int> arr(150);
    for (int i = 0; i < 150; ++i) {
        arr[i] = 150 - i;
    }
    std::vector<int> expected = arr;
    std::sort(expected.begin(), expected.end());
    MergeSort<int>::sort(arr);
    EXPECT_EQ(arr, expected);
}

// 13. Duża tablica (>100 elementów) z ujemnymi, dodatnimi i duplikatami
TEST(MergeSortTest, LargeArrayMixedWithDuplicates) {
    std::mt19937 gen(12345);
    std::uniform_int_distribution<int> dist(-25, 25);
    std::vector<int> arr(200);
    for (int& x : arr) {
        x = dist(gen);
    }
    std::vector<int> expected = arr;
    std::sort(expected.begin(), expected.end());
    MergeSort<int>::sort(arr);
    EXPECT_EQ(arr, expected);
}