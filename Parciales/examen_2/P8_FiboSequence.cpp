#include <bits/stdc++.h>
using namespace std;

// https://www.beecrowd.com.br/judge/en/problems/view/1701

/*
Fibo is a big fan of numbers, specially of big ones. He loves sequences that 
grow fast, his favorite is a well known sequence, the Fibonacci Sequence. Someday 
he decided to create a new sequence using his favorite one. His new sequence is build 
multiplying consecutive Fibonacci numbers. So he gets two initial Fibonacci numbers of 
indexes A and B. The first element of the new sequence is the Fibonacci number of index 
A multiplied by the number of index B, the second one is the Fibonacci number of index A+1 
multiplied by the number of index B+1, and so on. He knows how to get any element of his 
sequence, but he would like to know another thing. He would like to know the sum of the first
N numbers of the new sequence. Can you help him?

PS: Fibonnaci(0) = 0 and Fibonnaci(1) = 1

Input
The input file has a lot of test cases. Each test case has three integers, A, B and N (1 <= A, B, N <= 1000000000), 
their meaning was explained in the text above. The input ends with three zeros.

Output
For each test case you have to print one number, the sum of the N first elements of Fibo's sequence. 
This number can be really large, so you have to print it MOD 1000000007.

example:
input:
1 1 5

output:
40
*/

typedef int long long ll;

ll 
pisano(ll m)
{
    ll prev = 0;
    ll curr = 1;
    ll res = 0;
 
    for(int i = 0; i < m * m; i++)
    {
        ll temp = 0;
        temp = curr;
        curr = (prev + curr) % m;
        prev = temp;
 
        if (prev == 0 && curr == 1)
            res = i + 1;
    }
    return res;
}
 
ll 
fibonacciModulo(ll n, ll m)
{
    ll pisanoPeriod = pisano(m);
    n = n % pisanoPeriod;
    ll prev = 0;
    ll curr = 1;
 
    if (n == 0) return 0;
    else if (n == 1) return 1;
 
    for(ll i = 0; i < n - 1; ++i)
    {
        ll temp = 0;
        temp = curr;
        curr = (prev + curr) % m;
        prev = temp;
    }
    return curr % m;
}

void solve(ll a, ll b, ll n)
{
    ll num = 0;
    for(ll cont = -1; cont < n; cont++)
        num += fibonacciModulo(a + cont + 1, 1000000007) * fibonacciModulo(b + cont + 1, 1000000007);
    cout << num % 1000000007 << endl;
}

int main(int argc, char const *argv[])
{
    solve(10000, 10000, 10000);

    return 0;
}
