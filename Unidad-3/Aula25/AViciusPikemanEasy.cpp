#include <bits/stdc++.h>
using namespace std;

// https://open.kattis.com/problems/pikemaneasy

typedef long long int ll;
ll ARRA[10000];

int 
COMPARATION(const void *p, const void *q) {
    int *a = (int *) p;
    int *b = (int *) q;
    return *a - *b;
}

int 
main(int argc, char const *argv[])
{
    ll x, y, z, m, n, o = 0 ,p = 0, l = 0, i;
    cin >> x >> y >> z >> m >> n >> ARRA[0];
    for (i = 1; i < x; ++i){
        ARRA[i] = (z * ARRA[i-1] + m) % n + 1;
    }
    qsort(ARRA, x, sizeof(ll), COMPARATION);
    for (i = 0; i < x; ++i){
        if (l + ARRA[i] <= y){
            o = (o + ARRA[i] + l) % 1000000007;
            l += ARRA[i]; p++;
        } else break;
    }
    cout << p << " " << o << '\n';

    return 0;
}