#include <bits/stdc++.h>
using namespace std;

// Given an integer array nums, return all the 
// triplets [nums[i], nums[j], nums[k]] such  that i != j,
// i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

int main(){

    int array[] = {-1, 0, 1, 2, -1, -4};
    int n = 5, ptr1, ptr2, i = 0, x, target = 0;

    if (n < 3){
        cout << "[]" << '\n';
        exit(1);
    }
    else if (n >= 3){
        ptr1 = i + 1;
        ptr2 = i + 2;

        for (;i != n - 2; ++i){
            x = array[i] + array[ptr1] + array[ptr2];
                if (x == target){
                    cout << '[' << array[i] << ',' << array[ptr1] << ',' << array[ptr2] << ']' << '\n';
                }
            ++ptr1; ++ptr2;
        }
    }

    return EXIT_SUCCESS; 
}