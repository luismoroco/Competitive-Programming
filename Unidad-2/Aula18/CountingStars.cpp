#include <bits/stdc++.h>
using namespace std;

// https://open.kattis.com/problems/countingstars

typedef vector<vector<pair<char, bool>>> iVvp;

int Fill(int m, int n, int i, int j, iVvp &grid)
{
    if(i < 0 || i >= m || j < 0 || j >= n) return 0;
    if(grid[i][j].second) return 0;

    grid[i][j].second = true;

    Fill(m, n, i, j+1, grid);
    Fill(m, n, i, j-1, grid);
    Fill(m, n, i+1, j, grid);
    Fill(m, n, i-1, j, grid);

    return 1;
}

void solve(iVvp &grid)
{
    int res(0);
    int m = grid.size();
    int n = grid[0].size();
    for (size_t i = 0; i < m; ++i){
        for (size_t j = 0; j < n; ++j)
            res += Fill(m, n, i, j, grid); 
    }
    cout << res << '\n';
}


int main(int argc, char const *argv[])
{
    int m, n, i, j, start = 0;
    char x;
    cin >> m >> n;
    iVvp grid;
    for (i = 0; i < m; ++i){
        vector<pair<char, bool>> col;
        for (j = 0; j < n; ++j){
            cin >> x;
            pair<int, bool> t;
            t.first = x;
            t.second = (x == '#');
            col.push_back(t);
        }
        grid.push_back(col);        
    }
    solve(grid);

    return 0;
}
