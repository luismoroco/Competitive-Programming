#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, target, i, left, rigth, tmp;
    bool flag = false;
    vector<int> array;
    cin >> n >> target;

    while (n--){
        cin >> x;
        array.push_back(x);
    }

    for ( i = 1; i <= array.size(); ++i)
    {
        left = i;
        rigth = array.size()-1;
        while (left < rigth && array[left] && array[rigth]) 
        {
            tmp = array[left] + array[rigth];
            if (tmp == target)
            {
                cout << left << ' ' << rigth << '\n';
                flag = true;
                exit(1);
            }
            else if (tmp < target)
                left++;
            else
                rigth--;
        }
    }
    
    if (flag == false) 
        cout << "IMPOSSIBLE" << '\n';


    return EXIT_SUCCESS;
}
