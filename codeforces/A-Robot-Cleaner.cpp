#include <bits/stdc++.h>
 
using namespace std;
 
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
 
    int n, m, rb, cb, rd, cd;
    while (t--){
        cin >> n >> m >> rb >> cb >> rd >> cd;
        
        int res = 0;
        int x = 1, y = 1;
 
        while(true){
            if (rb == rd || cb == cd) break;
            if (rb + x > n || rb + x < 1) x = x * -1;
            if (cb + y > m || cb + y < 1) y = y * -1;
            
            rb += x;
            cb += y;
            ++res;
        }   
 
        cout << res << '\n';
    }
    
    return EXIT_SUCCESS;
}