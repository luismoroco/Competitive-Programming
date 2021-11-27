// https://www.spoj.com/problems/ADAPLANT/
#include <bits/stdc++.h>
using namespace std;
/*
input:
3
5 0
1 2 3 5 6
4 6
1 10 2 9
10 1
1 7 8 9 19 11 21 8 11 0 
output:
2
9
13
*/

int main(){
    int t, n, k, n_tmp, i, x, mx, j, w;
    vector<int> ans;
    cin >> t;
    while(t--){
        cin >> n >> k;
        int array[n];
        n_tmp = n; i = 0;
        while(n_tmp--){
            cin >> x;
            array[i] = x;
            ++i;
        }
        mx = 0; i = 0, w = 0;
        while(w<=k){
            for(j=0; j<n-w-1; j=j+1+w){
                n_tmp = abs(array[j]-array[j+1]);
                if(n_tmp > mx)
                    mx = n_tmp;
            } 
            ++w;
        }
        ans.push_back(mx);
    }
    
    for(auto i : ans) cout << i << '\n';

    return EXIT_SUCCESS;
}