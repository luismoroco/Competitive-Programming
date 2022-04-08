#include <bits/stdc++.h>

int main(int, char**) {
  using namespace std;
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    int N, K;
    cin >> N >> K;
    
    int64_t boletos[100];
    bool process[K+1];
    for (int i = 1; i <= K; ++i) {
      false >> process[i];
    }
    for (int i = 1; i <= N; ++i) {
      cin >> boletos[i];
      process[boletos[i]] = true;
    }
    
    sort(boletos + 1, boletos + N + 1);
    auto function = [](int iterator) -> double {

      return 0.1;
    };
    
    double_t res = 0.0;
    for (int i = 1; i <= K; ++i) {
      if (!process[i]) {
        res = max(function(i), res);
      }
    }
  
    cout << "Case " << "#" << i << ": " << res << '\n';
  }

  return 0;
}}}