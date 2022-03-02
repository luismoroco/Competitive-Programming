#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int t;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        int tam, mx;
        cin >> tam >> mx;
        
        vector<int> v(tam);
        for (int x = 0; x < tam; ++x) cin >> v[x];

        sort(v.begin(), v.end());

        int ans = 0, accu = 0;
        while (ans < tam && accu + v[ans] <= mx) {
            accu += v[ans];
            ++ans;
        }

        cout << "Case #" << i << ": " << ans << '\n';
    }

    return 0;
}
