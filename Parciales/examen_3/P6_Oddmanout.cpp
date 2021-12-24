#include <bits/stdc++.h>

using namespace std;

// https://open.kattis.com/problems/oddmanout

int main(int argc, const char * argv[])
{
    int numberCases;
    cin >> numberCases;

    int i = 1;
    while(numberCases--){
        map<long,int> m;
        int G;
        cin >> G;

        while(G--){
            long C;
            cin >> C;
            if(m[C] == 0) ++m[C]; 
            else m.erase(C); 
        }

        cout << "Case #" << i << ": " << m.begin()->first << '\n';
        ++i;
    }

    return EXIT_SUCCESS;
}