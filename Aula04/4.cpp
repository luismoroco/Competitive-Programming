#include <bits/stdc++.h>
using namespace std;

// Mayor suma de subarrays
// output : 18 

int main()
{
    int array[] = {1, -2, 3, 10, -4, 7, 2, -5};
    int n = 8, best = 0, sum = 0;

    for (int k = 0; k < n; k++) {
        sum = max(array[k],sum+array[k]);
        best = max(best,sum);
    }
    cout << best << '\n';

    return EXIT_SUCCESS;
}