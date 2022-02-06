#include <bits/stdc++.h>

using namespace std;
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    string x;
    cin >> x;
    int data[4] = {0, 0, 0, 0};
    int i, j;
    
    for (int i = 0; i < x.length(); ++i){
        if (x[i] == '1')
            data[1] += 1;
        if (x[i] == '2')
            data[2] += 1;
        if (x[i] == '3')
            data[3] += 1;
    }
 
    bool flag = false;
    for (i = 0; i < 4; ++i){
        for (j = 0; j < data[i]; ++j){
            if (flag == false){
                cout << i;
                flag = true;
                continue;
            }
            cout << '+' << i;
        }
    }
    
    return EXIT_SUCCESS;
}