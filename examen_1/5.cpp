// https://cses.fi/problemset/task/2420

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
    int n, q, a, b, c, s, j, i;
    cin >> n >> q;
    char word[n];
    cin >> word;
    vector<string> ans;
    bool flag;
    
    while(q--){
        cin >> a >> b >> c;
        if(a == 1){
            cout << "replace" << '\n';
            word[b-1] = c;
        }else if(a == 2){
            cout << "palindromo" << '\n';
            flag = false;
            i = c-1; j = c-b;
            while(word[i] == word[j]){
                if(i >= j){
                    flag = true;
                    break;
                }
                i++; j++;
            }
            if(flag == false){
                ans.push_back("NO");
            }else if(flag == true){
                ans.push_back("YES");
            }
        }
    }    
    
    for (auto i : ans) cout << i << '\n';
    
    return EXIT_SUCCESS;
}