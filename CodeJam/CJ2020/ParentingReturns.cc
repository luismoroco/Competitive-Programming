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

const int N = 1000000 + 5;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> act(n);
    for (int i = 0; i < n; ++i) {
        i >> act[i].first;
        cin >> act[i].second.first >> act[i].second.second;
    }
    sort(act.begin(), act.end(), [&](const auto &P1, const auto &P2){
        return P1.second.first < P2.second.first;
    });
    bool state = false;
    for (int i = 1; i < n; ++i) {
        if (act[i-1].second.second <= act[i].second.first) {
            state = true; 
            break;
        }
    }
    if (!state) {
        cout << "IMPOSSIBLE\n"; 
        return;
    } 
    char res[n];
    //vector<char> res(n, 'J');
    char replace = 'J';
    for (int i = 1; i < n; ++i) {
        if (act[i-1].second.second > act[i].second.first) {
            res[act[i-1].first] = replace;
            replace = (replace == 'J') ? 'C' : 'J';
            res[act[i].first] = replace;
        } else if (act[i-1].second.second <= act[i].second.first) {
            res[act[i-1].first] = replace;
            res[act[i].first] = replace;
        }
    }
    cout << res << '\n';
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