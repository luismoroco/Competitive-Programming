#include <bits/stdc++.h>
using namespace std;

// https://open.kattis.com/problems/stack

/*
You were recently hired by Rural and Municipal Roadway Communications to manage messages
on a scrolling display above a major highway. Much to your surprise, these are very primitive 
displays. You have to input the message manually every time it should be changed (there is no 
memory to preload a list of messages).

Strangely, the only way to post messages is using an on-board stack. You can push a character 
onto the top of the stack, you can pop the character that is on top of the stack, and you can 
print the character that is on top of the stack..

Out of boredom, or perhaps the universal human desire to do as little work as possible to 
get the job done, you wonder what the minimum number of push, pop, and print are required 
to print a message your boss has told you to display. Oh, you must also ensure the stack is 
clear at the end so that you are ready to input a new message next time your boss asks you to do this.

Example If we want to print the message abba and then clear the stack you could do the 
following. Note the contents of the stack are recorded below with the top of the stack on the right.

Input
The first line of input is a single integer T≤30 indicating the number of test cases. Each 
of the following T lines contains a single string consisting of any printable characters. The 
first and last character of each line will not be a space. Each line has at least one and at most 
200 characters.

Output
For each of the T strings in the input, you should output on a single line the minimum number 
of operations required to print the string on the display.

example 1:
input : abba
output: 8

example 2:
input : d
output: 3
*/

// solve 
int solution(string &str)
{

    int n = str.size();
    int cnt = 0;
    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == ' ')
            continue;
        if (st.empty())
        {
            st.push(str[i]);
            cnt++;
        }
        else
        {
            if (st.top() == str[i])
            {
                st.pop();
                cnt += 2;
            }
            else
            {
                st.push(str[i]);
                cnt += 3;
            }
        }
    }
    return cnt;
}



int main(int argc, char const *argv[])
{
    string str = "d";
    cout << solution(str) << '\n';

    return 0;
}



