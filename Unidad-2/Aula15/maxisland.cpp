#include <bits/stdc++.h>
using namespace std;

int n, m;
int trav(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || j < 0 || i >= n || j >= m || !grid[i][j]) return 0;
        grid[i][j] = 0;
        return 1 + trav(i-1, j, grid) + trav(i, j-1, grid) + trav(i+1, j, grid) + trav(i, j+1, grid);
}

int maxIsland(vector<vector<int>> &grid){
    int m, n, i, j, ans = 0;
    m = grid.size(); n = grid[0].size();
    for (i = 0; i < m; i++){
        for (j = 0; i < n; j++){
            if (grid[i][j] == 1){
                ans = max(ans, trav(i, j, grid));
            }
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> x = {{1,1,1},{1,1,0},{1,0,1}};
    cout << maxIsland(x);

    return 1;
}
