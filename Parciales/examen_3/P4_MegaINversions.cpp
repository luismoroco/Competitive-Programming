#include <bits/stdc++.h>
using namespace std;

// https://open.kattis.com/problems/megainversions

typedef long long int ll;
typedef vector<ll> vl;

void 
Increment(vl &f, ll i, ll d) 
{
    for(; i < f.size(); i |= i+1) f[i] += d;
}

ll 
Count_i_down(vl &f, ll i) 
{
    ll total = 0;
    for(; i > 0; i &= i-1) total += f[i-1];
    return total;
}

ll Count_i_top(vl &f, ll i) { return Count_i_down(f, f.size()) - Count_i_down(f, i);}

int main(int argc, char const *argv[]) 
{
    ll LENGHT;
    cin >> LENGHT;
    vl BUFF1(LENGHT+1,0), BUFF2(LENGHT+1,0), BUFF3(LENGHT+1,0);

    while(LENGHT--) {
        ll num;
        cin >> num;
        ll s1 = Count_i_top(BUFF1, num+1);
        ll s2 = Count_i_top(BUFF2, num+1);
        Increment(BUFF1, num, 1);
        Increment(BUFF2, num, s1);
        Increment(BUFF3, num, s2);
    }

    cout << Count_i_top(BUFF3, 0) << '\n';

    return EXIT_SUCCESS;
}