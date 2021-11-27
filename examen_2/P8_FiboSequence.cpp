#include <bits/stdc++.h>
using namespace std;

// https://www.beecrowd.com.br/judge/en/problems/view/1701

typedef long long ll;

ll 
pisano(ll m)
{
    ll prev = 0;
    ll curr = 1;
    ll res = 0;
 
    for(int i = 0; i < m * m; i++)
    {
        ll temp = 0;
        temp = curr;
        curr = (prev + curr) % m;
        prev = temp;
 
        if (prev == 0 && curr == 1)
            res = i + 1;
    }
    return res;
}
 
ll 
fibonacciModulo(ll n, ll m)
{
    ll pisanoPeriod = pisano(m);
    n = n % pisanoPeriod;
    ll prev = 0;
    ll curr = 1;
 
    if (n == 0) return 0;
    else if (n == 1) return 1;
 
    for(ll i = 0; i < n - 1; ++i)
    {
        ll temp = 0;
        temp = curr;
        curr = (prev + curr) % m;
        prev = temp;
    }
    return curr % m;
}

void 
solve(ll a, ll b, ll n)
{
    ll num = 0;
    for(ll cont = -1; cont < n; cont++)
        num += fibonacciModulo(a + cont + 1, 1000000007) * fibonacciModulo(b + cont + 1, 1000000007);
    cout << num << '\n';
}

int 
main(int argc, char const *argv[])
{
    ll a, b, n;
   /* 
    cin >> a >> b >> n;
    solve(a, b, n);
    */
    cout << fibonacciModulo(1548276540, 235);
    return 0;
}
