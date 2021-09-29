#include <bits/stdc++.h>
using namespace std;

/*
* output esperado = [3, 3, 5, 5, 6, 7] 
*/

int main()
{
    int array[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int n = 8, ptr1, ptr2, i = 0, x;
    vector<int> nx;
    
    ptr1 = i + 1;
    ptr2 = i + 2;

    for (;i != n - 2; ++i){
        x = max(array[i], max(array[ptr1], array[ptr2]));
        nx.push_back(x);
        ++ptr1; ++ptr2;
    }
    
    for (auto &v : nx) cout << v << ' ';

    return EXIT_SUCCESS;
}