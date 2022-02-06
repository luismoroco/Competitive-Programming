#include <bits/stdc++.h>

using namespace std;

int tam, n, i;
 
string solve(string x){
    tam = x.length();
    string ans = x[0] + to_string(tam-2) + x[tam-1];
    return ans;
}
 
int main()
{
    cin >> n;
    string answer[n];
    string x;
    i = 0;
    while (n--){
        cin >> x;
        if (x.length() > 10)
            answer[i] = solve(x);
        else
            answer[i] = x;
        ++i;
    }
    for (auto v : answer)
        cout << v << '\n';
 
    return EXIT_SUCCESS;
}