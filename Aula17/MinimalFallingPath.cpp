#include <bits/stdc++.h>
using namespace std;

int minFallingPathSum(vector<vector<int>>& grid) {
        
    int n = grid.size(); 
    if(n == 1)
    {
        return grid[0][0];
    }
    else
    {
        vector<int> ans = grid[0];
        sort(ans.begin(), ans.end());
            
        for(int i = 1; i < n; i++){
            for(int j = 0; j < n; j++){    
                if(ans[0] == grid[i - 1][j]) grid[i][j] += ans[1];
                else grid[i][j] += ans[0];
            }
            ans = grid[i];
            sort(ans.begin(),ans.end());
        }

        return ans[0];
    }
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> x = {{1,2,3}, {4,5,6}, {7,8,9}};
    cout << minFallingPathSum(x) << '\n'; 
    
    return 0;
}
