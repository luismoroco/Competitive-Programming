#include <bits/stdc++.h>
using namespace std;

// https://cses.fi/problemset/task/2108

typedef long long int ll;
const ll MARX =1e5+5;

ll n = 0, t = 0, ans = 0;
string arr;
ll BUFFF[MARX], LCP[MARX], BFFE[MARX], POSITION[MARX];

bool 
compare(ll i, ll j){
    if(POSITION[i]!=POSITION[j]) return (POSITION[i]<POSITION[j]);
    i+=t;j+=t;
    if(i<n && j<n) return (POSITION[i]<POSITION[j]);
    return (i>j);
}

int 
main(int argc, char const *argv[])
{
    ll x = 0;
    cin >> arr;
    n = arr.length();
    for(ll i = 0; i < n; ++i){
        BUFFF[i] = i;
        POSITION[i] = arr[i];
    }
    for(t = 1; t < 2*n+1; t*=2){
        sort(BUFFF, BUFFF+n, compare);
        for(ll i = 0; i < n-1; ++i){
            BFFE[i+1] = BFFE[i];
            if(compare(BUFFF[i], BUFFF[i+1])) BFFE[i+1]++;
        }
        for(ll i = 0; i < n; ++i){
            POSITION[BUFFF[i]] = BFFE[i];
        }
        if(BFFE[n-1] == n-1) break;
    }
    ll px = 0;
    for(ll i = 0; i < n; ++i){
        if(POSITION[i] != n-1){
            ll j = BUFFF[POSITION[i]+1];
            while(arr[i+px] == arr[j+px]) px++;
            LCP[POSITION[i]] = px;
            if(px > 0) px--;
        }
    }
    cin >> x;
    ll p = 0, q = 0;
    for (ll i = 0; i < n; ++i){
        if (p + (n-BUFFF[i]) - q >= x){ 
            ll j = q;
            string ans = arr.substr(BUFFF[i], j);
            while(p < x){
                ans += arr[BUFFF[i]+j];
                p++; j++;
            }
            cout << ans; break;
        }
        p += (n-BUFFF[i]) - q;
        q = LCP[i];
    }

    return 0;
}