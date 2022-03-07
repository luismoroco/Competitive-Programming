#include <bits/stdc++.h>

using namespace std;

string addSpaces(string s, vector<int> spaces) {
    int a = 0;
    for (int i = 0; i < spaces.size(); ++i) {
        s.insert(spaces[i]+a, " ");
        ++a; 
    }
    return s;
}

string addSpaces(string s, vector<int> spaces) {
    string x;
    int m = 0; 
    for (int i = 0; i < s.length(); ++i) {
        if (m < spaces.size() && i == spaces[m]) { x += " "; ++m;}
        x += s[i];
    }
    return x;
}

int main(int argc, char const *argv[]) {
    cout << addSpaces("LeetcodeHelpsMeLearn", {8, 13, 15});

    return 0;
}