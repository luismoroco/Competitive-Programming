#include <bits/stdc++.h>

using namespace std;

bool bfs(vector<vector<int>> &grid, int i, int j) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return false;
    if (grid[i][j]) return true;
    grid[i][j] = 1;

    return (bfs(grid, i-1, j) && bfs(grid, i, j+1) 
         && bfs(grid, i+1, j) && bfs(grid, i, j-1));
}

int closedIsland(vector<vector<int>> &grid) {
    int count = 0;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (!grid[i][j]) {
                if (bfs(grid, i, j)) 
                    ++count;
            }
        }
    }

    return count;
}

int main(int argc, char const *argv[]) {
    vector<vector<int>> x = {{1,1,1,1,1,1,1,0}
                            ,{1,0,0,0,0,1,1,0}
                            ,{1,0,1,0,1,1,1,0}
                            ,{1,0,0,0,0,1,0,1}
                            ,{1,1,1,1,1,1,1,0}};
    
    cout << (closedIsland(x)) << '\n';

    return 0;
}
