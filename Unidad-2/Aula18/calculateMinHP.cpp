#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/dungeon-game/

typedef vector<vector<int>> vii;
typedef vector<int> vi;

int Function(vii &dungeon,int n, int m){
    vii sol(n + 1, vi(m + 1, INT_MAX));
    sol[n][m - 1] = 1;
    sol[n - 1][m] = 1;
    
    int temp;
    for(size_t i = n - 1; i >= 0; i--){
        for(size_t j = m - 1; j >= 0; j--){
            temp = min(sol[i + 1][j], sol[i][j + 1]) - dungeon[i][j];
            if (temp <= 0) sol[i][j] = 1;
            else sol[i][j] = temp;
        }
    }
    return sol[0][0];
}

int calculateMinimumHP(vii &dungeon) {
    int n = dungeon.size(), m = dungeon[0].size();
    cout << Function(dungeon, n, m);
}

int main(int argc, char const *argv[])
{
    vii x = {{-2,-3,3},{-5,-10,1},{10,30,-5}};
    calculateMinimumHP(x);

    return 0;
}













