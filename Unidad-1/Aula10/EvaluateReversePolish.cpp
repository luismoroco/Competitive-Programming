#include <bits/stdc++.h>
using namespace std;

// stoi-> string to int 
// isdigit-> know if a character is a idigit 

// https://leetcode.com/problems/evaluate-reverse-polish-notation/

int solve(vector<string> &tokens){
    stack<int> op;
    int i, res, x;
    for (i = 0; i < tokens.size(); ++i){
        if(isdigit(tokens[i][0])){ op.push(stoi(tokens[i]));}
        else if(tokens[i] == "+"){
            x = op.top(); op.pop(); 
            x += op.top(); op.pop();
            op.push(x);
        }
        else if(tokens[i] == "-"){
            x = op.top(); op.pop(); 
            x -= op.top(); op.pop();
            op.push(x); 
        }
        else if(tokens[i] == "*"){
            x = op.top(); op.pop(); 
            x *= op.top(); op.pop();
            op.push(x);
        }
        else if(tokens[i] == "/"){
            x = op.top(); op.pop(); 
            x /= op.top(); op.pop();
            op.push(x);
        }
    }
    cout << op.top() << '\n';
    return op.top();
}   

int main(){

    vector<string> tokens = {"2","1","+","3","*"};
    solve(tokens);
    
    return EXIT_SUCCESS;
}