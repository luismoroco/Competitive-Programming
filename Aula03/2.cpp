#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> mtx;
    int n, x, prev = 0;
    cin >> n;

    mtx.push_back(prev);
    while (n--)
    {
        cin >> x;
        prev += x;
        mtx.push_back(prev);
    }

    for (auto i : mtx)
        cout << i << ' ';

    return EXIT_SUCCESS;
}