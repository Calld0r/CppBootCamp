/*
    Write a program that use the bubble sort algorithm to sort an integer array in ascending order (search for the
    bubble sorting algorithm).
*/

#include <iostream>

void BubbleSort(int arr[], int size);

int main () {
    int arr[] = {12,102,28,4,203,8,78,2,321,57};
    int arr_elements = sizeof(arr) / sizeof(int);

    BubbleSort(arr, arr_elements);

    // print sorted array
    std::cout << "After bubble sort: ";
    for(int i = 0; i < arr_elements; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

void BubbleSort(int arr[], int size) {
    int temp;

    //  i = 1 : last iterration not needed since it should already be sorted by then
    for(int i = 1; i < size; i++) {
        // loop through the array and compare the numbers next to each other
        //  if the element with the higher index is larger, swap them.
        //   decrese the iterration each time as we don't need to go through the
        //    sorted elements again
        for(int j = 0; j < size-i; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}