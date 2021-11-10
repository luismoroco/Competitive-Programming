#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> x, int i, int j){
    
}

int maxIsland(vector<vector<int>> &grid){
    int m, n, i, j, ans = 0;
    m = grid.size(); n = grid[0].size();
    for (i = 0; i < m; ++i){
        for (j = 0; i < n; ++j){
            //if (grid[i][j])
               // ans = max(ans, dfs(grid, i, j));
        }
    }
}

int main(){
    vector<vector<int>> x = {{1,1,1},{1,1,0},{1,0,1}};
    maxIsland(x);

    return 1;
}