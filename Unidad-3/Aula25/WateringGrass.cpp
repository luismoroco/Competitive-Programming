#include <bits/stdc++.h>
using namespace std;

// https://open.kattis.com/problems/grass

typedef long double ld;
typedef long long int ll;
typedef pair<ld, ld> pdd;

int 
main(int argc, char const *argv[])
{
    ld N, L, W, x, r;
    while (cin >> N >> L >> W) {
        vector<pdd> lis;
        while (N--) {
            cin >> x >> r;
            if (2*r > W) {
                ld tmp = sqrt(pow(r, 2) - pow(W/2, 2));
                lis.push_back(pdd(x - tmp, x + tmp));
            }
        }
        sort(lis.begin(), lis.end());
        ld c = 0, i = 0, aux = 0;
        ld n = lis.size();

        while(true){
            ld tmp = -1;
            while(i < n &&  lis[i].first <= aux){
                tmp = max(tmp, lis[i].second);
                i++;
            }
            if(tmp == -1){
                cout << -1 << endl;
                break;
            }
            c++;
            aux = tmp;
            if (aux >= L){
                cout << c << endl;
                break;
            }
        }

    }
    return 0;
}