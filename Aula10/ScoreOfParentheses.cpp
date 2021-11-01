#include <iostream>
using std::string;
using std::cout;

int solve(string S){
    int pwr = 0, ans = 0;
    for (int i = 1; i < S.length(); ++i){ 
        if (S[i] == '(') pwr++;
        else if (S[i-1] == '(') ++ans << pwr--;
        else pwr--;
    }
    return ans;
}

int main(){
    string s = "()";
    cout << solve(s);

    return EXIT_SUCCESS;
}