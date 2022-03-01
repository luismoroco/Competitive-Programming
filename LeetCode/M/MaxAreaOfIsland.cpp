#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &grid, int i, int j, int &tam) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return;
    if (grid[i][j] == 0) return;
    grid[i][j] = 0;
    ++tam;
    dfs(grid, i-1, j, tam);
    dfs(grid, i, j+1, tam);
    dfs(grid, i+1, j, tam);
    dfs(grid, i, j-1, tam);
}

int maxAreaOfIsland(vector<vector<int>> &grid) {
    int res = 0; 
    for (int i = 0; i < grid.size(); ++i){
        for (int j = 0; j < grid[0].size(); ++j){
            if (grid[i][j] == 1){
                int tam = 0; 
                dfs(grid, i, j, tam);
                res = max(res, tam);
            }
        }
    }

    return res;
}

int main(int argc, char const *argv[]) {

    vector<vector<int>> x = {{0,0,1,0,0,0,0,1,0,0,0,0,0}
                            ,{0,0,0,0,0,0,0,1,1,1,0,0,0}
                            ,{0,1,1,0,1,0,0,0,0,0,0,0,0}
                            ,{0,1,0,0,1,1,0,0,1,0,1,0,0}
                            ,{0,1,0,0,1,1,0,0,1,1,1,0,0}
                            ,{0,0,0,0,0,0,0,0,0,0,1,0,0}
                            ,{0,0,0,0,0,0,0,1,1,1,0,0,0}
                            ,{0,0,0,0,0,0,0,1,1,0,0,0,0}};
    
    cout << (maxAreaOfIsland(x)) << '\n';

    return 0;
}
