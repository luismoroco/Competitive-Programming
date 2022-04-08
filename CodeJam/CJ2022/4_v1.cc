#include <bits/stdc++.h>

using namespace std;

const int N = 1000000 + 5, INF = 1e18;
int64_t F[N], P[N];
int64_t T, i, ans;

void solve() {
    int n; 
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> F[i];
    }
    for (i = 0; i < n; ++i) {
        cin >> P[i]; 
        P[i]--;
    }

    ans = 0;
    vector<int64_t> KMin(n, INF); 
    for (i = n-1; i >= 0; i--) {
        int64_t v = F[i];
        if (KMin[i] != INF) {
            ans -= KMin[i];
            v = max(v, KMin[i]);
        }
        ans += v;
        if (P[i] != -1) {
            KMin[P[i]] = min(KMin[P[i]], v);
        }
    }
    cout << ans << '\n';
}

int main(int, char**) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    int i = 1;
    while (T--) {
        cout << "Case #" << i++ << ": "; solve();
    }

    return 0;
}