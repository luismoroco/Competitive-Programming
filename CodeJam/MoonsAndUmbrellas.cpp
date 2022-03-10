#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; 
    cin >> T;
    for (int i = 1; i <= T; i++) {
        int x, y;
        string st; 
        cin >> x >> y >> st;
        int N = st.size();
        vector<vector<int>> dp(N + 1, vector<int>(2, 1e9));
        dp[0][0] = dp[0][1] = 0;
        for (int i = 1; i <= N; ++i) {
            for (int r = 0; r <= 1; ++r) {
                
            }
        }


    }

    
}