#include <bits/stdc++.h>
 
using namespace std;
 
int main(int argc, char const *argv[])
{
    string word;
    getline(cin, word);
    int min = 0, may = 0;
    for (int i = 0; i < word.size(); ++i){
        if (isupper(word[i])) ++may;
        else ++min;
    }
 
    if (may < min || may == min){
        for (int i = 0; i < word.size(); ++i){
            word[i] = tolower(word[i]);
        }
    }
    else{
        for (int i = 0; i < word.size(); ++i){
            word[i] = toupper(word[i]);
        }
    }
    
    cout << word << '\n';
 
    return EXIT_SUCCESS;
}