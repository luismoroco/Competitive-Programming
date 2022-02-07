#include <bits/stdc++.h>


using namespace std;


int main(int argc, char const *argv[])
{
    int n; 
    cin >> n; 

    vector<vector<int>> dis(n+1, vector<int>(n+1));

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> dis[i][j];
        }
    }

    long long int base = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = i + 1; j <= n; ++j)
            base += dis[i][j];
    }

    int k; 
    cin >> k;

    for (int i = 0; i < k; ++i){

        int a, b, c;
        cin >> a >> b >> c;

        if (dis[a][b] < c){
            cout << base << ' '; continue;
        }

        dis[a][b] = c;
        dis[b][a] = c;
        
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= n; ++j){
                dis[i][j] = min(dis[i][j], dis[i][a]+dis[a][j]);
            }
        }       

        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= n; ++j){
                dis[i][j] = min(dis[i][j], dis[i][b]+dis[b][j]);
            }
        }

        long long int sum = 0;
        for (int i = 1; i <= n; ++i){
            for (int j = i + 1; j <= n; ++j)
                sum += dis[i][j];
        }
        
        base = min(base, sum);
        cout << base << ' ';
    }


    return EXIT_SUCCESS;
}