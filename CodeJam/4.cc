#include <bits/stdc++.h>

using namespace std;

long long sum = 0;

void dfs(int s, vector<bool> &visited, vector<long long> feli, 
                            vector<int> adj[]) {
    if (visited[s]) return;
    visited[s] = true;
    sum = max(sum, feli[s]);    
    for (auto u : adj[s]) {
        dfs(u, visited, feli, adj);
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
    vector<long long> feli(n+1, 0), edge(n+1, 0);
    vector<bool> pure(n+1, true);
    vector<int> adj[n+1];
    vector<bool> visited(n+1, false);
    vector<int> res;
    long long response = 0;
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
        long long Local = 0;
        for (int j = 0; j < permuted[0].size(); ++j) {
            sum = 0;
            dfs(permuted[i][j], visited, feli, adj);
            Local += sum;
        }
        for (int i = 0; i <= n; ++i) {
            visited[i] = false;
        }
        response = max(response, Local);
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