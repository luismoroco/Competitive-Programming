#include <bits/stdc++.h>

using namespace std;

const int N = 1000000 + 5;

void print(vector<int> x) {
    for (int i : x) {
        cout << i << ' ';
    }
    cout << '\n';
}

int main(int, char**) {
    vector<int> vi = {2,3,4,5};
    
    int it = 0;
    while (it < vi.size()) {
        print(vi);
        int bf = vi.back();
        vi.pop_back();
        vi.insert(vi.begin(), bf);
        ++it;
    }
    cout << "GOZU\n";


    return 0;
}