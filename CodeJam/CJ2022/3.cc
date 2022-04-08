#include <bits/stdc++.h>

using namespace std;

const int N = 1000000 + 5;

void solve() {
    int n;
    cin >> n;
    int dados[n];
    int sum = 0, x;
    priority_queue<int, vector<int>, greater<int>> dp;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        dp.push(x);
    }
    int it = 1;
    while (!dp.empty()) {
        int t = dp.top();
        dp.pop();
        if (it <= t) {
            ++it;
            ++sum;
        } else {
            continue;;
        }
    }
    cout << sum << '\n';
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