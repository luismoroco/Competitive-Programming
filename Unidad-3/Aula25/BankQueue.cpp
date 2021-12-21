#include <bits/stdc++.h>
using namespace std;

// https://open.kattis.com/problems/bank

typedef long long int ll; 
typedef pair<ll, ll> pii;
typedef vector<pii> vpii;
typedef vector<bool> vb;

int main(int argc, char const *argv[])
{
    ll n, m, i, ans;
    while (cin >> n >> m)
    {
        ans = 0;
        vpii v(n);
        vb BUFF(m+1, true);
        for (i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
        sort(v.begin(), v.end(), [](pii a, pii b) { return (a.first == b.first && a.second > b.second) || a.first > b.first; });
        for (auto x : v) {
            while (x.second >= 0 && !BUFF[x.second]) {x.second--;}
            if (x.second >= 0){ BUFF[x.second] = false; ans += x.first; }
        }
        cout << ans << '\n';
    }

    return 0;
}