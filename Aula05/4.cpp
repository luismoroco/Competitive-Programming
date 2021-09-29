#include <bits/stdc++.h>
using namespace std;

int main()
{
    /*
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, x, target, i, left, rigth, tmp;
    vector<int> array;
    cin >> n >> target;
    while (n--)
    {
        cin >> x;
        array.push_back(x);
    }
    */

    int array[] = {3, 15, 4, 9, 1};
    int n = 5, i, left, rigth, tmp, target = 5;
    bool flag = false;

    /*
    * output esperado : [2, 4] -> sum[4, 1] = 5 
    */

    for ( i = 0; i < n; ++i)
    {
        left = i;
        rigth = n - 1;
        while (left < rigth && array[left] && array[rigth]) // 1
        {
            tmp = array[left] + array[rigth];
            if (tmp == target)
            {
                cout << " solve : " << '[' << left << ',' << rigth << ']' << '\n';
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
