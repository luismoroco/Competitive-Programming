#include <bits/stdc++.h>
using namespace std;

// https://www.beecrowd.com.br/judge/es/problems/view/2792

typedef long long ll;
typedef vector<ll> vl;
#define MAX 500005

int 
Fx(vl &v, ll x){
    ll ans = 0;
    while(x > 0){
        ans += v[x];
        x -= x & (-x);
    }
    return ans;
}

int 
main(int argc, char const *argv[])
{
    ll N, input, i;
    cin >> N;
    vl v(MAX, 0);
    for(i = 1; i <= N; i++){
        cin >> input;
        cout << (input - Fx(v, input));
        if(i == N) cout << endl;
        else cout << " ";
        while (input < MAX){
            v[input] += 1;
            input += input & (-input);
        } 
    }

    return 0;
}

