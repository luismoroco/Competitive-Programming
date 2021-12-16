#include <bits/stdc++.h>
using namespace std;

// https://cses.fi/problemset/task/2109

typedef long long int ll;
typedef pair<int,int> pii;
const ll MAXX = 1e5+5;
ll BUFF[MAXX], POSITION[MAXX], BUFFFER[MAXX], LCP[MAXX], MAKK[MAXX*10], gap, N;
pii seg[MAXX*10];
string S;

bool 
comp(ll i, ll j){
    if(POSITION[i] != POSITION[j]) return (POSITION[i] < POSITION[j]);
    i += gap; j += gap;
    if(i < N && j < N) return (POSITION[i] < POSITION[j]);
    return (i > j);
}

void
push(ll k){
    if (MAKK[k]) {
        MAKK[k] = 0;
        seg[2*k].first = seg[2*k + 1].first = seg[k].first/2;
        seg[2*k].second = seg[2*k + 1].second = 0;
        MAKK[2*k] = MAKK[2*k + 1] = 1;
    }
}

void 
update(ll v, ll a, ll b, ll k, ll x, ll y){
    if (b < x || a > y) return;
    if (a<=x && b>=y) {
        seg[k].second += v;
        return;
    }
    int h = min(b,y) - max(a,x) + 1;
    push(k); 
    seg[k].first += h*v;
    int d = (x+y)/2;
    update(v, a, b, 2*k, x, d);
    update(v, a, b, 2*k + 1, d + 1, y);  
}

ll
assign(ll v, ll a, ll b, ll k, ll x, ll y){
    if (b < x || a > y) return seg[k].first + (y - x + 1)*seg[k].second;
    if (a <= x && b >= y) {
        seg[k].first = (y-x+1)*v;
        seg[k].second = 0;
        MAKK[k] = 1; 
        return seg[k].first;
    }
    push(k); 
    int d = (x+y)/2;
    seg[2*k].second += seg[k].second, seg[2*k + 1].second += seg[k].second;
    seg[k].second = 0;
    seg[k].first = assign(v, a, b, 2*k, x, d) + assign(v, a, b, 2*k + 1, d + 1, y);
    return seg[k].first;
}

ll
sum(ll a, ll b, ll k, ll x, ll y){
    if (b < x || a > y) return 0;
    if (a <= x && b >= y) {
        return seg[k].first + (y-x+1)*seg[k].second;
    }
    push(k); 
    seg[k].first += (y-x+1)*seg[k].second;
    seg[2*k].second += seg[k].second, seg[2*k + 1].second += seg[k].second;
    seg[k].second = 0;
    ll d = (x+y)/2;
    return sum(a, b, 2*k, x, d) + sum(a, b, 2*k + 1, d + 1, y);
}

int 
main(int argc, char const *argv[])
{
    getline(cin, S);
    N = S.length();
    for (ll i = 0; i < N; i++) BUFF[i] = i, POSITION[i] = S[i];
    for (gap = 1;; gap <<= 1) {
        sort(BUFF, BUFF+N, comp);
        for (ll i = 0; i < N-1; i++) BUFFFER[i+1] = BUFFFER[i] + comp(BUFF[i], BUFF[i+1]);
        for (ll i = 0; i < N; i++) POSITION[BUFF[i]] = BUFFFER[i];
        if (BUFFFER[N - 1] == N - 1) break;
    } 
    for (ll i = 0, k = 0; i < N; i++) if (POSITION[i] != N-1) {
        ll j = BUFF[POSITION[i] + 1];
        while (S[i + k] == S[j + k]) k++;
        LCP[POSITION[i]] = k;
        if (k) k--;
    }
    ll k; cin >> k;
    k = N*(N+1)/2 - k + 1;
    ll K = 1<<(int) ceil(log2(N+1)), cur = 0;
    for (ll i = N-1; i >= 0; i--) {
        update(1, 1, N-BUFF[i], 1, 0, K-1);
        ll prev = (i ? LCP[i-1] : 0);
        ll l = prev+1, r = N-BUFF[i], ans = -1;
        while (l <= r) {
            ll m = l + (r-l)/2;
            if (cur + sum(m, N-BUFF[i], 1, 0, K-1) >= k) {ans = m; l = m + 1;}
            else r = m - 1;
        }
        if (ans != -1) { return cout << S.substr(BUFF[i], ans), 0;}
        cur += sum(prev+1, N-BUFF[i], 1, 0, K-1);
        assign(0, prev+1, N-BUFF[i], 1, 0, K-1);
    }

    return 0;
}