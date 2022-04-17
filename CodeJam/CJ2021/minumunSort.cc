#include <iostream>
#include <cassert>
using namespace std;

uint64_t N;

void function() {
  int min;
  for (int i = 1; i < N; ++i) {
    printf("M %d %d\n", i, N);
    fflush(stdout);
    cin >> min;
    if (min == i) {
      continue;
    }
    
    printf("S %d %d\n", i, min);
    fflush(stdout);
    cin >> min;
    assert(min == 1);
  }
  
  printf("D\n");
  fflush(stdout);
  cin >> min;
  assert(min == 1);
}

int main(int, char**) {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int T;
  cin >> T >> N;
  for (int i = 1; i <= T; ++i) {
    function();
  }

  return 0;
}