#include <bits/stdc++.h>
using namespace std;

int LCS(string &P, string &Q, int n, int m)
{
    int result{};
    if (n == 0 or m == 0) result = 0;
    else if (P[n-1] == Q[m-1]) result = 1 + LCS(P, Q, n-1, m-1);
    else return max(LCS(P, Q, n-1, m), LCS(P, Q, n, m-1));
}

// tipo memorizacion

// tipo iterativo

int main(int argc, char const *argv[])
{
    string a = "abcdefghij";
    string b = "ecdgi";
    cout << LCS(a, b, 10, 5);

    return 0;
}
