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
    
    int64_t ans = 0, iter = arr[0].size(), a, b;
    for (int i = 1; i < N; ++i) {
      a = arr[i-1].size(), b = arr[i].size();
      if (a < b) {
        iter = b;
        continue;
      } 
      if (a == b) {
        if (stoi(arr[i-1]) < stoi(arr[i])) {
          continue;
        } else {
          arr[i] += '0';
          iter++, ans++;
        }
      }
      if (a > b) {
        int8_t t = a-b+1, it = 0;
        while(it <= t) {
          if (stoi(arr[i-1]) < stoi(arr[i])) {
            ans += it;
            break;
          }
          arr[i] += '0';
          iter++;
          it++;
        }
      }
    }
    
    printf("Case #%d: %d\n", i, ans);
  }

  return 0;
}