// https://www.spoj.com/problems/CODFURY/
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

/*
Input:
1
4 50
20 5 23 45
Output:
48 3
*/

int main(){
    int t, p, m, x, i, sum;
    cin >> t;
    while(t--){
        priority_queue<pair<int, int>> pq;
        cin >> p >> m;
        int array[p];
        i = 0;
        while(i < p){
            cin >> x;
            array[i] = x;
            ++i;
        }
        sum = 0;
        for(i = 0; i < p; ++i){
            sum = max(array[i], sum + array[i]);
            if (sum <= m){pq.push(make_pair(i+1, sum));}
        }
        pair<int, int> top = pq.top();
        cout << top.second << ' ' << top.first << '\n';
    }
 
    return EXIT_SUCCESS;
}