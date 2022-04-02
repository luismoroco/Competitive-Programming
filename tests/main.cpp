#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>

using namespace std;

const int N = 1000000 + 5;

int n;
vector<int> feli(N), edge(N);
vector<bool> pure(N, true);
vector<int> adj[N];
vector<bool> visited(N, false);
vector<int> res;
int sum_parcial = 0;
int acumulate = 0;

void dfs(int s) {
    if (visited[s]) return;
    visited[s] = true;
    sum_parcial = max(sum_parcial, feli[s]);    
    for (auto u : adj[s]) {
        dfs(u);
    }
}

void BestLocal(int x) {
    for (int i = 0; i < res.size(); ++i) {
        if (res[i] == x) continue;
        sum_parcial = 0;
        dfs(res[i]);
        acumulate += sum_parcial;
    } 
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> feli[i];
    } 
    for (int j = 1; j <= n; ++j) {
        cin >> edge[j];
        adj[j].push_back(edge[j]);
        pure[edge[j]] = false;
    }
    for (int i = 1; i <= n; ++i) {
        if (pure[i]) res.push_back(i);
    }
    int response = 0;
    for (int i = 0; i < res.size(); ++i) {
        dfs(res[i]);
        acumulate += sum_parcial;
        BestLocal(res[i]);
        response = max(response, acumulate);
        sum_parcial = 0;
        visited.clear();
    }   
    cout << response << '\n';
    pure.clear();
    adj->clear();
    feli.clear();
    edge.clear();
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