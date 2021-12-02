#include <bits/stdc++.h>
using namespace std;
int i = 0, n, qry, xx, a, b, c, x, sum = 0, best = 0;

// https://cses.fi/problemset/task/2166/

int process(int array[], int k){

    for (int k = 0; k < n; k++) {
        sum = max(array[k],sum+array[k]);
        best = max(best,sum);
    }
    return best;
}

int main(){

    cin >> n >> qry;
    vector<int> ans;
    int array[n];
    xx = n;
    
    while (n--){
        cin >> x;
        array[i] = x;
        ++i;
    }

    while (qry--){
        cin >> a >> b >> c;
        if (a == 1)
            array[b] = c;
        else{
            int k = c-b-1;
            int temp[k];
            int p = 0;
            for (i = b; i < c; ++i){
                temp[p] = array[i]; 
                ++p;
            }
            ans.push_back(process(temp,k));
        }
    }

    for (auto i : ans) cout << i << '\n';
    
    return EXIT_SUCCESS;
}