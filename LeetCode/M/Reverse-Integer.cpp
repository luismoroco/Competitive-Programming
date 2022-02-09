#include <bits/stdc++.h>

using namespace std;

int Fx(int x) {

    bool signo = (x < 0) ? true : false;
    x = abs(x);
    string c = to_string(x);
    reverse(c.begin(), c.end());
    x = (long)atoi(c.c_str());
    x = (signo)? -1*x : x;
    return (x < INT_MIN || x > INT_MAX) ? 0 : x;
}

int main(int argc, char const *argv[]) {

    int x = 1534236469;
    cout << Fx(x) << '\n';

    return 0;
}