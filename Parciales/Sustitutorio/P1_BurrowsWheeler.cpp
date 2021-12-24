#include <bits/stdc++.h>
using namespace std;

// https://open.kattis.com/problems/burrowswheeler

/*
The Burrows-Wheeler transform is a technique for transforming a text message so that it responds well to compression techniques. 
Under this transform, we consider all cyclic shifts of an input string. For example, if our text was the string “arbitrary string”, 
then the string “rbitrary stringa” would be the result of cyclicly shifting the string one character to the left. The first 
character is moved to the end of the string, and all of the other characters are moved one index earlier. If a string has n characters, 
then there are n cyclic shifts of the string. The text on the left lists all cyclic shifts of the string “arbitrary string”, one per line.


Under the Burrows-Wheeler transform, we imagine that we lexicographically sorted all these lines. The figure on the right illustrates what 
this would yield for the text “arbitrary string”. The original message is encoded as the right-hand column of this sorted list of cyclicly 
shifted copies of the input string. For example, “arbitrary string” would be encoded as “ygrrnrbitata isr”.

For this problem, you are expected to compute the Burrows-Wheeler transform for an arbitrary line of text. Of course, the transform is 
invertible, but we’ll let some other programmer worry about recovering the original message from your encoding.

Input
Input consists of up to 100 messages, one per line. A message may use lowercase or uppercase letters (a–z), digits, punctuation, and spaces. 
Each message may be up to 100000 characters in length. Messages continue up to the end of file. The total number of input characters is 
no more than 220.

Output
For each input message, output a single line that results from applying the Burrows-Wheeler transform. The validation for this problem 
is sensitive to both case and spacing changes.

example

Input:
arbitrary string
this is the thing I was talking about

output:
ygrrnrbitata isr
ggssseI  twahnnttthkh laiibiai   tuo 

*/

void Solution()
{
    string line;
    while (getline(cin, line)){
        string result = "";
        for (int i = 0; i < line.size(); i++){
            result += line[(i + 1) % line.size()];
        }
        cout << result << endl;
        
    }

}

int main(int argc, char const *argv[])
{
    while (true){
        Solution();
    }

    return 0;
}
