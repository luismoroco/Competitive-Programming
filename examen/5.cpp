// https://cses.fi/problemset/task/1648

#include <bits/stdc++.h>
using namespace std;
/*
Input:
7 5
aybabtu
2 3 5
1 3 x
2 3 5
1 5 x
2 3 5

Output:
YES
NO
YES
*/

int main(){
    int n, op, x, y, i, j, m, chr_it, lng;
    char replace;
    string st;
    cin >> n >> op;
    cin >> st;
    vector<string> ans;

    while (op--){
        cin >> x >> y >> replace;
        if (x == 1) {
            st[y] = replace;
        }
        if (x == 2){
            chr_it = (int)replace - 48;
            lng = chr_it - y + 1;
            if (lng <= 1) {
                ans.push_back("YES");
                continue;
            }
            i = y; j = lng - 1;
            while (st[i] == st[j]){
                if (i >= j){
                    ans.push_back("YES");
                    break;
                }
                i++; j++;
            }
            ans.push_back("NO");
            continue;
        }
    }
    cout << '\n';
    for (auto i : ans)
        cout << i << '\n';
    
    return EXIT_SUCCESS;
}