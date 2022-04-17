#include <iostream>
using namespace std;

const int M = 3;
pair<string, uint64_t> arr[M]; 
uint64_t N, Q;

void function() {
    cin >> N >> Q;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i].first >> arr[i].second;
    }
    
    
}

int main(int, char**) {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": "; function();
  }

  return 0;
}