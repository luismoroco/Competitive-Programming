// https://www.beecrowd.com.br/judge/en/problems/view/1259

#include <bits/stdc++.h>
using namespace std;
/*

input:
10
4
32
34
543
3456
654
567
87
6789
98

*/

int main()
{
    int N, x;
    cin >> N;

    priority_queue<int,vector<int>,greater<int>> par;
    priority_queue<int> impar;
    
    while (N--)
    {
        cin >> x;
        if (x % 2 == 0) par.push(x);
        else impar.push(x);
    }

    while (!par.empty())
    {
        cout << par.top() << '\n'; 
        par.pop();
    }

    while (!impar.empty())
    {
        cout << impar.top() << '\n';
        impar.pop();
    }
    
    return 0;
}