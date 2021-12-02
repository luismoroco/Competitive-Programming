#include <bits/stdc++.h>
using namespace std;

void solve(deque<int> &s){
    int time(0), piv(-1);
    while (s.front() != piv  && s.back() != piv){
        if(s.front() < s.back()) {time += s.front(); s.pop_front();}
        else {time += s.back(); s.pop_back();} 
    }
    cout << time << '\n';
}

int main(){
    deque<int> wait = {4, -1, 5, 2, 3};
    solve(wait);

    return EXIT_SUCCESS;
}