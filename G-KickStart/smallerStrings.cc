#include <bits/stdc++.h>
using namespace std;

const int MOD = (int) 1e9 + 7;
int64_t P[27][100005];
string s, r;

void run() {
  int n, k;
  cin >> n >> k >> s;
  r = s;
  int64_t ans = 0;
  



}

int main(int, char**) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 1; i <= 26; i++) {
    P[i][0] = 1;
    for (int j = 1; j <= 100000; j++) {
      P[i][j] = P[i][j - 1] * i % MOD;
    }
  }

  int T; 
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": "; run();
  }

  return 0;
}
