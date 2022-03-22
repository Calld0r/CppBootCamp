/*
    Write a program that use the selection sort algorithm to sort an integer array in ascending order (search for the
    selection sorting algorithm).
*/

#include<iostream>

void SelectionSort(int arr[], int size);

int main()
{
    int arr[] = {12,102,28,4,203,8,78,2,321,57};
    int arr_elements = sizeof(arr)/sizeof(int);

    SelectionSort(arr, arr_elements);
    std::cout << "After selection sort: ";

    for(int i = 0; i < arr_elements; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
void SelectionSort(int arr[], int size)
{
    int temp, lower, current, index;

    for(int i=0; i<size-1; i++) {
        current=0;
        lower = arr[i];
        for(int j=i+1; j<size; j++) {
            if(lower > arr[j]) {
                lower = arr[j];
                current++;
                index = j;
            }
        }
        if(current!=0) {
            temp = arr[i];
            arr[i] = lower;
            arr[index] = temp;
        }
    }
}