#include <bits/stdc++.h>
using namespace std;

// https://open.kattis.com/problems/stringmatching

const int NTT =  100010;
typedef int long long ll;

char T[NTT], P[NTT];
ll b[NTT], n, m;

int 
main(int argc, char const *argv[])
{
    ll i, j;
    while (1){
        cin.getline(P, NTT); m= strlen(P);
        cin.getline(T, NTT); n= strlen(T);
        i = 0, j = -1; b[0] = -1;
        while( i < m ){
            while( j >= 0 && P[i] != P[j] ) j = b[j];
            i++; j++; b[i] = j;
        } 
        i = 0, j = 0;
        while( i < n ){
            while( j >= 0 && T[i] != P[j] ) j = b[j];
            i++; j++;
            if( j == m ){
                cout <<  i-j  << " ";
                j = b[j];
            }
        }
        cout << '\n';
    }

    return 0;
}