#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/pacific-atlantic-water-flow/

typedef vector<int> vi;
typedef vector<vector<int>> vii;

int n, m;
void DFS(int i, int j, vii &A, vii &b){
    if(b[i][j] == 0) 
        b[i][j] = 1;
    if(i > 0 && A[i - 1][j] >= A[i][j] && b[i - 1][j] == 0) 
        DFS(i-1, j, A, b);
    if(j > 0 && A[i][j - 1] >= A[i][j] && b[i][j - 1] == 0)  
        DFS(i, j - 1, A, b);
    if(j < m - 1 && A[i][j + 1] >= A[i][j] && b[i][j + 1] == 0) 
        DFS(i, j + 1, A, b);
    if(i < n - 1 && A[i + 1][j] >= A[i][j] && b[i + 1][j] == 0) 
        DFS(i + 1, j, A, b);
    return;
}

vii pacificAtlantic(vii &heights) {
    n = heights.size();
    m = heights[0].size();
    int ans = 0, i, j;
    
    vii res;
    vii blue(n, vi(m,0));
    vii red(n, vi(m,0));
    
    for(i = 0; i < m; ++i) 
        DFS(0, i, heights, blue);
    for(i = 1; i < n; ++i) 
        DFS(i, 0, heights, blue);
    for(i = 0; i < n; ++i) 
        DFS(i, m-1, heights, red);
    for(i = m - 2; i >= 0; --i) 
        DFS(n-1, i, heights, red);
    
    for(i = 0; i < n; ++i){
        for(j = 0; j < m; ++j){
            if(blue[i][j] == 1 && red[i][j] == 1) 
                res.push_back({i,j});
        }
    }   

    for (auto i : res){
        for (auto j : i) cout << j << ' ';
        cout << '\t';
    }

    return res;  
}

int main(int argc, char const *argv[])
{
    vii x = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    pacificAtlantic(x);

    return 0;
}
