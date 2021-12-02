#include <bits/stdc++.h>
using namespace std;

/*
* El objetivo es encontrar el mayor número que se pueda obtener
* multiplicando dos números de esta secuencia. 
*
* 10
* 8 1 6 3 4 10 3 9 14 2 
*/

int main()
{
    vector<int> mtx;
    int n, x, m;
    cin >> n;
    m = n;
    while (n--)
    {
        cin >> x;
        mtx.push_back(x);
    }

    sort(mtx.begin(), mtx.end());
    cout << mtx[m - 1] * mtx[m - 2];

    return EXIT_SUCCESS;
}
