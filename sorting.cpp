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

void sorting::swap(int &a, int &b, int &moveCount) {
    int temp = a;
    a = b;
    b = temp;
    moveCount = moveCount+3;
}
int sorting::indexOfLargest(int *arr, const int size, int &compCount) {
    int index = 0;
    for( int i = 1; i < size; i++){
        if( arr[index] < arr[i])
            index = i;
        compCount++;
    }
    return index;
}
void sorting::selectionSort(int *arr, const int size, int &compCount, int &moveCount) {
    for ( int last = size - 1; last > 0; last--){
        int largest = indexOfLargest(arr,last+1,compCount);
        swap(arr[largest],arr[last],moveCount);
    }
}
void sorting::displayArray(const int *arr, const int size) {
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout <<endl;
}
void sorting::mergeSort(int *arr, const int size, int &compCount, int &moveCount) {
    mergeSort(arr,0,size-1,compCount,moveCount);
}
void sorting::mergeSort(int *arr, int begIndex, int lastIndex, int &compCount, int &moveCount) {
    if ( begIndex < lastIndex){
        int mid = (begIndex + lastIndex) / 2;
        mergeSort(arr,begIndex,mid,compCount,moveCount);
        mergeSort(arr,mid+1,lastIndex,compCount,moveCount);
        merge(arr,begIndex,mid,lastIndex,compCount,moveCount);
    }
}
void sorting::merge(int *arr, int begIndex, int midIndex, int lastIndex, int &compCount, int &moveCount) {
    int tempArray[lastIndex+1]; 	// temporary array
    int first1 = begIndex; 	// beginning of first subarray
    int last1 = midIndex; 		// end of first subarray
    int first2 = midIndex + 1;	// beginning of second subarray
    int last2 = lastIndex;		// end of second subarray
    int index = first1; // next available location in tempArray

    for ( ; (first1 <= last1) && (first2 <= last2); ++index) {
        compCount++;
        if (arr[first1] < arr[first2]) {
            moveCount++;
            tempArray[index] = arr[first1];
            ++first1;
        }
        else {
            moveCount++;
            tempArray[index] = arr[first2];
            ++first2;
        }
    }
    // finish off the first subarray, if necessary
    for (; first1 <= last1; ++first1, ++index) {
        moveCount++;
        tempArray[index] = arr[first1];
    }

    // finish off the second subarray, if necessary
    for (; first2 <= last2; ++first2, ++index) {
        moveCount++;
        tempArray[index] = arr[first2];
    }

    // copy the result back into the original array
    for (index = begIndex; index <= lastIndex; ++index) {
        moveCount++;
        arr[index] = tempArray[index];
    }
}  // end merge
void sorting::createRandomArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++){
        int nu = rand() % 1000;
        arr1[i]=nu;
        arr2[i]=nu;
        arr3[i]=nu;
        arr4[i]=nu;
    }
}
void sorting::createAscendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size) {
    srand(time(NULL));
    int multiplier = 0;
    for (int i = 0; i < size; i++){
        int nu = (rand() % 10) + multiplier;
        multiplier = multiplier + 10;
        arr1[i]=nu;
        arr2[i]=nu;
        arr3[i]=nu;
        arr4[i]=nu;
    }
}
void sorting::createDescendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size) {
    srand(time(NULL));
    int increment = 10000000;
    for (int i = 0; i < size; i++){
        int nu = (rand() % 10) + increment;
        increment = increment - 10;
        arr1[i]=nu;
        arr2[i]=nu;
        arr3[i]=nu;
        arr4[i]=nu;
    }
}
void sorting::quickSort(int *arr, const int size, int &compCount, int &moveCount) {
    quickSort(arr,0,size-1,compCount,moveCount);
}
void sorting::quickSort(int *arr, int firstIndex, int lastIndex, int &compCount, int &moveCount) {
    int pivotIndex;
    if(firstIndex < lastIndex) {
        partition(arr, firstIndex, lastIndex, pivotIndex,compCount,moveCount);
        quickSort(arr, firstIndex, pivotIndex - 1, compCount, moveCount);
        quickSort(arr, pivotIndex + 1, lastIndex, compCount, moveCount);
    }
}
void sorting::partition(int *arr, int firstIndex, int lastIndex, int &pivotIndex, int &compCount, int &moveCount) {
    int pivot = arr[firstIndex];
    moveCount++;
    int lastS1 = firstIndex;           // index of last item in S1
    int firstUnknown = firstIndex + 1; // index of first item in unknown
    // move one item at a time until unknown region is empty
    for (  ; firstUnknown <= lastIndex; ++firstUnknown) {
        // Invariant: theArray[first+1..lastS1] < pivot
        //            theArray[lastS1+1..firstUnknown-1] >= pivot
        // move item from unknown to proper region
        compCount++;
        if (arr[firstUnknown] < pivot) {// belongs to S1
            ++lastS1;
            swap(arr[firstUnknown], arr[lastS1],moveCount);
        }	// else belongs to S2
    }
    // place pivot in proper position and mark its location
    swap(arr[firstIndex], arr[lastS1],moveCount);
    pivotIndex = lastS1;

}
void sorting::radixSort(int *arr, const int size) {
    int max = 0;
    for(int i = 0; i < size; i++){
        if(arr[i]>max)
            max = arr[i];
    }
    radixSort(arr,size,getLength(max));
}
void sorting::radixSort(int *arr, int size, int length ) {

    for (int j = length; 0 <= j;j--) {
        //Initialize 10 groups to empty
        int group[10][size];
        for(int i = 0; i < 10;i++){
            for(int j = 0; j < size; j++)
                group[i][j]=0;
        }
        // Initialize a counter for each group to 0
        int counter[10]={};
        for (int i = 0; i < size; i++) {
            //k = jth digit of theArray[i]
            int k = getInt(arr[i],length-j);
            //Place theArray[i] at the end of group k
            group[k][counter[k]] = arr[i];
            //Increase kth counter by 1
            counter[k] = counter[k]+1;
        }
        //Replace the items in theArray with all the items in
        //group 0, followed by all the items in group 1, and so on.
        int index = 0;
        for(int i = 0; i < 10;i++){
            for(int k = 0; k < size; k++) {
                    if(group[i][k]!=0) {
                        arr[index] = group[i][k];
                        index++;
                    }
            }
        }

    }
}
int sorting::getInt( int i, int index) {
    return (i / (int) (pow(10.0,(double)index))) % 10;
}
int sorting::getLength(int nu)
{
    int ct=0;
    while(nu)
    {
        nu=nu/10;
        ct++;
    }
    return ct;
}

