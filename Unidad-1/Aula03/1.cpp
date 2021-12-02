#include <bits/stdc++.h>
using namespace std;

// números divisibles por 'K'

/*
    7 3
    1
    51
    966369
    7
    9
    999996
    11

    outuput = 4 
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, num, cont = 0;
    cin >> n >> k;

    while (n--)
    {
        cin >> num;
        if (num % k == 0)
            ++cont;
    }
    cout << cont << '\n';

    return EXIT_SUCCESS;
}
