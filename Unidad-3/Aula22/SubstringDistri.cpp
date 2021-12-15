#include <bits/stdc++.h>
using namespace std;

//https://cses.fi/problemset/task/2110


typedef long long ll;

bool 
Fx(ll x, ll y, ll &gap, ll &N, ll *pos){
    if(pos[x] != pos[y])
        return pos[x] < pos[y];
    x += gap;
    y += gap;
    return (x < N && y < N) ? pos[x] < pos[y] : x > y;
}

int 
main(int argc, char const *argv[])
{
    ll max = 1e5+5;
    ll sa[max], pos[max], tmp[max], lcp[max], pre[max], gap, N;
    string S;
    cin >> S;
    N = S.length();
    for (ll i = 0; i < N; i++) sa[i] = i, pos[i] = S[i];
    for (gap = 1;; gap <<= 1) {
        sort(sa, sa+N, [&](ll x, ll y){
            if (pos[x] != pos[y]) return pos[x] < pos[y];
            x += gap; y += gap;
            return (x < N && y < N) ? pos[x] < pos[y] : x > y;
        });
        for (ll i = 0; i < N-1; i++) tmp[i+1] = tmp[i] + Fx(sa[i], sa[i+1], gap, N, pos);
        for (ll i = 0; i < N; i++) pos[sa[i]] = tmp[i];
        if (tmp[N-1] == N-1) break;
    }

    for (ll i = 0, k = 0; i < N; i++) {
        if (pos[i] != N-1) {
            ll j = sa[pos[i] + 1];
            while (S[i + k] == S[j + k]) k++;
            lcp[pos[i]] = k;
            if (k) k--;
        }
    }

    ll prev = 0;
    for (ll i = 0; i < N; i++) {
        pre[prev + 1]++;
        pre[N - sa[i] + 1]--;
        prev = lcp[i];
    }
    for (ll i = 1; i <= N; i++) {
        cout << pre[i] << ' ' ;
        pre[i+1] += pre[i];
    }
    
    return 0;
}











