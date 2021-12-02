#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int N, M;
        queue<pair<int, int>> q;
        int paths[100][100];
        pair<int, int> from[100][100];
        int oo = INT_MAX;
        pair<int, int> A;
        string ans;
        bool possible = false;

        Solution(int n, int m){
            memset(paths, 0, sizeof(paths));
            memset(from, 0, sizeof(from));
            N = n;
            M = m;
        }

        void 
        retrace(pair<int, int> node){  
            pair<int, int> origin = from[node.first][node.second];
            if(origin ==  pair<int, int>(0,0)) return;
            if(origin.first == node.first+1) ans.push_back('U');
            if(origin.first == node.first-1) ans.push_back('D');
            if(origin.second == node.second+1) ans.push_back('L');
            if(origin.second == node.second-1) ans.push_back('R');
            retrace(origin);
        }

        void 
        check(pair<int, int> origin, pair<int, int> dest){ // check if the considered destination may be traveled to
            int pl = paths[origin.first][origin.second];
            if(pl+1<paths[dest.first][dest.second]){
                paths[dest.first][dest.second]  = pl+1;
                q.push(dest);
                from[dest.first][dest.second] = origin;
            }
        }

        bool mora = false; 
        void 
        bfs(){
            while(!q.empty()){ 
                pair<int, int> loc = q.front(), next; q.pop();
                next = loc; next.first++; check(loc, next); // go through adjacent locations
                next = loc; next.first--; check(loc, next);
                next = loc; next.second++; check(loc, next);
                next = loc; next.second--; check(loc, next);
                if(mora && (loc.first == 1 || loc.second == 1 || loc.first == N || loc.second == M)){
                    cout << "YES" << endl;
                    cout << paths[loc.first][loc.second] << endl;
                    retrace(loc);
                    possible = true;
                    return;
                }
            }
        }
};

int 
main(int argc, char const *argv[])
{
    int x, y;
    cin >> x >> y;
    Solution sol(x, y);
    for(int i = 1; i <= sol.N; i++){
        string s;
        cin >> s;
        for(int j = 1; j <= sol.M; j++){
            sol.paths[i][j] = sol.oo;
            if(s[j-1] == '#') sol.paths[i][j] = 0;
            if(s[j-1] == 'M') {sol.q.push(make_pair(i,j)); sol.paths[i][j] = 0;}
            if(s[j-1] == 'A') {sol.A.first = i; sol.A.second = j;}
        }
    }
    sol.bfs();
    sol.mora = true; 
	sol.from[sol.A.first][sol.A.second] = pair<int, int>(0,0); 
	sol.paths[sol.A.first][sol.A.second] = 0; sol.q.push(sol.A); 
    sol.bfs();
    if(sol.possible){
        reverse(sol.ans.begin(), sol.ans.end());
        cout << sol.ans << endl;
    }
    else{
        cout << "NO\n";
    }

    return 0;
}