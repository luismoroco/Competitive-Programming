#include <bits/stdc++.h>
using namespace std;

// https://cses.fi/problemset/task/1077
// Costo deslizante

int main()
{
    int ar[] = {2, 4, 3, 5, 8, 1, 2, 1};
    int n = 8, k = 3, i = 0, j, x, y;

    for (; i <= n - k; ++i){
        x = i + 1; y = i + 2;
        cout << '[' << ar[i] << ' ' << ar[x] << ' ' << ar[y] << ']' << '\n'; 

    }

    return EXIT_SUCCESS;
}