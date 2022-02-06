#include <bits/stdc++.h>

using namespace std;

// https://open.kattis.com/problems/excursion

void Solution()
{
    vector<int> v = {0,0,0};
    int swaps = 0;
    
    string s;
    getline(cin, s);
    
    for (size_t i = 0; i < v.size(); i++){
        v[s[i]-'0']++;
    }
    
    for (size_t i = 0; i < v.size(); i++){
        if (i=='0'){
            v[0]--;
        }
        else{ 
            swaps += v[0];
        }
    }

    for (size_t i = 0; i < v.size(); i++)
    {
        if (i=='1'){
            v[1]--;
        }
        if (i=='2'){
            swaps += v[1];
        }
    }

}

int main(int argc, char const *argv[])
{
    Solution();     

    return 0;
}