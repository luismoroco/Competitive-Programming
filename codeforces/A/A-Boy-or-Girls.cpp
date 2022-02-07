#include <bits/stdc++.h>

using namespace std;
 
int main()
{
    string word;
    cin >> word;
    int size = word.length(), i;
    unordered_set<char> mp;
 
    for (i = 0; i < size; ++i){
        mp.insert(word[i]);
    }
 
    if (mp.size()%2 == 0) cout << "CHAT WITH HER!" << '\n';
    else cout << "IGNORE HIM!" << '\n'; 
 
    return EXIT_SUCCESS;
}