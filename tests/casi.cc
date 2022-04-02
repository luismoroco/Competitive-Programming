#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>

using namespace std;

void dfs(int s, vector<bool> &visited, vector<int> &feli, 
                            vector<int> adj[], int &sum) {
    if (visited[s]) return;
    visited[s] = true;
    sum = max(sum, feli[s]);    
    for (auto u : adj[s]) {
        dfs(u, visited, feli, adj, sum);
    }
}

int BestLocal(int x, vector<int> &res, int &sum, vector<bool> &visited, 
                      vector<int> &feli, vector<int> adj[], int &acumu) {
    for (int i = 0; i < res.size(); ++i) {
        if (res[i] == x) continue;
        sum = 0;
        dfs(res[i], visited, feli, adj, sum);
        acumu += sum;
    } 
}

void permutations(vector<vector<int>> &res,
                        vector<int> nums, int l, int h) {
    if (l == h) {
        res.push_back(nums);
        return;
    }
    for (int i = l; i <= h; i++) {
        swap(nums[l], nums[i]);
        permutations(res, nums, l + 1, h);
        swap(nums[l], nums[i]);
    }
}

vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> res;
    int x = nums.size() - 1;
    permutations(res, nums, 0, x);
    return res;
}


void solve() {
    int n;
    cin >> n;
    vector<int> feli(n+1), edge(n+1);
    vector<bool> pure(n+1, true);
    vector<int> adj[n+1];
    vector<bool> visited(n+1, false);
    vector<int> res;
    int sum_parcial = 0;
    int acumulate = 0;
    int response = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> feli[i];
    } 
    for (int j = 1; j <= n; ++j) {
        cin >> edge[j];
        adj[j].push_back(edge[j]);
        pure[edge[j]] = false;
    }
    for (int i = 1; i <= n; ++i) {
        if (pure[i]) res.push_back(i);
    }
    vector<vector<int>> permuted = permute(res);
    for (int i = 0; i < permuted.size(); ++i) {
        
    }

    for (int i = 0; i < res.size(); ++i) {
        dfs(res[i],  visited, feli, adj, sum_parcial);
        acumulate += sum_parcial;
        BestLocal(res[i], res, sum_parcial, visited, feli, adj, acumulate);
        response = max(response, acumulate);
        sum_parcial = 0;
        visited.clear();
    } 
    cout << response << '\n';

}

int main(int, char**) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    int i = 1;
    while (t--) {
        cout << "Case #" << i++ << ": "; solve();
    }

    return 0;
}