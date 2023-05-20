#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1 << 12;
const double PI = 2 * acos(0.0);

int main(int, char**) {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  
  string x;
  cin >> x;

  int n = x.length();

  if (n == 1) {
    printf("%d\n", n);
    return 0;
  }

  bool dp[n][n];
  memset(dp, false, sizeof(dp));

  int i;
  for (i = 0; i < n; ++i) dp[i][i] = true;

  int begin = 0, maxLength = 1;
  for (i = 0; i < n - 1; ++i) {
    if (x[i] == x[i + 1]) {
      dp[i][i + 1] = true;
      begin = i;
      maxLength = 2;
    }
  }
  
  int k; 
  for (k = 3; k <= n; ++k) {
    for (i = 0; i < n - k + 1; ++i) {
      int j = i + k - 1;
      
      if (dp[i + 1][j - 1] && x[i] == x[j]) {
        dp[i][j] = true;

        if (k > maxLength) {
          begin = i;
          maxLength = k;
        } 
      } 

    }
  }

  cout << x.substr(begin, maxLength) << '\n';

  return 0;
}