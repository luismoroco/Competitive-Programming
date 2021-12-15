#include <bits/stdc++.h>
using namespace std;

// https://open.kattis.com/problems/suffixarrayreconstruction

typedef long long ll;

int 
main(int argc, char const *argv[])
{
    ll t, tn, S, p;
    string Buff, W;
    bool Status;
    cin >> t;
    while (t--){
        cin >> tn >> S;
        Buff = "";
        for (ll i = 0; i < tn; i++) Buff += "*";
        Status = true;
        for (ll i = 0; i < S; i++){
            cin >> p >> W; p--;
            for (ll j = 0; j < W.size(); j++){
                if (W[j] == '*') break;
                if (Buff[j + p] == '*' || Buff[j + p] == W[j]) Buff[j + p] = W[j];
                else { Status = false; break;}
            }
            for (ll j = 0; j < W.size(); j++){
                if (W[W.size() - j - 1] == '*') break;
                if (Buff[tn - j - 1] == '*' || Buff[tn - j - 1] == W[W.size() - j - 1]){ Buff[tn - j - 1] = W[W.size() - j - 1];}
                else { Status = false; break;}
            }
        }

        for (ll i = 0; i < tn; i++){ if (Buff[i] == '*'){Status = false;break;}}
        if (Status) cout << Buff << endl;
        else cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}