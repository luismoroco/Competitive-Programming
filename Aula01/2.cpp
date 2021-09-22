#include <bits/stdc++.h>
using namespace std;
int i, j;

void findBucle(vector<int> &mtx)
{
    for ( i = 0; i < mtx.size(); ++i)
    {
        bool flag = false;
        vector<int> anwr;

        for ( j = 0; j < i; ++j)
        {
            anwr.push_back(mtx[j]);

            if (mtx[i] == mtx[j])
            {
                anwr.push_back(mtx[j]);
                flag = true;
                for (auto v : anwr) cout << v << ' ';
                break;
            }
        }
    }
}

int main()
{
    vector<int> mtx = {9, 1, 2, 3, 2, 3, 2};
    findBucle(mtx);

    return EXIT_SUCCESS;
}
