#include <bits/stdc++.h>
using namespace std;

int climbStairs(int n) {
    if (n < 3) return n;

    int x = 1, y = 2, res;
    for (size_t i = 3; i <= n; ++i)
    {
        res = x + y;
        x = y;
        y = res;
    }

    return res; 
    
}

int main()
{
    cout << climbStairs(4);
    return 0;
}