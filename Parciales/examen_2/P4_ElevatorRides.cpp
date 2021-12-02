#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vll;
ll k, tar;
vll dp;

ll 
Fx(vl &persons, ll taken, ll total)
{
    if(taken == tar) 
        return 0;
    if(dp[taken][total] != -1) 
        return dp[taken][total];
    
    bool notused = false;
    ll ans = INT_MAX;
    for(ll i = 0; i < persons.size(); ++i){
        if(taken&(1 << i)) 
            continue;
        if(persons[i] > total) 
            continue;
        
        notused = true;
        taken ^= (1 << i);
        ans = min(ans, Fx(persons, taken, total - persons[i]));
        taken ^= (1 << i);
    }
    if(!notused)
        return dp[taken][total] = 1 + Fx(persons,taken,k);
    
    return dp[taken][total] = ans;
}

ll 
solve(vl &persons, ll maxCapacity) {
    k = maxCapacity;
    tar = 0;
        
    for(ll i = 0; i < persons.size(); ++i)
        tar ^= (1 << i);

    dp.resize(tar+1, vl(k + 1,-1));
    return 1 + Fx(persons, 0, k);
}

int 
main(ll argc, char const *argv[])
{
    ll n, m, x;
    cin >> n >> m;
    vl persons;
    while (n--){
        cin >> x;
        persons.push_back(x);
    }
    cout << solve(persons, m) << '\n';

    return 0;
}