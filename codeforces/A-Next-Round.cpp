#include <bits/stdc++.h>

using namespace std;

int n, k, i, x;
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    int notas[n];
    
    i = 0;
    while (n--){
        cin >> x;
        notas[i] = x;
        ++i;
    }
 
    int cont = 0;
    int pivote = notas[k-1];
    for ( auto i : notas){
        if ((i >= pivote) && i != 0) ++cont;
        else continue;
    }
    cout << cont << '\n';
 
    return EXIT_SUCCESS;
}