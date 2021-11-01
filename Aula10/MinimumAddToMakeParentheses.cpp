#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

int minAddToMakeValid(string s) {
    int l = 0, r = 0;
    for (char c : s){
      if (c == '(') {++l;}
      else {
        if (l == 0)++r;
        else --l;
      }
    }
    return l + r;
}

int main(){
    string s = "()))((";
    cout << minAddToMakeValid(s) << '\n';

    return EXIT_SUCCESS;
}