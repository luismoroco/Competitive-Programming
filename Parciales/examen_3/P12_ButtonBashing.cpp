#include <bits/stdc++.h>
using namespace std;

# define INFINITE 1000000000
const int SECONDS = 3600;

typedef queue<int> qi;
typedef vector<int> vi;


void 
Solution(qi &q, vi &DISTANCES, vi &BUFF)
{
    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        for(auto& i : BUFF) {
            int next = curr + i;
            next = max(0,next);
            next = min(SECONDS,next);

            if(DISTANCES[next] > DISTANCES[curr]+1) {
                DISTANCES[next] = DISTANCES[curr]+1;
                q.push(next);
            }
        }
    }
}

int 
main(int argc, char const *argv[]) 
{
    int n;
    cin >> n;
    while(n--) {
        int n, m;
        cin >> n >> m;
        vi BUFF(n);
        for(auto& i : BUFF) {cin >> i;}
        vi DISTANCES(SECONDS + 1, INFINITE);
        DISTANCES[0] = 0;
        qi q;
        q.push(0);
        Solution(q, DISTANCES, BUFF);
        for(int i = m; i <= SECONDS; i++) {
            if(DISTANCES[i] != INFINITE) { cout << DISTANCES[i] << " " << i - m << endl; break;}
        }
    }

    return EXIT_SUCCESS;
}