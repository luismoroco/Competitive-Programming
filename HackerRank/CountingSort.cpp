#include <bits/stdc++.h>

using namespace std;

vector<int> countingSort(vector<int> arr) {

    int range = INT_MIN;
    for (int i : arr)
        range = (i >= range)? i : range;

    vector<int> dp(range+1, 0);
    unordered_multiset<int> mp;
    set<int> st;

    for (int i : arr) { 
        mp.insert(i); st.insert(i); 
    }

    for (auto it = st.begin(); it != st.end(); ++it)
        dp[*it] = mp.count(*it);
    
    return dp;
}


int main(int argc, char const *argv[]) {

    countingSort({1, 1, 3, 2, 1});
    

    return 0;
}
