#include <bits/stdc++.h>
using namespace std;

int main(){

    int N, k, l, r, i;
    cin >> N >> k;
    vector<int> dif(N+1, 0);

    while (k--){
        cin >> l >> r;
        l--;
        ++dif[l];--dif[r];
    }
 
    for (i = 1; i < N; i++){
        dif[i] += dif[i-1];
    }

    sort(dif.begin(), dif.end());
    cout << dif[N/2] << '\n'; 
    
    return 0;
}