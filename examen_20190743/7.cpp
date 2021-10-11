#include <bits/stdc++.h>
using namespace std;
/*
Input:
8 3
2 1 3 4 5 3 4 4
2 2 4
1 3 6
2 2 4
Output:
8
9
*/

int main(){
    int N, n, x, i, o, a, b, c, sum, lng, tmp;
    cin >> N >> o;
    n = N; int array[N+1];
    
    i = 1;
    while(n--){
        cin >> x;
        array[i] = x;
        ++i;
    }
    
    vector<int> ans;
    while(o--){
        cin >> a >> b >> c;
        if (a == 1){
            // reverse b->c  
            lng = c-b+1;
            for (i = a; i<lng/2; ++i){
                tmp = array[lng-i-1];
                array[lng-i-1] = array[i];
                array[i] = tmp;
            }
            continue;
        }else if (a == 2){
            // calculate suma
            sum = 0;
            for (i = b; i <= c; ++i)
                sum += array[i];
            ans.push_back(sum);
        }
    }
    
    for (auto i : ans) cout << i << '\n';

    return EXIT_SUCCESS;
}