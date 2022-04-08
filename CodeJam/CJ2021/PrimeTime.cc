#include <iostream>
using namespace std;

const int K = 111;
const int M = 30303;
uint64_t arr[K][2], N;

bool processing(uint64_t prod, uint64_t sum) {
  for (int i = 0; i < N; ++i) {
    int contador = 0;
    while (prod % arr[i][0] == 0) {
      prod /= arr[i][0];
      sum -= arr[i][0];
      ++contador;
    } 
    if (contador > arr[i][1]) {
      return false;
    }
  }
  return prod == 1 && sum == 0;
}

uint64_t function() {
  cin >> N;
  uint64_t total = 0;
  for (int i = 0; i < N; ++i) {
    cin >> arr[i][0] >> arr[i][1];
    total += arr[i][0] * arr[i][1];
  }

  for (int k = 1; k < total && k < M; ++k) {
    if (processing(total - k, k)) {
      return total - k;
    } 
  }

  return 0;
}

int main(int, char**) {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    printf("Case #%d: %lld\n", i, function()); 
  }

  return 0;
}