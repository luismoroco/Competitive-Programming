#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, c, k, s = 1, mas = 0;
    cin >> n >> k;   
    while (n--){
        cin >> c;
        mas = max(mas, c);
    }
    cout << (mas/1000) % k +1 << '\n';
    
    return 0;
}