#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/keys-and-rooms/

typedef vector<bool> vb;
typedef vector<vector<int>> vii;

void DFS(vb &visited, vii &rooms, int s, int &count){
    visited[s] = true;
    ++count;
    for (int it : rooms[s]){
        if (visited[it] == false) DFS(visited, rooms, it, count);
    }
}

bool canVisitAllRooms(vii &rooms){
    int n = rooms.size();
    int res = 0;

    vb visited(n, false);
    visited[0] = true;
    DFS(visited, rooms, 0, res);
    
    return (res == n);
}

int main(int argc, char const *argv[])
{
    vii x = {{1,3},{3,0,1},{2},{0}};
    cout << canVisitAllRooms(x);

    return 0;
}
