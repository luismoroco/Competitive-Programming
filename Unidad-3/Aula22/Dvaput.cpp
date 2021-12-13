#include <bits/stdc++.h>
using namespace std;

// https://open.kattis.com/problems/dvaput

typedef pair<int, int> pii;

    char T[200005], P[200005];
    int N, RA[200005], tempRA[200005], SA[200005], tempSA[200005], c[200005];
    int PLCP[200005], Phi[200005], LCP[200005], m;

    void
    Couting(int k){
        int i, sum, maxi = max(300, N);
        memset(c, 0, sizeof c);
        for (i = 0; i < N; i++) c[i + k < N ? RA[i + k] : 0]++;
        for (i = sum = 0; i < maxi; i++) { int t = c[i]; c[i] = sum; sum += t;}
        for (i = 0; i < N; i++) tempSA[c[SA[i]+k < N ? RA[SA[i]+k] : 0]++] = SA[i];
        for (i = 0; i < N; i++) SA[i] = tempSA[i];
    }

    void
    FxSA(){
        int i, k, r;
        for (i = 0; i < N; i++) RA[i] = T[i];
        for (i = 0; i < N; i++) SA[i] = i;
        for (k = 1; k < N; k <<= 1){
            Couting(k);
            Couting(0);
            tempRA[SA[0]] = r = 0;
            for (i = 1; i < N; i++) tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
            for (i = 0; i < N; i++) RA[i] = tempRA[i];
            if (RA[SA[N-1]] == N-1) break;
        }
    }

    void
    CLCP(){
        int i, L;
        Phi[SA[0]] = -1;
        for (i = 1; i < N; i++) Phi[SA[i]] = SA[i-1];   
        for (i = L = 0; i < N; i++){
            if (Phi[i] == -1) { PLCP[i] = 0; continue; }
            while (T[i+L] == T[Phi[i]+L]) L++;
            PLCP[i] = L;
            L = max(L-1, 0);
        }
        for (i = 0; i < N; i++) LCP[i] = PLCP[SA[i]];
    }

    pii Fx(){
        int i, idx = 0, maxLCP = -1;
        for (i = 1; i < N; i++)       
            if (LCP[i] > maxLCP) maxLCP = LCP[i], idx = i;
        return pii(maxLCP, idx);   
    }

    void
    solve(){
        cin >> N; 
        cin >> T;
        T[N++] = '$'; 
        FxSA(); 
        CLCP();
        pii ans = Fx(); 
        cout << ans.first << '\n';
    }

int 
main(int argc, char const *argv[])
{
    solve();
    return 0;
}