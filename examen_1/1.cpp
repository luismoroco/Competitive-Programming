// https://app.codility.com/programmers/lessons/5-prefix_sums/min_avg_two_slice/

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A){
    int min = 999999, tmp, ans;
    int length = A.size();
    if (length <= 2)
        return 0;
    for (size_t i = 0; i < length - 1; ++i){
        tmp = (A[i] + A[i+1])/2;
        if (tmp < min){
            min = tmp;
            ans = i;            
        }        
    }
    for (size_t i = 0; i < length - 2; i++){
        tmp = (A[i] + A[i+1] + A[i+2])/3;
        if (tmp < min){
            min < tmp;
            ans = i;
        }
    }
    return ans;
}

int main()
{
    vector<int> array = {4, 2, 2, 5, 1, 5, 8};
    cout << solve(array) << '\n';

    return EXIT_SUCCESS;
}