#include <bits/stdc++.h>


using namespace std;


string pangrams(string s) {

    vector<bool> dp(122+1, false);
    for (int i = 0; i < s.length(); ++i) {
        s[i] = tolower(s[i]);
        int x = s[i];
        if (x >= 97 && x <= 122) dp[x] = true;
    }

    bool res = true;
    for (int i = 97; i <= 122; ++i) {
        res *= dp[i];
    }

    return (res)? "pangram" : "not pangram";
}


int main(int argc, char const *argv[]) {
    
    cout << pangrams("We promptly judged antique ivory buckles for the next prize");

    return 0;
}
