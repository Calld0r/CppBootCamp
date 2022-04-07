/*
    Write a program that removes the repeated number of an input sorted array and return a new array without
    the repeated numbers. The function shall return error if the size of the input array is ZERO. The function takes
    four inputs:
    a. Old array.
    b. Old array size.
    c. New array (empty array).
    d. The size of the new array after fill it in the function.
    int removeDuplicates(int arr_old[], int n_old, int arr_new[], int *n_new)

        Example:
        arr1 = {1,2,3,3,3,4,4,5,5,5} arr2 = {1,2,3,4,5}
*/

#include <iostream>

int removeDuplicates(int arr_old[], int n_old, int arr_new[], int *n_new);

void printArr(int arr[], int size);

int main () {
    int arr_old[] = {1,2,3,3,3,4,4,5,5,5}, n_old = sizeof(arr_old)/sizeof(int);
    int arr_new[n_old], *n_new = new int;
    
    if (sizeof(arr_old)) {
        removeDuplicates(arr_old, n_old, arr_new, n_new);

        std::cout << "arr_old[] = { ";
        printArr(arr_old, n_old);
        std::cout << "}" << std::endl;

        std::cout << "arr_new[] = { ";
        printArr(arr_new, *n_new);
        std::cout << "}" << std::endl;

    } else std::cout << "error: ZERO array input!" << std::endl;

    delete n_new;
    n_new = nullptr;
    return 0;
}

int removeDuplicates(int arr_old[], int n_old, int arr_new[], int *n_new) {
    for (int i = 0; i < n_old; i++) {
        if (!(arr_old[i] == arr_old[i+1])) {
            arr_new[*n_new] = arr_old[i];
            (*n_new)++;
        }
    }
    return 0;
}

void printArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
    }
}