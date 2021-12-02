#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &lists){
    priority_queue<int,vector<int>,greater<int>> ans;
    int i, j;
    for (i = 0; i < lists.size(); ++i){
        for (j= 0; j < lists[i].size(); ++j){
            ans.push(lists[i][j]);
        }
    }
    while (!ans.empty()){
        cout << ans.top(); ans.pop();
    }
}

int main(){
    vector<vector<int>> lists = {{1,4,5}, {1,3,4}, {2,6}};
    solve(lists);

    return EXIT_SUCCESS;
}