#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n; 

  int mat[n][n];
  int dp[n + 1][n + 1];
  
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> mat[i][j];
    }
  }
  
  int acc = 0;  
  for (int i = 0; i < n; ++i) {
    acc += mat[0][i];
    dp[0][i] = acc; 
  }

  acc = 0;
  for (int i = 0; i < n; ++i) {
    acc += mat[i][0];
    dp[i][0] = acc; 
  }

  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < n; ++j) {
      dp[i][j] = std::min({dp[i - 1][j] + mat[i][j], dp[i][j - 1] + mat[i][j]});
    }
  }

  printf("%d\t", dp[n - 1][n - 1]);

  return 0;
}

/*

3
1 2 1 
4 1 3
2 1 1

*/