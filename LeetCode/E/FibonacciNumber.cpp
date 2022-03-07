#include <bits/stdc++.h>

using namespace std;

int fib(int n) {
    if (n <= 1) return n;
    vector<int> dp(n + 2);
    dp[0] = 0; dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main(int argc, char const *argv[]) {
    cout << (fib(25)) << '\n';

    return 0;
}
