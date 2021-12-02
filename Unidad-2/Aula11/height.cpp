// https://www.beecrowd.com.br/judge/en/problems/view/1566

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int N, nx, x, e;
    cin >> N;
    vector<vector<int>> res;
    while (N--)
    {
        cin >> nx;
        priority_queue<int,vector<int>,greater<int>> temp;
        vector<int> ax;
        while (nx--)
        {
            cin >> x;
            temp.push(x);
        }
        
        while (!temp.empty())
        {
            e = temp.top(); 
            ax.push_back(e);
            temp.pop();
        }

        res.push_back(ax);
    }

    for (x = 0; x < res.size(); ++x){
        for (e = 0; e < res[x].size(); ++e){
            cout << res[x][e] << ' ';
        }
        cout << '\n';
    }
    
    
    return 0;
}
