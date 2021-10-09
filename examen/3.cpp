// https://cses.fi/problemset/task/1644

#include <bits/stdc++.h>
using namespace std;

/*
Input:
8 1 2
-1 3 -2 5 3 -5 2 2

Output:
8
*/
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, a, b, x, i = 0, nn;
    cin >> n >> a >> b;
    nn = n;
    int array[n];
 
    while (nn--){
        cin >> x;
        array[i] = x;
        ++i;
    }
 
    int best = 0, sum = 0, k, j;
    for (k = 0; k < n; k++) {
        sum = max(array[k],sum+array[k]);
        best = max(best,sum);
    }
    cout << best << '\n'; 

    /*
    int k, j, best = 0, sum;
    for (k = 0; k < n - a; ++k){
        sum = 0;
        for (j = 0; j < a; ++j){
            sum += array[k+j];
            best = max(best,sum);
        }
    }
    */
 
    best = 0, sum = 0;
    for (k = 0; k < n - b; ++k){
        sum = 0;
        for (j = 0; j < b; ++j){
            sum += array[k+j];
            best = max(best,sum);
        }
    }
    cout << best << "\n";
 
 
    return EXIT_SUCCESS;
}