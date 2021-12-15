#include <bits/stdc++.h>
using namespace std;

// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=4459

int main(int argc, char const *argv[])
{
    int t, i, j, k, x, y, tmp, pos; 
    cin >> t;
    string s;
    while (t--){
        cin >> s;
		pos = 0, j = 1, k = 0;
		while(pos < s.length() && j < s.length() && k < s.length()) {
			x = pos + k;
			y = j + k;
			if(x >= s.length())	x -= s.length();
			if(y >= s.length())	y -= s.length();
			if(s[x] == s[y]) {
				k++;
			} else if(s[x] > s[y]) {
				pos = j+1 > pos+k+1 ? j+1 : pos+k+1;
				k = 0;
				tmp = pos, pos = j, j = tmp;
			} else {
				j = pos+1 > j+k+1 ? pos+1 : j+k+1;
				k = 0;
			}
		}
		for	(int i = pos; s[i]; i++)
			putchar(s[i]);
		for	(int i = 0; i < pos; i++)
			putchar(s[i]);
		puts("");
	}

    return 0;
}
