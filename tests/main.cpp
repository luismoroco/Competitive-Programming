#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 110;

int E, W;
int amt[MAXN][MAXN];
int dp[MAXN][MAXN];

int ctot[MAXN];
int ntot[MAXN];

void gogo()
{
    cin >> E >> W;
    for (int i = 0; i < E; i++)
        for (int j = 0; j < W; j++)
        {
            cin >> amt[i][j];
        }

    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            dp[i][j] = -1e9;

    for (int i = 0; i < E; i++)
        dp[i][i] = 0;

    for (int i = 0; i < E; i++)
    {
        for (int j = 0; j < W; j++)
            ctot[j] = amt[i][j];

        for (int j = i - 1; j >= 0; j--)
        {
            for (int k = 0; k < W; k++)
                ctot[k] = min (ctot[k], amt[j][k]);

            for (int k = 0; k < W; k++)
                ntot[k] = amt[j][k];
            for (int k = j; k >= 0; k--)
            {
                for (int l = 0; l < W; l++)
                    ntot[l] = min (ntot[l], amt[k][l]);
                int tt = 0;
                for (int l = 0; l < W; l++)
                    tt += min (ctot[l], ntot[l]);
                dp[k][i] = max (dp[k][i], dp[k][j] + dp[j+1][i] + tt);
            }
        }
    }

    int tot = dp[0][E-1];
    int cc = 0;
    for (int i = 0; i < E; i++)
        for (int j = 0; j < W; j++)
            cc += 2 * amt[i][j];
    cout << cc - 2 * tot << "\n";
}

int main()
{
    int T; cin >> T;

    for (int t = 0; t < T; t++)
    {
        cout << "Case #" << t + 1 << ": ";
        gogo();
    }
}