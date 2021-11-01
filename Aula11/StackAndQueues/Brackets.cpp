#include <bits/stdc++.h>
using namespace std;

int solve(string &S){
    int i;
    stack<int> st;
    char x;
    for (i = 0; i < S.length(); ++i){
        x = S[i];
        if(st.size() == 0) return 0;
        switch (x){
            case ')':
                if(st.top() == '(') st.pop();
                break;
            case ']':
                if(st.top() == '[') st.pop();
                break;
            case '}':
                if(st.top() == '{') st.pop();
                break;
            default:
                st.push(x);
                break;
            }
    }
    return st.size() == 0 ? 1 : 0;
}


int main(){
    string x = "{[()()]}";
    cout << solve(x) << '\n'; 

    return EXIT_SUCCESS;
}