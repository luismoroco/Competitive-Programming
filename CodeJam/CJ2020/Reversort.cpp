#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; scanf("%d", &t); 
    for (int i = 1; i <= t; ++i) {
        int v; scanf("%d", &v);
        vector<int> dp(v + 1);
        for (int i = 1; i <= v; ++i) scanf("%d", &dp[i]);
        int ans = 0;
        for (int i = 1; i < v; ++i) {
            int pos = i;
            for (int j = i + 1; j <= v; ++j) {
                if (dp[j] == i) { pos = j; break; }
            }
            reverse(dp.begin() + i, dp.end() + pos + 1);
            ans += pos - i + 1;
        }
        printf("Case #%d: %d\n", i, ans);
    }
    return 0;
}
