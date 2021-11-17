#include <bits/stdc++.h>
using namespace std;

int min(int x, int y, int z)
{
    if (x < y) return max(x, z);
    else return max(y, z);
}

int solve(vector<vector<int>> &grid, int m, int n)
{
    if (n < 0 || m < 0) return -1;
    else if (m == 0 && n == 0) return grid[m][n];
    else return grid[m][n] + min(solve(grid, m-1, n-1), solve(grid, m-1, n), solve(grid, m, n-1));
}

int main()
{
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}};
    cout << solve(grid, 2, 1);

    return 0;
}