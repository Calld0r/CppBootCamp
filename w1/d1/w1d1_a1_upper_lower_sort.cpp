/*
    Write a program to return an array containing the values between two 8-bits unsigned integers IN DESCENDING
    ORDER EXCLUSIVE. The function takes 2 values (lower_value and upper_value), it shall determine the values in
    between, and then arrange the sequence in descending order excluding the upper and lower values.
    If the lower_value is greater than or equal the upper_value, return an array of 2 elements,
    both containing value = 0xFF
    
    Example:
    Input: lower_value=2 and upper_value=5 Output:
    Output Array=4,3 Output Array Size=2
*/

#include <iostream>

int main () {
    unsigned int lower_value, upper_value, arr_length;
    bool is_neg = false;
    std::cout << "Enter lower_value: ";
    std::cin >> lower_value;
    std::cout << "Enter upper_value: ";
    std::cin >> upper_value;

    if (lower_value > upper_value) {
        is_neg = true;
        arr_length = 2;
    } else {
        arr_length = upper_value - lower_value;
    }

    unsigned int num_arr[arr_length];

    if (is_neg) {
        for (int i = 0; i < arr_length; i++) {
            num_arr[i] = 0xFF;
        } 
    } else {
        for (int i = 0; i < arr_length-1; i++) {
            num_arr[i] = upper_value - 1;
            upper_value--;
        }
        arr_length--;
    }

    for(int i = 0; i < arr_length; i++) {
        std::cout << num_arr[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}