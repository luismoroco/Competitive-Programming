#include <bits/stdc++.h>

using namespace std;

void plusMinus(vector<int> arr) {
    int mn = 0, my = 0, c = 0;
    for (int i : arr) {
        if (i < 0) ++mn;
        else if (i > 0) ++my;
        else ++c;
    }
    
    cout << fixed;
    cout << setprecision(6); 
    cout << (double)my/arr.size() << '\n';
    cout << (double)mn/arr.size()  << '\n';
    cout << (double)c/arr.size()  << '\n';
}

int main(int argc, char const *argv[])
{
    plusMinus({1, 1, 0, -1, -1});    


    return 0;
}
