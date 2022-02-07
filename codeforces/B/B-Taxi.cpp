#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, x;
    cin >> n;

    priority_queue<int> dp;

    for (int i = 0; i < n; ++i){ cin >> x; dp.push(x);}

    int count = 0;
    while (!dp.empty()){
        int pivo = dp.top();
        if (pivo == 4) { dp.pop(); ++count; }
        else{
            int accu = pivo;
            int contador = 0;
            while (accu < 4 && !dp.empty()){
                dp.pop();
                if (accu + dp.top() <= 4){
                    accu += dp.top(); ++contador;
                }
            }
            count += contador;
        }
    }

    cout << count << '\n';

    return EXIT_SUCCESS;
}