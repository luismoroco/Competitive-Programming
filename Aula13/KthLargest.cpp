// https://leetcode.com/problems/kth-largest-element-in-an-array/

#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> temp;
    int i;
    for ( int it : nums) temp.push(it);
    for (i = 1; i < k; i++) temp.pop();
    return temp.top();
}

int main(){
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    int k = 4;
    findKthLargest(nums, k);
    
    return 0;
}
