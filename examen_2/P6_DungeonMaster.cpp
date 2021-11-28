#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<char>>& dungeon, int i, int j, int level, int& min_time){
    if(i < 0 || i >= dungeon.size() || j < 0 || j >= dungeon[0].size() || dungeon[i][j] == '#') return;
    if(dungeon[i][j] == 'E'){
        min_time = min(min_time, level);
        return;
    }
    dungeon[i][j] = '#';
    solve(dungeon, i+1, j, level+1, min_time);
    solve(dungeon, i-1, j, level+1, min_time);
    solve(dungeon, i, j+1, level+1, min_time);
    solve(dungeon, i, j-1, level+1, min_time);
    dungeon[i][j] = '.';
}

int main(int argc, char const *argv[])
{
    int n, m, k;
    while(cin >> n >> m >> k && n != 0 && m != 0 && k != 0){
        int min_time = k;
        vector<vector<char>> dungeon(n, vector<char>(m, '.'));
        while(n--){
            for(int i = 0; i < m; i++){
                string s;
                cin >> s;
                for(int j = 0; j < s.size(); j++){
                    dungeon[i][j] = s[j];
                }
            }
        }
        solve(dungeon, 0, 0, 0, min_time);
        cout << min_time << endl;
        if(min_time == k) cout << "Trapped!" << endl;
        else cout << "Escaped in " << min_time << " minute(s)." << endl;
    }
    return 0;
}