#include <bits/stdc++.h>

using namespace std;

bool canJump(vector<int> nums) {
    int stp = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        stp--;
        if (stp < 0) return false;
        stp = (stp < nums[i])? nums[i] : stp;
    }
    return true;
}

int main(int argc, char const *argv[]) {
    cout << (canJump({2, 3, 1, 1, 4})) << '\n';

    return 0;
}
