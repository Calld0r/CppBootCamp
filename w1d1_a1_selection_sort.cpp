/*
    Write a program that use the selection sort algorithm to sort an integer array in ascending order (search for the
    selection sorting algorithm).
*/

#include<iostream>

void SelectionSort(int arr[], int size);

int main() {
    int arr[] = {12,102,28,4,203,8,78,2,321,57};
    int arr_elements = sizeof(arr) / sizeof(int);

    SelectionSort(arr, arr_elements);

    // print sorted array
    std::cout << "After selection sort: ";
    for(int i = 0; i < arr_elements; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
void SelectionSort(int arr[], int size) {
    int temp, min, index;
    bool match;
    
    // look at the first element of arr and assume this is the smallest until proven wrong
    //  size - 1 : last iterration not needed since it should already be sorted by then
    for(int i = 0; i < size-1; i++) {
        match = false;
        min = arr[i];
    // look at the second element of arr and iterrate over all elements looking for a element
    //  with larger value, if found, store this in the min variable
        for(int j = i+1; j < size; j++) {
            if(min > arr[j]) {
                min = arr[j];
                match = true;
                index = j;
            }
        }
    
    // If a smaller numer of the array was found switch places of the content of
    //  the arr[i] element and the element containing the smallest number, min.
        if(match) {
            temp = arr[i];
            arr[i] = min;
            arr[index] = temp;
        }
    }
}