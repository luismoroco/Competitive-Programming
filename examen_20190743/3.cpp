#include <iostream>
using namespace std;
typedef long long lli;

int main()
{
    lli n, a, b;
    cin >> n >> a >> b;
    lli A[n];
        
    for(lli i=0; i<n; i++)
        cin >> A[i];
    
    lli veces = (b-a)+1;
    lli subArr = (n-a)+1;
    lli maxSum = 0;
    lli tempSum = 0;

    if (n == 1){
        maxSum = A[0];
    }
    else{
        for(lli i=0; i<veces; i++)
        {
            for(lli j=0; j<subArr-i; j++)
            {
                tempSum = 0;
                for(lli k=j; k<a+j+i; k++)
                    tempSum += A[k];
                
                if(tempSum > maxSum)
                    maxSum = tempSum;
            }
        }
    }

    cout << maxSum << '\n';
    return 0;
}