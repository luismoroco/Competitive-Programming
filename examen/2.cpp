// https://app.codility.com/programmers/lessons/5-prefix_sums/genomic_range_query/

#include <bits/stdc++.h>
using namespace std;

vector<int> solution(string &S, vector<int> &P, vector<int> &Q){
    vector<int> answ;
    int lngt = P.size()-1, x = 0, min, i;
    while (x<=lngt){
        min = 999999;
        for (i = P[x]; i <= Q[x]; ++i){
            if (S[i] == 'A' &&  1 <= min) min = 1;
            if (S[i] == 'C' &&  2 <= min) min = 2;
            if (S[i] == 'G' &&  3 <= min) min = 3;
            if (S[i] == 'T' &&  4 <= min) min = 4;
        }
        answ.push_back(min);
        ++x;
    }
    return answ;
}


int main()
{
    string S = "CAGCCTA";
    vector<int> P = {2, 5, 0};
    vector<int> Q = {4, 5, 6};
    solution(S, P, Q);

    return EXIT_SUCCESS;
}