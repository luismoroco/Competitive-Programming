#include <bits/stdc++.h>
using namespace std;

// https://open.kattis.com/problems/lifeforms

typedef int long long ll;
#define MAXX 110005
#define MAXN 105
ll From[MAXX], WLen[MAXN], n, h;
char M[MAXN];

class Solution {
    public:
        ll sa[MAXX], height[MAXX], weight[MAXX], A[MAXX], B[MAXX] , n;
        char str[MAXX];

        void 
        RADIX(ll *x, ll *y, ll m) { 
            ll i;
            for(i = 0; i < m; i++) weight[i] = 0;
            for(i = 0; i < n; i++) weight[x[y[i]]]++;
            for(i = 1; i < m; i++) weight[i] += weight[i-1];
            for(i = n-1; i >= 0; i--) sa[--weight[x[y[i]]]] = y[i];
        }

        bool 
        CMP(ll *r, ll a, ll b, ll l) {
            if(r[a] == r[b]) {
                if(a+l >= n || b+l >= n) return false;
                return r[a+l] == r[b+l];
            }
            else return false;
        }

        void 
        Fx(){
            ll i, j, k;
            for(i = 0; i < n; i++)  A[sa[i]] = i;
            for(i = 0; i < n; i++) {
                if(A[i] == 0) { height[A[i]] = 0; continue;}
                if(i == 0 || height[A[i-1]] <= 1) k = 0;
                else k = height[A[i-1]]-1;
                while(str[sa[A[i]-1]+k] == str[sa[A[i]]+k]) k++;
                height[A[i]] = k;
            }
        }

        void
        Fy(){
            ll i, k, m = 128, p;
            ll *x = A, *y = B, *z;
            n = strlen(str);
            x[n] = 0;
            for(i = 0; i < n; i++) x[i] = str[i], y[i] = i;
            RADIX(x, y, m);
            for(k = 1, p = 1; p < n; k *= 2, m = p) {
                for(p = 0, i = n-k; i < n; i++) y[p++] = i;
                for(i = 0; i < n; i++) {
                    if(sa[i] >= k) y[p++] = sa[i]-k;
                }
                RADIX(x, y, m);
                z = x, x = y, y = z;
                for(i = 1, p = 1, x[sa[0]] = 0; i < n; i++)
                    x[sa[i]] = CMP(y, sa[i-1], sa[i], k) ? p-1 : p++;
            }
        }
};

Solution sol;

ll 
check(ll len, ll Print){
    ll i, j, k, cnt;
    for(i = n; i < sol.n; i++) {
        if(sol.height[i] >= len) {
            memset(M, 0, sizeof(M));
            j = i; cnt = 1;
            M[From[sol.sa[i-1]]] = 1;
            while(j < sol.n && sol.height[j] >= len) {
                if(From[sol.sa[j]] != From[sol.sa[j]+len-1]) {
                    j++;break;
                }
                if(M[From[sol.sa[j]]] == 0) {
                    M[From[sol.sa[j]]] = 1; cnt++;
                }
                j++;
            }
            if(cnt > h) {
                if(Print) {
                    for(k = 0; k < len; k++) putchar(sol.str[sol.sa[i]+k]);
                    puts("");
                } else return 1;
            }
            i = j-1;
        }
    }
    return 0; 
}

int 
main(int argc, char const *argv[])
{
    ll i, f = 0;
    while(scanf("%lld", &n) == 1 && n) {
        if (f) puts("");
        f = 1; h = n/2;
        ll m = 0, mxlen = 0;
        for(i = 0; i < n; ++i) {
            scanf("%s", sol.str+m);
            ll cnt = 0;
            while(sol.str[m]){
                From[m] = i, m++, cnt++;
            }
            if(cnt > mxlen) mxlen = cnt;
            WLen[i] = cnt;
            sol.str[m++] = '$';
            sol.str[m] = 0;
        } 

        sol.str[m-1] = '\0';
        if(n == 1) {
            puts(sol.str);
            continue;
        }

        sol.Fy();
        sol.Fx();
        ll l = 1, r = mxlen, res = 0;
        while(l <= r) {
            m = (l+r)/2;
            if(check(m, 0)) {
                l = m+1;
                if(m > res) res = m;
            } else r = m-1;
        }
        if(res == 0) cout << "?\n";
        else check(res, 1);
    }
    return 0;
}