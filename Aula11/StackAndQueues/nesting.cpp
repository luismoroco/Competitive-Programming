#include <bits/stdc++.h>
using namespace std;

int solution(string &S) 
{
    vector<char> stack;
    for(auto& character : S)
    {
        if (character == '(') 
            stack.push_back('(');
        else if (!stack.empty()) 
            stack.pop_back();
        else 
            return 0;
    }
    
    if(!stack.empty()) 
        return 0;
    return 1;
}

int main()
{
    string test = "(()(())())";
    solution(test);

    return 0;   
}