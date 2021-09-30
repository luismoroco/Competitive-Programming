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


    
    /*
    for (i = 0; i < n; i++)
    {
        left = i;
        rigthh = n - 1;
        while (left < rigthh)
        {
            tmp = array[i] + array[left] + array[rigthh];
            if (tmp == target)
            {
                cout << '[' << array[i] << ',' << array[left] << ',' << array[rigthh] << ']' << '\n';
                left++;
                rigthh--;
            }
            else if (tmp < target)
                left++;
            else
                rigthh--;
        }
    }
    */

    return EXIT_SUCCESS; 
}

/*
    int array[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int n = 8, ptr1, ptr2, i = 0, x, k = 3;
    vector<int> nx;

    ptr1 = i + 1;
    ptr2 = i + 2;

    for (;i != n - 2; ++i){
        x = max(array[i], max(array[ptr1], array[ptr2]));
        nx.push_back(x);
        ++ptr1; ++ptr2;
    }
    for (auto &v : nx) cout << v << ' ';
    
*/