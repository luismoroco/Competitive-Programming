#include <bits/stdc++.h>

using namespace std;

void provide(vector<vector<bool>> &dp) {
    int x, y, s;
    cin >> x >> y >> s;
    dp[x][y] = false;
    for (int i = x - s; i <= x; ++i) { if (i >= 0) dp[i][y] = false;}
    for (int i = y; i <= y + s; ++i) { if (i < dp[0].size()) dp[x][i] = false;}
    for (int i = x; i <= x + s; ++i) { if (i < dp.size()) dp[i][y] = false;}
    for (int i = y - s; i <= y; ++i) { if (i >= 0) dp[x][i] = false;}
}

int main(int argc, char const *argv[]) {
    int m, n, k;
    cin >> m >> n >> k;

    vector<vector<bool>> dp(m, vector<bool>(n, true));
    while (k--) {
        provide(dp);
    }

    for (auto i : dp) {
        for (auto x : i) {
            cout << x << ' ';
        }
        cout << '\n';
    }

    return 0;
}
