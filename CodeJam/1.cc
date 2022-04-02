#include <bits/stdc++.h>

using namespace std;

const int N = 1000000 + 5;

void solve() {
    int R, C;
    cin >> R >> C;
    R = R*2 + 1;
    C = C*2 + 1;
    vector<vector<char>> dp(R, vector<char>(C, '.'));
    for (int i = 0; i < R; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < C; ++j){
                dp[i][j] = (j%2 == 0) ? '+' : '-';
            }
        } else {
            for (int j = 0; j < C; ++j){
                dp[i][j] = (j%2 == 0) ? '|' : '.';
            } 
        }
    } 

    dp[0][0] = '.';
    dp[0][1] = '.';
    dp[1][0] = '.';
    dp[1][1] = '.';
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << dp[i][j];
        }
        cout << endl;
    }
}   

int main(int, char**) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    int i = 1;
    while (t--) {
        cout << "Case #" << i++ << ": \n"; solve();
    }

    return 0;
}