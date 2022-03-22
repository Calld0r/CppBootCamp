/*
    Write a program that use the bubble sort algorithm to sort an integer array in ascending order (search for the
    bubble sorting algorithm).
*/

#include <iostream>

void BubbleSort(int arr[], int size);

int main () {
    int arr[] = {12,102,28,4,203,8,78,2,321,57};
    int arr_elements = sizeof(arr)/sizeof(int);

    BubbleSort(arr, arr_elements);

    std::cout << "After bubble sort: ";
    for(int i = 0; i < arr_elements; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

void BubbleSort(int arr[], int size) {
    int temp;
    for(int i = 1; i < size; i++) {
        for(int j = 0; j < size-i; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}