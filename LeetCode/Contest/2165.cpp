#include <bits/stdc++.h>

using namespace std;

long long smallestNumber(long long num) {
    string dp = to_string(num);
    if (dp[0] != '-') {
        sort(dp.begin(), dp.end());
        for (int i = 0; i < dp.size(); ++i) {
            if (dp[i] != '0') {
                swap(dp[i], dp[0]); 
                break;
            }
        }
        return stoll(dp);
    }
    else {
        sort(dp.begin() + 1, dp.end(), [&](char &x, char &y){return x > y;});
        return stoll(dp);
    }
}

int main(int argc, char const *argv[]) {
    
    cout << smallestNumber(-7605);

    return 0;
}
