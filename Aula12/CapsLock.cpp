#include<deque>
#include<vector>
#include<string>

using namespace std;

void solve(string &x){
    deque<char> tmp;
    char d;
    for (size_t i(0); i < x.length(); ++i){
        d = x[i];
        if(d=='$'){
            
        }
        else if(d=='@'){

        }
        else{
            tmp.push_back(d);
        }
    }
    
}


int main(){
    string word = "abc$d@ef$@g$";
    solve(word);

    return 0;
}