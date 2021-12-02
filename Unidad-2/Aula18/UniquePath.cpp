#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/unique-paths/

typedef vector<vector<int>> vii;
typedef vector<int> vi;

int uniquePaths(int m, int n){
    vii sol(n, vi(m, 1));
    for (size_t i = 0; i < n; ++i){
        for (size_t j = 0; j < m; ++j)
            sol[i][j] = sol[i - 1][j] + sol[i][j - 1];
    }
    
    return sol[n - 1][m - 1];
}


int main(int argc, char const *argv[])
{
    cout << uniquePaths(3, 7);

    return 0;
}
