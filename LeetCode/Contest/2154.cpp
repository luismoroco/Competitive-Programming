#include <bits/stdc++.h>

using namespace std;

int findFinalValue(vector<int> nums, int original) {
    unordered_multiset<int> mp;
    for (int i = 0; i < nums.size(); ++i) {
        mp.insert(nums[i]);
    }

    while (mp.find(original) != mp.end()) {
        original *= 2;
    }
    
    return original;
} 

int main(int argc, char const *argv[]){
    cout << findFinalValue({8, 19, 4, 2, 15, 3}, 2) << '\n';

    return 0;
}
