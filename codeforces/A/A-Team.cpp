#include <bits/stdc++.h>

using namespace std;

int n, x, y, z, cont = 0;
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    while (n--){
        cin >> x >> y >> z;
        if ((x + y + z) >= 2)
            ++cont;
    }
    cout << cont << '\n';
 
    return EXIT_SUCCESS;
}