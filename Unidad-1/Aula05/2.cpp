#include <bits/stdc++.h>
using namespace std;

// Maximum Subarray Sum

int main()
{
    int array[] = {-1, 3, -2, 5, 3, -5, 2, 2};
    int n = 8, sum = 0, best =0;

    for (int k = 0; k < n; k++) {
        sum = max(array[k],sum+array[k]);
        best = max(best,sum);
    }
    cout << best << '\n';

    return EXIT_SUCCESS;
}