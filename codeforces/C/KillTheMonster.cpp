#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t; 

    while (t--) {
        int hc, dc, hm, dm, k, w, a;
        cin >> hc, dc;
        cin >> hm, dm;
        cin >> k >> w >> a; 

        hc = hc + k*w;
        dc = dc + k*a; 

        while (hc >= 0 && hm >= 0) {
            hm -= dc; 
            hc -= dm;
        }

        hc < hm ? cout << "YES" : cout << "NO";
    }    

    return 0;
}

// harina vegetal de consumo nasal