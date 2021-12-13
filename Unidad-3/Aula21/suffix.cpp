#include <bits/stdc++.h>
using namespace std;

// suffixarray - suffix array

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    int l = s.length();
    vector<int> suffix(l);
    for (int i = 0; i < l; i++){
        suffix[i] = i;
    }
    sort(suffix.begin(), suffix.end(), [&](int i, int j) {
        return s.substr(i, l - i) < s.substr(j, l - j);
    });
    for (int i = 0; i < l; i++){
        cout << suffix[i] << " ";
    }
    cout << endl;

    return 0;
}