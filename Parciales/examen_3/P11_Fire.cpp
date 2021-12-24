#include <bits/stdc++.h>
using namespace std;

// https://open.kattis.com/problems/fire2

typedef long long int ll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef queue<pair<int,int>> qpii;

ll n, m;
bool FXX1(ll x, ll y) {return x >= 0 && x <= n+1 && y >= 0 && y <= m+1;}
bool FXX2(ll x, ll y) {return x >= 1 && x <= n && y >= 1 && y <= m;}

void BFFS(vvc &v, qpii &oldq, qpii &newq, bool fire) 
{
    vector<pair<int,int>> movement = {{1,0},{-1,0},{0,1},{0,-1}};
    while(!oldq.empty()) {
        int currx = oldq.front().first;
        int curry = oldq.front().second;
        oldq.pop();
        for(auto i : movement) {
            int nextx = currx + i.first;
            int nexty = curry + i.second;
            if(fire) {
                if(FXX2(nextx,nexty)) {
                    if(v[nextx][nexty] == '.' || v[nextx][nexty] == '@') {
                        v[nextx][nexty] = '*';
                        newq.push({nextx,nexty});
                    }
                }
            }
            else {
                if(FXX1(nextx,nexty)) {
                    if(v[nextx][nexty] == '.') {
                        v[nextx][nexty] = '@';
                        newq.push({nextx,nexty});
                    }
                }
            }
        }
    }
}

void isingrig(vvc &v, qpii &guys) 
{
    qpii newguys;
    while(!guys.empty()) {
        pair<int,int> i = guys.front();
        guys.pop();
        if(v[i.first][i.second] != '*') {
            newguys.push(i);
        }
    }
    guys = newguys;
}

int main(int argc, char const *argv[])
{
    ll cases;
    cin >> cases;
    while(cases--) {
        cin >> m >> n;
        vvc v(n+2, vc(m+2, '.'));
        for(ll i = 1; i <= n; i++) {
            for(ll j = 1; j <= m; j++) {
                cin >> v[i][j];
            }
        }
        qpii guys, fire;
        for(ll i = 1; i <= n; i++) {
            for(ll j = 1; j <= m; j++) {
                if(v[i][j] == '@') {
                    guys.push({i,j});
                }
                else if(v[i][j] == '*') {
                    fire.push({i,j});
                }
            }
        }

        ll time = 0;
        bool works = false;
        while(!fire.empty() || !guys.empty()){
            qpii newguys, newfire;
            BFFS(v, guys, newguys, false);
            BFFS(v, fire, newfire, true);
            for (int i = 0; i < n+2; ++i) if (v[i][0] == '@' || v[i][m+1] == '@') works = true;
            for (int i = 0; i < m+2; ++i) if (v[0][i] == '@' || v[n+1][i] == '@') works = true;
            isingrig(v, newguys);
            guys = newguys; fire = newfire; ++time;
            if (works == true) break;
        }

        if (works == true) cout << time << '\n';
        else cout << "IMPOSSIBLE\n";
    }

    return EXIT_SUCCESS;
}