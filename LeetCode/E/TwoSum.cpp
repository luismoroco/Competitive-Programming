#include <bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {

    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); ++i){
        int x = target -  nums[i];
        if (mp.find(x) != mp.end()) return {mp[x] , i};
        mp[nums[i]] = i;
    }
    return {};
}

int main(int argc, char const *argv[])
{
    vector<int> x = {3, 2, 4};
    vector<int> res = twoSum(x, 6);

    return 0;
}
