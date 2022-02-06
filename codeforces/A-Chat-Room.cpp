#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    string tg = "hello";

    string x;
    cin >> x;

    int count = 0;
    int it = 0;

    for (int i = 0; i < x.length(); ++i){
        if (x[i] == tg[it]){
            ++count;
            ++it;
            if (count == 5) break; 
        }
    }

    count == 5 ? cout << "YES\n" : cout << "NO\n"; 

    return EXIT_SUCCESS;
}
