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
#include <unordered_map>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int t = 0, r = 0, c = 0;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        set<int> rx;
        for (int j = 0; j < n; ++j) {
            cin >> v[i][j];
            if (i == j) t += v[i][j];
            rx.insert(v[i][j]);
        }
        r += (rx.size() == n) ? 0 : 1;   
    }
    
    int j = 0;
    while (j < n) {
        set<int> cx;
        for (int it = 0; it < n; ++it) {
            cx.insert(v[it][j]);
        }
        c += (cx.size() == n) ? 0 : 1;
        ++j;
    }

    cout << t << ' ' << r << ' ' << c << '\n';
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