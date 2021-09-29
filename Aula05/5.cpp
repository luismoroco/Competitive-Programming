#include <bits/stdc++.h>
using namespace std;

/*
* output esperado = sum[4, 1, 5] = 10   
*/

int main()
{
    int array[] = {2, 3, 4, 1, 5};
    int n = 5, k = 3, best = 0, sum = 0;

    for (int i = 0; i < k; i++) 
        best += array[i];

    sum = best;
    for (int i = k; i < n; i++){
        sum += array[i] - array[i - k];
        best = max(best, sum);
    }
    
    cout << best << '\n';

    return EXIT_SUCCESS;
}