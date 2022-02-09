#include <bits/stdc++.h>

using namespace std;


vector<int> matchingStrings(vector<string> strings, vector<string> queries) {

    vector<int> dp(queries.size(), 0);
    unordered_map<int, string> mp;

    for (int i = 0; i < strings.size(); ++i) 
        mp[i] = strings[i];

    for (int i = 0; i < queries.size(); ++i) {
        int count = 0;
        for (auto it = mp.begin(); it != mp.end();) {
            if (it -> second == queries[i]) {
                ++count; it = mp.erase(it);
            } else {++it;}
        }
        dp[i] = count;
    }
    return dp;
}

vector<int> matchingStrings(vector<string> strings, vector<string> queries) {

    vector<int> dp(queries.size(), 0);
    unordered_multiset<string> mp;

    for (int i = 0; i < strings.size(); ++i) 
        mp.insert(strings[i]);

    for (int i = 0; i < queries.size(); ++i)
        dp[i] = mp.count(queries[i]);

    return dp;
}

int main(int argc, char const *argv[])
{
    matchingStrings({"ab", "ab", "abc"}, {"ab", "abc", "bc"});
    
    return 0;
}