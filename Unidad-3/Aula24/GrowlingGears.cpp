#include <bits/stdc++.h>
using namespace std;

// https://open.kattis.com/problems/growlinggears

typedef long long int ll;
typedef vector<ll> vll;

int 
main(int argc, char const *argv[])
{
    ll n, m , max;
    double_t pos, val, a, b, c;
    cin >> n;
    while (n--){
        cin >> m;
        vll v;
        for(ll j = 0; j < m; j++) {
            cin >> a >> b >> c;
            pos = b / (2*a);
            val = a * pow(pos, 2) + b * pos + c;
            v.push_back(val);
        }
        max = 0;
        for(ll j = 0; j < m; j++) {
            if(v[j] > v[max]) max = j;
        }
        cout << max+1 << '\n';
    }

    return 0;
}