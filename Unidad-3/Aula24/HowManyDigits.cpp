#include <bits/stdc++.h>
using namespace std;

// https://open.kattis.com/problems/howmanydigits

typedef long long int ll;
#define E 2.718281828459045235360287471352662497757247093699959574966967627724076630353
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286

int 
main(int argc, char const *argv[])
{
    ll n;
    while (scanf("%d",&n) == 1) {
        if (n < 2) { 
            cout << "1\n"; 
            continue; 
        }
        else{
            cout << (int)ceil(log10(2*PI*n)/2+n*(log10(n/E))) << '\n';
        }
    }
    
    return 0;
}