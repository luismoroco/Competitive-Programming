#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/asteroid-collision/

vector<int> asteroidCollision(vector<int>& asteroids) 
{
    vector<int> row;
    int x, y;
    for (size_t i = 0; i < asteroids.size(); ++i)
    {
        x = asteroids[i];
        y = asteroids[i+1];
        if (x > 0 && y > 0){row.push_back(x);}
        else if (x < 0 && y < 0){row.push_back(x);}
        else if (x < 0 && y > 0){
            int marx = max(abs(x), abs(y));
            row.push_back(marx);
        }
        else if (x > 0 && y < 0){
            if (abs(x) != abs(y)){
                int marx = max(abs(x), abs(y));
                row.push_back(marx);
            }
            else{continue;}
        }
    }

    for (int it : row) cout << it << ' ';
    
    return row;
    
}

int main(int argc, char const *argv[])
{
    vector<int> x = {8, -8};
    asteroidCollision(x);

    return 0;
}
