#include <bits/stdc++.h>
using namespace std;

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
            cont++;
    }
    cout << cont;

    return EXIT_SUCCESS;
}
