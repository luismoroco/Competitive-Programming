#include <bits/stdc++.h>
using namespace std;

// https://cses.fi/problemset/task/1683

typedef int long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vll;
typedef map<ll, bool> mpb;
typedef vector<bool> vb;

void 
DFS(vll &adj, mpb &visited, vl &a, ll x)
{
    visited[x] = true;
    for (ll i : adj[x]){
        if (!visited[i]) DFS(adj, visited, a, i);
    }
    a.push_back(x);
}

void
Fx(vl &b, vll &reinos, ll x, ll y)
{
    b[x] = y;
    for (ll i : reinos[x]){
        if (b[i] == -1) Fx(b, reinos, i, y);
    }
}

void 
solve(ll n, mpb &visited, vl &a, vl &b, vl &c, vll &adj, vll &reinos)
{
    for (ll i = 0; i < n; ++i){
        if (!visited[i]) DFS(adj, visited, a, i);
    }
    reverse(begin(a), end(a));
    for (ll i : a){
        if (b[i] == -1){
            Fx(b, reinos, i, i);
            c.push_back(i);
        }
    }
}

int 
main(int argc, char const *argv[])
{
    ll n, m, x, y;
    cin >> n >> m;

    vll adj, reinos;
    vl a, b = vl(n, -1), c;
    mpb visited;
    adj.resize(n), reinos.resize(n);

    while (m--){
        cin >> x >> y;
        --x, --y;
        adj[x].push_back(y);
        reinos[y].push_back(x);
    }

    solve(n, visited, a, b, c, adj, reinos);

    int ID[200000]{};
    int sol = 0;
    for (size_t i = 0; i < n; ++i){
        if (!ID[b[i]]) ID[b[i]] = ++sol;
    }
    
    cout << sol << '\n';
    for (size_t i = 0; i < n; ++i){
        cout << ID[b[i]] << " \n"[i == n - 1];
    }

    return 0;
}