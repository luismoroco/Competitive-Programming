#include <bits/stdc++.h>

using namespace std;

string timeConversion(string s) {

    bool tarde = (s[8]=='P')? true : false;
    
    s.erase(8,2);
    int num = (s[0]-'0')*10 + (s[1]-'0');

    if (num < 12 && tarde) {
        num += 12; 
        string tmp = to_string(num);
        s[0] = tmp[0]; s[1] = tmp[1];
    }
    else if (num == 12 && !tarde) {
        s[0] = '0'; s[1] = '0';
    } 

    return s;

}

int main(int argc, char const *argv[])
{
    cout << timeConversion("12:00:00AM");

    return 0;
}
