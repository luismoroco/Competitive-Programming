#include <bits/stdc++.h>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    for (int i = 0; i < obstacleGrid.size(); ++i) {
        for (int j = 0; j < obstacleGrid[0].size(); ++j) {
            
        }
    }
}

int main(int argc, char const *argv[]) {
    vector<vector<int>> x = {{0, 0, 0},
                             {0, 1, 0},
                             {0, 0, 0}};
    
    cout << (uniquePathsWithObstacles(x)) << '\n';

    return 0;
}
