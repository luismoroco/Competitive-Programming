#include <bits/stdc++.h>
using namespace std;

// https://open.kattis.com/problems/bachetsgame

#define MAX_LEN 1000000

int 
comparator(const void* a, const void* b){ return *((int*)a) - *((int*)b);}

int main()
{
    char pos[MAX_LEN + 1];
    pos[0] = 'P';
    int n, s;
    while(scanf("%d %d",&n,&s) == 2)
    {
        int arr[s];
        for (int i = 0; i < s; i++) scanf("%d", arr + i);
        qsort(arr, (size_t)s, sizeof(int), comparator);
        memset(pos + 1, 0, MAX_LEN * sizeof(char));
        for (int i = 0; i <= n; i++){
            if (pos[i] == 0) pos[i] = 'P';
            if (pos[i] == 'P'){
                if (i < MAX_LEN - arr[s-1]){
                    for (int j = 0; j < s; j++) pos[i + arr[j]] = 'N';
                }
                else{
                    for (int j = 0; j < s; j++){
                        if (i + arr[j] <= MAX_LEN) pos[i + arr[j]] = 'N';
                    }
                }
            }
        }

        if (pos[n] == 'N') cout << "Stan wins\n";
        else cout << "Ollie wins\n";
    }
    return 0;
}