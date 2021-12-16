#include <bits/stdc++.h>
using namespace std;

// https://open.kattis.com/problems/bachetsgame

/*

Bachet’s game is probably known to all but probably not by this name. Initially there are n stones on the table. There are two players Stan and Ollie, who move alternately. Stan always starts. The legal moves consist in removing at least one but not more than k stones from the table. The winner is the one to take the last stone. Here we consider a variation of this game. The number of stones that can be removed in a single move must be a member of a certain set of m numbers. Among the m numbers there is always 1 and thus the game never stalls.
Input
The input consists of a number of lines (between 1 and 100, inclusive). Each line describes one game by a sequence of positive numbers. The first number is n≤1000000 the number of stones on the table; the second number is m≤10 giving the number of numbers that follow; the last m numbers on the line specify how many stones can be removed from the table in a single move.

Output
For each line of input, output one line saying either Stan wins or Ollie wins assuming that both of them play perfectly.

Sample Input 1	

20 3 1 3 8
21 3 1 3 8
22 3 1 3 8
23 3 1 3 8
1000000 10 1 23 38 11 7 5 4 8 3 13
999996 10 1 23 38 11 7 5 4 8 3 13

Sample Output 1

Stan wins
Stan wins
Ollie wins
Stan wins
Stan wins
Ollie wins

*/

typedef long long int ll;
typedef vector<ll> vll;

int main(int argc, char const *argv[])
{
    int n, m, k;
    int a, b, c;
    int max;
    int pos;
    int val;
    int stan = 0;
    int ollie = 0;
    while (cin >> n >> m) {
        if (n == 1000000) break;
        cin >> k;
        vll v;
        for(int j = 0; j < m; j++) {
            cin >> a >> b >> c;
            pos = b / (2*a);
            val = a * pow(pos, 2) + b * pos + c;
            v.push_back(val);
        }
        max = 0;
        for(int j = 0; j < m; j++) {
            if(v[j] > v[max]) max = j;
        }
        if (stan == 0) {
            stan = 1;
            ollie = 0;
        } else {
            stan = 0;
            ollie = 1;
        }
        if (stan == 1) {
            if (max == m-1) {
                cout << "Stan wins\n";
            } else {
                cout << "Ollie wins\n";
            }
        } else {
            if (max == m-1) {
                cout << "Ollie wins\n";
            } else {
                cout << "Stan wins\n";
            }
        }
    }

    return 0;
}
