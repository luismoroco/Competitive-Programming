#include <bits/stdc++.h>

using namespace std;

const int N = 1000000 + 5;

const int sucess = 1000000;
vector<vector<long>> dp(3, vector<long>(4, INT_MAX));

void setFasle(int x, vector<vector<bool>> &st) {
    for (int i = 0; i < 3; ++i) {
        st[i][x] = false;
    }
}

void solve() {
    vector<int> res(4, 0);
    vector<vector<bool>> st(3, vector<bool>(4, true));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> dp[i][j];
        }
    }
    int x = 0, y = 1, z = 2;
    int possible = 0, it = 0;
    for (int i = 0; i < 4; ++i) {
        if (dp[x][i] == 0 || dp[y][i] == 0 || dp[z][i] == 0) {
            setFasle(i, st);
            ++it;
            continue;
        } else {
            int mini = min(dp[x][i], min(dp[y][i], dp[z][i]));
            possible += mini;
            res[it] = mini;
            ++it;
        }    
    }
    if (possible >= sucess) {
        int sum = 0, it = 0;
        int ans[4] = {0, 0, 0, 0};
        while (it < 4 && sum + res[it] <= sucess) {
            if (st[0][it] == false) {
                ++it;
            } else {
                ans[it] = res[it];
                sum += res[it];
                ++it;
            }
        }
        if (sucess - sum <= res[it]) {
            int x = sucess - sum;
            sum += x;
            ans[it] = x;
        } 
        sum = 0;
        
        for (int i = 0; i < 4; ++i) {
            cout << ans[i] << ' ';  
        }
        cout << '\n';

    } else {
        cout << "IMPOSSIBLE\n";
    }
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