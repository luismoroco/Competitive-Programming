// https://cses.fi/problemset/task/1645

/*
8
2 5 1 4 8 3 2 5

output : 
0 1 0 3 4 3 3 7
*/

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int N, x, i, n, j;
    cin >> N; n = N;
    int arr[N];

    i = 0;
    while (n--){
        cin >> x;
        arr[i] = x;
        ++i;
    }
    
    int min, pivote, cont;
    for (i = 0; i < N; ++i){
        min = arr[i]; pivote = i, cont = 0;
        while(pivote-- && pivote >= 0){ //!=
            ++cont;
            if (arr[pivote] < min){
                min = arr[pivote];
                break;
            }
        }
        cout << ++pivote << ' ';
    }

    return EXIT_SUCCESS;
}