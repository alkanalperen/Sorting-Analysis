/*
 * Title: Sorting and Algorithm Efficiency
 * Author: Alperen Alkan
 * ID: 21803216
 * Section: 3
 * Assignment: 1
 * Description: description of your code
 */

#include "sorting.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    int arr1[] =  { 12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
    int arr2[] =  { 12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
    int arr3[] =  { 12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
    int arr4[] =  { 12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
    int compCount = 0;
    int moveCount = 0;
    int size = (sizeof(arr1)/sizeof(*arr1));
    sorting s;
    cout << "SelectionSort "<<endl;
    s.selectionSort(arr1,size,compCount,moveCount);
    s.displayArray(arr1,size);
    cout <<"compCount is "<< compCount <<endl;
    cout <<"moveCount is "<< moveCount <<endl;
    cout <<"--------------"<<endl;
    compCount = 0;
    moveCount = 0;
    cout << "MergeSort "<<endl;
    s.mergeSort(arr2,size,compCount,moveCount);
    s.displayArray(arr2,size);
    cout <<"compCount is "<< compCount <<endl;
    cout <<"moveCount is "<< moveCount <<endl;
    cout <<"--------------"<<endl;
    compCount = 0;
    moveCount = 0;
    cout << "QuickSort "<<endl;
    s.quickSort(arr3,size,compCount,moveCount);
    s.displayArray(arr3,size);
    cout <<"compCount is "<< compCount <<endl;
    cout <<"moveCount is "<< moveCount <<endl;
    cout <<"--------------"<<endl;
    cout << "RadixSort "<<endl;
    s.radixSort(arr4,size);
    s.displayArray(arr4,size);
    cout <<"--------------"<<endl;

    s.performanceAnalysis();

    return 0;
}
