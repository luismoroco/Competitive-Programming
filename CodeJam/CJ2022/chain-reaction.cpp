#include <bits/stdc++.h>
#define cpu()                  \
  ios::sync_with_stdio(false); \
  cin.tie(nullptr)
#define pb push_back
#define ff first
#define ss second

typedef long long ll;

using namespace std;

const int MOD = 1e9 + 7, MOD1 = (119 << 23) | 1;
const int INF = 2e9 + 5, MAX = 1e5 + 5;
vector<int> d[MAX];
ll f[MAX];
pair<ll, ll> dp[MAX];

void dfs(int u = 0)
{
  dp[u] = {0, INF};
  ll mn = INF;
  for (int it : d[u])
  {
    dfs(it);
    if (dp[it].ss < mn)
    {
      mn = dp[it].ss;
    }
    dp[u].ff += dp[it].ff;
  }
  if (mn == INF)
  {
    mn = 0;
  }
  dp[u].ss = max(mn, f[u]);
  dp[u].ff += max(f[u] - mn, 0LL); // here
}

void solve()
{
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> f[i];
  }
  for (int i = 1; i <= n; i++)
  {
    int x;
    cin >> x;
    d[x].push_back(i);
  }
  dfs();
  cout << dp[0].ff << "\n";
  for (int i = 0; i <= n; i++)
  {
    vector<int>().swap(d[i]);
  }
}

int main()
{
  cpu();
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}