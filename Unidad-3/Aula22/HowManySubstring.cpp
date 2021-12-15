#include <bits/stdc++.h>
using namespace std;

// https://www.beecrowd.com.br/judge/es/problems/view/1530

const long long int MAXX=1e5+5;
typedef int long long ll;
ll n = 0,t = 0, ans =0;
string arr;
ll BUFF[MAXX], LCP[MAXX], BFFF[MAXX], POSITIOM[MAXX];

bool 
compare(ll i, ll j){
    if(POSITIOM[i]!=POSITIOM[j]) return (POSITIOM[i]<POSITIOM[j]);
    i+=t;j+=t;
    if(i<n && j<n) return (POSITIOM[i]<POSITIOM[j]);
    return (i>j);
}

int
main(int argc, char const *argv[])
{
    string T;
    while(true){
        getline(cin, T);
        for (ll i = 0; i < T.size(); i++){
            if(T[i]=='?'){
                for(ll i=0; i<n;i++){
                    BUFF[i]=i;
                    POSITIOM[i]=arr[i];
                }
                for(t=1;t<2*n+1;t*=2){
                    sort(BUFF,BUFF+n,compare);
                    for(ll i=0; i<n-1;i++){
                        BFFF[i+1]=BFFF[i];
                        if(compare(BUFF[i],BUFF[i+1])) BFFF[i+1]++;
                    }
                    for(ll i=0; i<n;i++){
                        POSITIOM[BUFF[i]]=BFFF[i];
                    }
                    if(BFFF[n-1]==n-1) break;
                }
                ll p=0;
                ll sumtot=(n*(n+1))/2;
                for(ll i=0; i<n;i++){
                    if(POSITIOM[i]!=n-1){
                        ll j=BUFF[POSITIOM[i]+1];
                        while(arr[i+p]==arr[j+p])p++;
                        LCP[POSITIOM[i]]=p;
                        ans+=p;
                        if(p>0) p--;
                    }
                } 
                cout<<sumtot-ans<<"\n";
            } else { 
                arr+=T[i];++n;
            }
        }
        n=0,t=0,ans=0;
        arr.clear();
    }
    
    return 0;
}