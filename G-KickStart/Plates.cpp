#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int n, k, p;
        cin >> n >> k >> p;

        vector<vector<int>> v(n, vector<int>(k));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < k; ++j) 
                cin >> v[i][j];
        }

        vector<int> dp(p + 1, 0);
        for (int i = 0; i < n; ++i) {
            vector<int> tp = dp;
            for (int j = 0; j <= p; ++j) {
                int cur = 0;
                
            }
        }

        cout << "Case #" << i << ": " << dp[p] << '\n';
    }

    return 0;
}
