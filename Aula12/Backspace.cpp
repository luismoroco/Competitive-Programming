#include <bits/stdc++.h>
using namespace std;

void solve(string st){
    deque<char> ans;
    for (size_t i(0); i < st.size(); ++i){
        if(st[i] != '#') ans.push_back(st[i]);
        else if(st[i]=='#') ans.pop_back();
    }

    while (!ans.empty()){
        cout << ans.front();
        ans.pop_front();
    }    
}

int main(){
    string st = "abc#de#f#ghi#jklmn#op#";
    solve(st);

    return EXIT_SUCCESS;
}