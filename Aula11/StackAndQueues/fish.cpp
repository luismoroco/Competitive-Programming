#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, vector<int> &B){
    int i;
    vector<int> p;
    pair<int, int> x;
    queue<pair<int, int>> up, down;
    
    for (i = 0; i < A.size(); ++i){
        if(B[i] == 0) {up.push({A[i], i});}
        else {down.push({A[i], i});}
    }
    
    while (!down.empty() && !up.empty()){
        if(down.front().second > up.front().second){
            p.push_back(up.front().first);
            up.pop();
        }
        else if(down.front().first > up.front().first){
            up.pop();
        }
        else if(down.front().first < up.front().first){
            down.pop();
        }
    }

    return 1;
}


int main(){
    vector<int> A = {4, 3, 2, 1, 5};
    vector<int> B = {0, 1, 0, 0, 0};
    solve(A, B);
    cout << '\n';

    return 0;
}