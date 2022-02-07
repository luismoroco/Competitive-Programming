#include <bits/stdc++.h>
 
using namespace std;
 
int main(int argc, char const *argv[])
{
    int n, x, sum = 0; 
    cin >> n;
    priority_queue<int> mon;
    while (n--){
        cin >> x;
        sum += x;
        mon.push(x);
    }
 
    int count = 0, tmp = 0;
    while (!mon.empty()){
        if (tmp > sum/2) break;
        tmp += mon.top();
        mon.pop();
        ++count;
    }
 
    cout << count << '\n';
 
    return EXIT_SUCCESS;
}