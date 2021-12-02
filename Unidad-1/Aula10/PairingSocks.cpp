#include <bits/stdc++.h>
using namespace std;
// https://open.kattis.com/problems/pairingsocks

int sockMerchant(int n, vector<int> ar) {
        int f[101],i;
        int c=0;

        for(i=0;i<101;i++)
            f[i]=0;

        for(i=0;i<n;i++)
            f[ar.at(i)]++;

        for(i=1;i<=100;i++)
            c+=f[i]/2;

        return c;

}

int main()
{
    

}

