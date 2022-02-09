#include <bits/stdc++.h>

using namespace std;

void miniMaxSum(vector<int> arr) {

    priority_queue<int, vector<int>, greater<int>> mini;
    priority_queue<int> max;
    for (int i = 0; i < arr.size(); ++i){ mini.push(arr[i]); max.push(arr[i]);}

    long long  ma = 0, mi = 0;
    for (int i = 0; i < 4; ++i) {
        ma += max.top(); max.pop();
        mi += mini.top(); mini.pop();
    }

    cout << mi << ' ' << ma << '\n'; 
}

int main(int argc, char const *argv[])
{
    miniMaxSum({256741038, 623958417, 467905213, 714532089, 938071625});
    
    return 0;
}
