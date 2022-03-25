#include <bits/stdc++.h>

using namespace std;

const int N = 1000000 + 5;

int n, m;
char l[N], p[N];

bool f() {
    int it = 0;
    for (int i = 0; i < m; ++i) {
        if (l[it] == p[i]) ++it;
        if (it == n) return true; 
    }
    return false;
}

int main(int, char**) {
    int T, c = 1;
    scanf("%d", &T);
    while (T--){
        scanf("%s", &l);
        n = strlen(l);
        scanf("%s", &p);
        m = strlen(p);
        printf("Case #%d: ", c++);
        f()? printf("%d\n", m - n) : printf("IMPOSSIBLE\n"); 
    }
    
    return 0;
}