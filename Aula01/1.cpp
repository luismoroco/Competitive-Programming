#include <bits/stdc++.h>
using namespace std;

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
