#include <bits/stdc++.h>

using namespace std;

vector<string> cellsInRange(string s) {
    char tam = max(s[1], s[4]);
    vector<string> ans;
    for (char i = 65; i <= s[3]; ++i){
        for (char j = '1'; j <= tam; ++j){
            string x = "A1";
            x[0] = i; x[1] = j;
            ans.push_back(x);
        }
    }
    
    return ans;
}

int main(int argc, char const *argv[]) {
    cellsInRange("K1:L2");

    return 0;
}
