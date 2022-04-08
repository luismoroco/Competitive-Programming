#include <bits/stdc++.h>

int main(int, char**) {
  using namespace std;
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  
  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    int N;
    cin >> N;
    string arr[N];
    for (string& iter : arr) {
      cin >> iter;
    }

    auto searchBest = [](int x, string str) -> string {
      while (true) {
        for (int i = 0; i <= 9; ++i) {
          str.push_back(i+'0');
          if (x < stoll(str)) {
            return str;
          }
          str.pop_back();
        }
        str += '0';
      }
    };
    
    int64_t ans = 0, iter = arr[0].size(), a, b;
    for (int i = 0; i < N - 1; ++i) {
      a = arr[i].size(), b = arr[i+1].size();
      if (a < b) {
        iter = b;
        continue;
      }
      if (a == b) {
        if (stoll(arr[i]) < stoll(arr[i+1])) {
          iter = b;
          continue;
        } else {
          string state = searchBest(stoll(arr[i]), arr[i+1]);
          ans += (state.size() - arr[i+1].size());
          iter = state.size();
          arr[i+1] = state;
          continue;
        }
      }
      if (a > b) {
        string state = searchBest(stoll(arr[i]), arr[i+1]);
        ans += (state.size() - arr[i+1].size());
        iter = state.size();
        arr[i+1] = state;
        continue;
      }
    }
    
    printf("Case #%d: %d\n", i, ans);
  }

  auto searchBest = [](int x, string str) -> string {
    while (true) {
      for (int i = 0; i <= 9; ++i) {
        str.push_back(i+'0');
        if (x < stoll(str)) {
          return str;
        }
        str.pop_back();
      }
      str += '0';
    }
  };

  return 0;
}