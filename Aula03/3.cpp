#include <bits/stdc++.h>
using namespace std;

int find(vector<int> &mtx)
{
    int i, total = 0, tmp = 0;
    for (auto i : mtx)
        total += i;

    for (i = 0; i < mtx.size(); ++i)
    {
        total -= mtx[i];
        if (tmp == total)
            return i - 1;
        tmp += i;
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> mtx = {1, 2, 3, 5, 7};
    cout << find(mtx) << '\n';

    return EXIT_SUCCESS;
}