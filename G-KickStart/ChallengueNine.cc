#include <bits/stdc++.h>

using namespace std;

void f() {
    string v;
    cin >> v;
    int sum = 0, n = v.length();
    for (char i : v) {
        sum += i - '0';
        sum %= 9;
    }
    if (sum) sum = 9 - sum;
    int at = n;
    for (int i = sum == 0; i < n; ++i) {
        if (v[i] - '0' > sum) {
            at = i;
            break;
        }
    }
    cout << v.insert(at, to_string(sum)) << '\n'; 
}

int main(int, char**) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; 
    cin >> t;
    int i = 1;
    while (t--) {
        cout << "Case #" << i++ << ": "; f();
    }

    return 0;
}