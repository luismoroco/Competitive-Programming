#include <bits/stdc++.h>

using namespace std;

bool PAL(string x){
    for (int i = 0; i < x.length()/2; ++i) {
        if (x[i] != x[x.length() -i -1]) return false;
    }
    return true;
}

string firstPalindrome(vector<string>& words) {
    for (int i = 0; i < words.size(); ++i) {
        if (PAL(words[i])) return words[i];
    }
    return "";
}

int main(int argc, char const *argv[]) {
    vector<string> x = {"abc","car","ada","racecar","cool"};
    cout << firstPalindrome(x);

    return 0;
}
