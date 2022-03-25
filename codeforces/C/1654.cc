#include <bits/stdc++.h>

using namespace std;

int main(int, char**) {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        int x;
        long int sum = 0;
        cin >> x;
        vector<int> dp(x);
        for (int &i : dp) {
            cin >> i; 
            sum += i; 
        } 
    }

    return 0;
}
