#include <bits/stdc++.h>
using namespace std;

// https://open.kattis.com/problems/trendingtopic

typedef pair<string,int> psti;
typedef vector<string> vst;
#define TEXT "<text>";
#define TOP "<top";

void 
runquery(map<string,int> BUFFF, int top) 
{
    map<int,vst> rev;
    for(auto i : BUFFF) {rev[i.second].push_back(i.first);}
    auto it = prev(rev.end());
    vector<psti> res;
    while(res.size() < top) {
        for(auto j : it->second) {res.push_back({j,it->first});}
        if(it == rev.begin()) break;
        it--;
    }
    sort(res.begin(),res.end(),[&](psti p1, psti p2) {
        if(p1.second == p2.second) { return p1.first < p2.first;}
        return p1.second > p2.second;
    });
    for(auto i : res) {cout << i.first << " " << i.second << endl;}
}

int 
main(int argc, char const *argv[]) 
{
    string s;
    vector<vst> DAAYS;
    map<int,vector<int>> CONSULTAS;
    int ACTUAL = 0;
    DAAYS.push_back({});
    while(cin >> s) {
        if(s == "<text>") {
            DAAYS.push_back({});
            ACTUAL++;
            continue;
        }
        if(s == "</text>") {continue;}
        if(s == "<top") {
            int n;
            cin >> n;
            string g;
            cin >> g;
            CONSULTAS[ACTUAL].push_back(n);
            continue;
        }
        if(s.size() < 4) {continue;}
        DAAYS[ACTUAL].push_back(s);
    }
    DAAYS.push_back({});
    ACTUAL++;
    map<string,int> BUFFF;
    for(int i = 0; i < ACTUAL; i++) {
        for(auto j : DAAYS[i]) {BUFFF[j]++;}
        if(i >= 7) {
            for(auto j : DAAYS[i-7]) {
                BUFFF[j]--;
                if(BUFFF[j] == 0) {BUFFF.erase(j);}
            }
        }
        for(auto j : CONSULTAS[i]) {
            cout << "<top " << j << ">" << endl;
            runquery(BUFFF,j);
            cout << "</top>" << endl;
        }
    }

    return EXIT_SUCCESS;
}