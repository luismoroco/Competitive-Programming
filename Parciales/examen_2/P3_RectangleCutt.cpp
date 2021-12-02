#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> vll;
typedef vector<ll> vl;

ll w, h, i, j, k;

// https://cses.fi/problemset/task/1744

void 
solve(ll w, ll h)
{
    vll dp(w + 1, vl(h + 1));
    for (i = 0; i <= w; ++i){
        for (j = 0; j <= h; ++j){
            if (i == j) dp[i][j] = 0;
            else dp[i][j] = INT_MAX;
        for (k = 1; k < i; ++k)
            dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
        for (k = 1; k < j; ++k)
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
        }
    }
    cout << dp[w][h] << '\n';
}


int 
main(int argc, char const *argv[])
{
    cin >> w >> h;
    solve(w, h);

    return 0;
}