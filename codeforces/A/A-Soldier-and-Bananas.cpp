#include <bits/stdc++.h>

using namespace std;
 
int main()
{
    int k, n, w, i, p = 0;
    cin >> k >> n >> w;
    
    for (i = 1; i <= w; ++i){
        p += k*i;
    }
    
    if (p > n) cout << p-n << '\n';
    else cout << 0 << '\n';
    
    return EXIT_SUCCESS;
}