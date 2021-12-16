#include <bits/stdc++.h>
using namespace std;

// https://open.kattis.com/problems/threepowers

typedef long long ll;
typedef vector<ll> vl;

void 
solve(ll n) {
    vl v;

    ll curr = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            v.push_back(curr);
        }
        curr *= 3;
        n /= 2;
    }

    cout << "{ ";
    for (ll i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i != v.size() - 1) {
            cout << ", ";
        }
    }
    cout << " }" << endl;
}

int 
main(int argc, char const *argv[])
{
    ll n;
    while (cin >> n){
        if (n == 0){ break;}
        solve(n-1);
    }

    return 0;
}