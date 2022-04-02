#include <iostream>
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

long sum = 0, Local = 0;
long response = 0;

const int N = 100000000 + 1;
int n;

long feli[N];
int edge[N];
bool pure[N], visited[N];

void dfs(int s, vector<int> adj[]) {
    if (visited[s]) return;
    visited[s] = true;
    sum = max(sum, feli[s]);    
    for (auto u : adj[s]) {
        dfs(u, adj);
    }
}

vector<int> resi;
void process(int x, vector<int> adj[]) {
    Local = sum;
    for (int i = 0; i < resi.size(); ++i) {
        sum = 0;
        if (resi[i] == x) {
            continue;
        } else {
            dfs(resi[i], adj);
            Local += sum;
        }
    }
    response = max(response, Local);
    for (int k = 0; k <= n; ++k) {
        visited[k] = false;
    } 
}

void solve() {
    cout << "GAA\n";
    cin >> n;
    int i, j, k;
    vector<int> adj[n+1];
    for (i = 0; i <= n; ++i) {
        pure[i] = true;
        visited[i] = false;
    }
    for (i = 1; i <= n; ++i) {
        cin >> feli[i];
    } 
    for (j = 1; j <= n; ++j) {
        cin >> edge[j];
        adj[j].push_back(edge[j]);
        pure[edge[j]] = false;
    }
    for (i = 1; i <= n; ++i) {
        if (pure[i]) resi.push_back(i);
    }
    for (int i = 0; i < resi.size(); ++i) {
        dfs(resi[i], adj);
        process(resi[i], adj);
        sum = 0;
    }
    cout << response << '\n';
    response = 0;
    resi.resize(0);
    adj->resize(0);
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