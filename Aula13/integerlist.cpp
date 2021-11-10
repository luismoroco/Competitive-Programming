#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> res;
int i;

void solve(string x, string v){
    deque<int> temp;
    vector<int> t;
    int cont = 0;

    for (i = 0; i < v.length(); ++i){
        if(v[i] == '[' || v[i] == ']' || v[i] == ','){continue;}
        else{temp.push_back((int)v[i]-'0');++cont;}
    }

    if(x.length() > cont){
        //t.push_back(-9999);
        res.push_back(t);
        return;
    }else{
        bool flag = true;
        for (i = 0; i < x.length(); ++i){
            if(x[i] == 'R'){
                if(flag == true){flag = false;}
                else{flag = true;}
            }
            if(x[i] == 'D'){
                if(flag == true){temp.pop_front();continue;}
                if(flag == false) {temp.pop_back();}
            }
        }

        if(flag == true){
            while (!temp.empty()){
                t.push_back(temp.front());
                temp.pop_front();
            }
            res.push_back(t);
            //for (auto x : t){cout << x << ',';}
            return;
        }else if (flag == false){
            while (!temp.empty()){
                t.push_back(temp.back());
                temp.pop_back();
            }
            res.push_back(t);
            //for (auto x : t){cout << x << ',';}
            return;
        }
    }
}


int main(){
    int n, t;
    cin >> n;
    string x, v;
    while (n--){
        cin >> x;
        cin >> t;
        cin >> v;
        solve(x, v);
    }

    for (i = 0; i < res.size(); ++i){
        if(res[i].empty() == true){cout << "error" << '\n'; continue;}
        else{
            cout << '[';
            for (auto x : res[i]){cout << x << ',';}
            cout << ']';
            cout << '\n';
        }
    }
    
   return EXIT_SUCCESS;
}