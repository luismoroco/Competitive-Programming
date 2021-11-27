#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
int main(int argc, char const *argv[])
{
    int n, x;
    cin >> n;
    vi data;

    while (cin >> x)
        data.push_back(x);

    for (int it : data)
        cout << it << '\t';
    
    return 0;
}