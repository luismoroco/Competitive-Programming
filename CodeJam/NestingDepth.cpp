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
char v[N];

void solve() {
    cin >> v;
    int n = strlen(v);
    int balance = 0;
    for (int i = 0; i < n; ++i) {
        int valor = v[i] - '0';
        while (valor > balance) {
            ++balance; 
            cout << '(';
        }
        while (valor < balance) {
            --balance;
            cout << ')';
        }        
        cout << v[i];
    }
    while (balance--) {
        cout << ')';
    }
    cout << '\n';
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