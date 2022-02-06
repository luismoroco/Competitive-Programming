#include <bits/stdc++.h>

using namespace std;
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string x;
    int n, op = 0, i, num = 0;
    cin >> n;
    while (n--){
        cin >> x;
        for (i = 0; i < x.length(); ++i){
            if (x[i] == '+') {++op;}
            if (x[i] == '-') {--op;}
        }
    }
    cout << num + (op/2) << '\n'; 
    
    return EXIT_SUCCESS;
}