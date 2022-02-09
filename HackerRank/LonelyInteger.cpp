#include <bits/stdc++.h>

using namespace std;

int lonelyinteger(vector<int> a) {

    if (a.size() == 1) return a[0];

    unordered_multiset<int> mp;
    set<int> st;

    for (int i = 0; i < a.size(); ++i) {
        mp.insert(a[i]);
        st.insert(a[i]);
    } 
    
    int res = INT_MAX;
    int ret = 0;

    for (auto it = st.begin(); it != st.end(); ++it) {
        int x = mp.count(*it);
        if (x <= res) {
            res = x;
            ret = *it;
        }
    }
    return ret;
}

int main(int argc, char const *argv[]) {

    cout << lonelyinteger({1, 2, 3, 4, 3, 2, 1}) << '\n';
    
    return 0;
}
