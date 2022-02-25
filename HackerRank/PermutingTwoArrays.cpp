#include <bits/stdc++.h>

using namespace std;

string twoArrays(int k, vector<int> A, vector<int> B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    bool state = true;
    for (size_t i = 0; i < A.size(); i++){
        if (A[i] + B[A.size()-1-i] < k) {
            state = false;
            break;
        }
    }
    
    return (state)? "YES" : "NO";
}

int main(int argc, char const *argv[]) {

    cout << (twoArrays(1, {0, 1}, {0, 2}));

    return 0;
}
