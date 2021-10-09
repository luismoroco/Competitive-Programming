temp

2 

////////////////
#include <bits/stdc++.h>
using namespace std;
 
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
 
    int k, j, best = 0, sum;
    for (k = 0; k < n - a; ++k){
        sum = 0;
        for (j = 0; j < a; ++j){
            sum += array[k+j];
            best = max(best,sum);
        }
    }
 
    for (k = 0; k < n - b; ++k){
        sum = 0;
        for (j = 0; j < b; ++j){
            sum += array[k+j];
            best = max(best,sum);
        }
    }
 
    cout << best << "\n";
 
    /*
    int best = 0, sum = 0;
    for (int k = 0; k < n; k++) {
        sum = max(array[k],sum+array[k]);
        best = max(best,sum);
    }
    cout << best << "\n";
    */
 
    return EXIT_SUCCESS;
}
////////////////