/*
 * Title: Sorting and Algorithm Efficiency
 * Author: Alperen Alkan
 * ID: 21803216
 * Section: 3
 * Assignment: 1
 * Description: description of your code
 */

#ifndef CS202HW1_SORTING_H
#define CS202HW1_SORTING_H
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <stdio.h>

using namespace std;

class sorting {
public:

    void selectionSort(int *arr, const int size, int &compCount, int &moveCount);
    void mergeSort(int *arr, const int size, int &compCount, int &moveCount);
    void quickSort(int *arr, const int size, int &compCount, int &moveCount);
    void radixSort(int *arr, const int size);
    void swap(int &a, int &b, int &moveCount);
    int indexOfLargest( int *arr, const int size, int &compCount);
    void displayArray(const int *arr, const int size);
    void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
    void createAscendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
    void createDescendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
    void mergeSort(int *arr, int begIndex, int lastIndex, int &compCount, int &moveCount);
    void merge(int *arr,int begIndex,int midIndex, int lastIndex , int &compCount, int &moveCount);
    int getSize(int *arr);
    void quickSort(int *arr, int firstIndex, int lastIndex, int &compCount, int &moveCount);
    void partition(int *arr, int firstIndex, int lastIndex, int &pivotIndex, int &compCount, int &moveCount);
    int getInt(int i, int index);
    void radixSort(int *arr, int size, int length);
    int getLength(int nu);
    void performanceAnalysis();
private:
 };


#endif //CS202HW1_SORTING_H
