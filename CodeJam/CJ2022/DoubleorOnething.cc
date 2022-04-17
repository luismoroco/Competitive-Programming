#include <bits/stdc++.h>
using namespace std;

void run() {
  string arr, ans;
  cin >> arr;
  
  int n = arr.length();
  for (int i = 0, j = 0; i < n; i++) {
    while (j < n && arr[i] == arr[j]) {
      j++;
    }
    ans += arr[i];
    if (j < n && arr[j] > arr[i]) {
      ans += arr[i];
    }
  }

  cout << ans << '\n';
}

int main(int, char**) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": "; run();
  }

  return 0;
}