#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1 << 12;
const double PI = 2 * acos(0.0);

int main(int, char**) {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  /* When there is number of data
  int TC, a, b;
  cin >> TC;
  while (TC--) {
    cin >> a >> b;
    printf("%d\n", a + b);
  }
  */

  /* when the end is 0 0
  int a, b; 
  while (scanf("%d %d", &a, &b), (a || b)) {
    printf("%d", a + b);
  }
  */
  
  int a, b;
  while (scanf("%d %d", &a, &b) != EOF) {
    printf("%d\n", a + b);
  }
  
  

  return 0;
}