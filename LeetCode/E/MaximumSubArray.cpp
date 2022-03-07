#include <bits/stdc++.h>

using namespace std;

int maxSubArray(vector<int> nums) {
    if (nums.size()) return nums[0];
    int res = nums[0], sum = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        sum = max(nums[i], sum + nums[i]); 
        res = max(res, sum);
    }
    return res;
}

int main(int argc, char const *argv[]) {
    cout << maxSubArray({1}) << '\n';

    return 0;
}