void sorting::performanceAnalysis() {
    int sizes[7]= { 6000, 10000, 14000, 18000, 22000, 26000, 30000};
    int selectionComp[21];
    int selectionMove[21];
    double selectionTime[21];
    int mergesortComp[21];
    int mergesortMove[21];
    double mergesortTime[21];
    int quickComp[21];
    int quickMove[21];
    double quickTime[21];
    double radixTime[21];
    for(int i = 0; i < 7;i++) {
        int *arr1 = new int[sizes[i]];
        int *arr2 = new int[sizes[i]];
        int *arr3 = new int[sizes[i]];
        int *arr4 = new int[sizes[i]];
        sorting s;
        //clock
        double duration;
        clock_t startTime = clock();
        //random
        createRandomArrays(arr1, arr2, arr3, arr4, sizes[i]);
        //selection
        int compCount = 0;
        int moveCount = 0;
        startTime = clock();
        s.selectionSort(arr1,sizes[i],compCount,moveCount);
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        selectionComp[i] = compCount;
        selectionMove[i] = moveCount;
        selectionTime[i] = duration;
        //merge
        compCount = 0;
        moveCount = 0;
        startTime = clock();
        s.mergeSort(arr2,sizes[i],compCount,moveCount);
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        mergesortComp[i] = compCount;
        mergesortMove[i] = moveCount;
        mergesortTime[i] = duration;
        //quick
        compCount = 0;
        moveCount = 0;
        startTime = clock();
        s.quickSort(arr3,sizes[i],compCount,moveCount);
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        quickComp[i] = compCount;
        quickMove[i] = moveCount;
        quickTime[i] = duration;
        //radix
        startTime = clock();
        s.radixSort(arr4,sizes[i]);
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        radixTime[i] = duration;
        //ascending 7
        createAscendingArrays(arr1, arr2, arr3, arr4, sizes[i]);
        //selection
        compCount = 0;
        moveCount = 0;
        startTime = clock();
        s.selectionSort(arr1,sizes[i],compCount,moveCount);
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        selectionComp[i+7] = compCount;
        selectionMove[i+7] = moveCount;
        selectionTime[i+7] = duration;        //merge
        s.mergeSort(arr2,sizes[i],compCount,moveCount);
        //merge
        compCount = 0;
        moveCount = 0;
        startTime = clock();
        s.mergeSort(arr2,sizes[i],compCount,moveCount);
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        mergesortComp[i+7] = compCount;
        mergesortMove[i+7] = moveCount;
        mergesortTime[i+7] = duration;
        //quick
        compCount = 0;
        moveCount = 0;
        startTime = clock();
        s.quickSort(arr3,sizes[i],compCount,moveCount);
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        quickComp[i+7] = compCount;
        quickMove[i+7] = moveCount;
        quickTime[i+7] = duration;
        //radix
        startTime = clock();
        s.radixSort(arr4,sizes[i]);
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        radixTime[i+7] = duration;
        //descending 14
        createDescendingArrays(arr1, arr2, arr3, arr4, sizes[i]);
        //selection
        compCount = 0;
        moveCount = 0;
        startTime = clock();
        s.selectionSort(arr1,sizes[i],compCount,moveCount);
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        selectionComp[i+14] = compCount;
        selectionMove[i+14] = moveCount;
        selectionTime[i+14] = duration;
        //merge
        compCount = 0;
        moveCount = 0;
        startTime = clock();
        s.mergeSort(arr2,sizes[i],compCount,moveCount);
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        mergesortComp[i+14] = compCount;
        mergesortMove[i+14] = moveCount;
        mergesortTime[i+14] = duration;
        //quick
        compCount = 0;
        moveCount = 0;
        startTime = clock();
        s.quickSort(arr3,sizes[i],compCount,moveCount);
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        quickComp[i+14] = compCount;
        quickMove[i+14] = moveCount;
        quickTime[i+14] = duration;
        //radix
        startTime = clock();
        s.radixSort(arr4,sizes[i]);
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        radixTime[i+14] = duration;
    }
    cout <<"-----------------------------------------------------------------------------------"<<endl;
    cout <<"RANDOM NUMBERS"<<endl;
    cout <<"Analysis of Selection Sort"<<endl;
    printf("%-20s%-20s%-20s%-20s", "ArraySize","Elapsed time","compCount","moveCount");
    for(int i = 0;i < 7; i++){
        cout <<endl;
        printf("%-20d%-20f%-20d%-20d", sizes[i],selectionTime[i],selectionComp[i],selectionMove[i]);
    }
    cout <<endl;
    cout <<"-----------------------------------------------------------------------------------"<<endl;
    cout <<"RANDOM NUMBERS"<<endl;
    cout <<"Analysis of Merge Sort"<<endl;
    printf("%-20s%-20s%-20s%-20s", "ArraySize","Elapsed time","compCount","moveCount");
    for(int i = 0;i < 7; i++){
        cout <<endl;
        printf("%-20d%-20f%-20d%-20d",sizes[i], mergesortTime[i],mergesortComp[i],mergesortMove[i]);
    }
    cout <<endl;
    cout <<"-----------------------------------------------------------------------------------"<<endl;
    cout <<"RANDOM NUMBERS"<<endl;
    cout <<"Analysis of Quick Sort"<<endl;
    printf("%-20s%-20s%-20s%-20s", "ArraySize","Elapsed time","compCount","moveCount");
    for(int i = 0;i < 7; i++){
        cout <<endl;
        printf("%-20d%-20f%-20d%-20d",sizes[i],quickTime[i],quickComp[i],quickMove[i]);
    }
    cout <<endl;
    cout <<"-----------------------------------------------------------------------------------"<<endl;
    cout <<"RANDOM NUMBERS"<<endl;
    cout <<"Analysis of Radix Sort"<<endl;
    printf("%-20s%-20s", "ArraySize","Elapsed time");
    for(int i = 0;i < 7; i++){
        cout <<endl;
        printf("%-20d%-20f",sizes[i],radixTime[i]);
    }
    cout <<endl;
    cout <<"-----------------------------------------------------------------------------------"<<endl;
    cout <<"ASCENDING NUMBERS"<<endl;
    cout <<"Analysis of Selection Sort"<<endl;
    printf("%-20s%-20s%-20s%-20s", "ArraySize","Elapsed time","compCount","moveCount");
    for(int i = 0;i < 7; i++){
        cout <<endl;
        printf("%-20d%-20f%-20d%-20d", sizes[i],selectionTime[i+7],selectionComp[i+7],selectionMove[i+7]);
    }
    cout <<endl;
    cout <<"-----------------------------------------------------------------------------------"<<endl;
    cout <<"ASCENDING NUMBERS"<<endl;
    cout <<"Analysis of Merge Sort"<<endl;
    printf("%-20s%-20s%-20s%-20s", "ArraySize","Elapsed time","compCount","moveCount");
    for(int i = 0;i < 7; i++){
        cout <<endl;
        printf("%-20d%-20f%-20d%-20d",sizes[i], mergesortTime[i+7],mergesortComp[i+7],mergesortMove[i+7]);
    }
    cout <<endl;
    cout <<"-----------------------------------------------------------------------------------"<<endl;
    cout <<"ASCENDING NUMBERS"<<endl;
    cout <<"Analysis of Quick Sort"<<endl;
    printf("%-20s%-20s%-20s%-20s", "ArraySize","Elapsed time","compCount","moveCount");
    for(int i = 0;i < 7; i++){
        cout <<endl;
        printf("%-20d%-20f%-20d%-20d",sizes[i],quickTime[i+7],quickComp[i+7],quickMove[i+7]);
    }
    cout <<endl;
    cout <<"-----------------------------------------------------------------------------------"<<endl;
    cout <<"ASCENDING NUMBERS"<<endl;
    cout <<"Analysis of Radix Sort"<<endl;
    printf("%-20s%-20s", "ArraySize","Elapsed time");
    for(int i = 0;i < 7; i++){
        cout <<endl;
        printf("%-20d%-20f",sizes[i],radixTime[i+7]);
    }
    cout <<endl;
    cout <<"-----------------------------------------------------------------------------------"<<endl;
    cout <<"DESCENDING NUMBERS"<<endl;
    cout <<"Analysis of Selection Sort"<<endl;
    printf("%-20s%-20s%-20s%-20s", "ArraySize","Elapsed time","compCount","moveCount");
    for(int i = 0;i < 7; i++){
        cout <<endl;
        printf("%-20d%-20f%-20d%-20d", sizes[i],selectionTime[i+14],selectionComp[i+14],selectionMove[i+14]);
    }
    cout <<endl;
    cout <<"-----------------------------------------------------------------------------------"<<endl;
    cout <<"DESCENDING NUMBERS"<<endl;
    cout <<"Analysis of Merge Sort"<<endl;
    printf("%-20s%-20s%-20s%-20s", "ArraySize","Elapsed time","compCount","moveCount");
    for(int i = 0;i < 7; i++){
        cout <<endl;
        printf("%-20d%-20f%-20d%-20d",sizes[i], mergesortTime[i+14],mergesortComp[i+14],mergesortMove[i+14]);
    }
    cout <<endl;
    cout <<"-----------------------------------------------------------------------------------"<<endl;
    cout <<"DESCENDING NUMBERS"<<endl;
    cout <<"Analysis of Quick Sort"<<endl;
    printf("%-20s%-20s%-20s%-20s", "ArraySize","Elapsed time","compCount","moveCount");
    for(int i = 0;i < 7; i++){
        cout <<endl;
        printf("%-20d%-20f%-20d%-20d",sizes[i],quickTime[i+14],quickComp[i+14],quickMove[i+14]);
    }
    cout <<endl;
    cout <<"-----------------------------------------------------------------------------------"<<endl;
    cout <<"DESCENDING NUMBERS"<<endl;
    cout <<"Analysis of Radix Sort"<<endl;
    printf("%-20s%-20s", "ArraySize","Elapsed time");
    for(int i = 0;i < 7; i++){
        cout <<endl;
        printf("%-20d%-20f",sizes[i],radixTime[i+14]);
    }



}

