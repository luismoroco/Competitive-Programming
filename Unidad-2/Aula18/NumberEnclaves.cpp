#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-of-enclaves/

void DFS(int i,int j,vector<vector<int>>& grid)
{
    if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]!=1)
        return;

    grid[i][j]=2;
    DFS(i+1, j, grid);
    DFS(i-1, j, grid);
    DFS(i, j+1, grid);
    DFS(i, j-1, grid);
}

int numEnclaves(vector<vector<int>>& grid) {
    int res = 0;
    for (size_t i = 0; i < grid.size(); ++i){
        for (size_t j = 0; j < grid[0].size(); ++j){
            if (i == 0||i == grid.size() - 1||j == 0||j == grid[0].size() - 1){
                if (grid[i][j] == 1) DFS(i,j,grid);
            }
        }
    }

    for (size_t i = 0; i < grid.size(); ++i){
        for (size_t j = 0; j < grid[0].size(); ++j){
            if (grid[i][j]==1)++res;
        }
    }

    cout << res << '\n';
    return res;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> x = {{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
    numEnclaves(x);

    return 0;
}

