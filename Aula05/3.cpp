#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> array = {-4, -3, 1, 2, 3};
    for (auto &v : array)
        v = v * v;
    sort(array.begin(), array.end());
    for (auto v : array)
        cout << v << ' ';

    return EXIT_SUCCESS;
}