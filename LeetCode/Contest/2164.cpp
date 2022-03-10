#include <bits/stdc++.h>

using namespace std;

vector<int> sortEvenOdd(vector<int> nums) {
    priority_queue<int> ip;
    priority_queue<int, vector<int>, greater<int>> pr;
    for (int i = 0; i < nums.size(); ++i) {
        if (i % 2 == 0) pr.push(nums[i]);
        else ip.push(nums[i]);
    }
    vector<int> ans(nums.size());
    for (int i = 0; i < ans.size(); ++i) {
        if (i % 2 == 0) {ans[i] = pr.top(); pr.pop();}
        else {ans[i] = ip.top(); ip.pop();} 
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    sortEvenOdd({2, 1});
    return 0;
}
