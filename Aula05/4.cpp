#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, target, i, left, rigth, tmp;
    vector<int> array;
    cin >> n >> target;
    while (n--)
    {
        cin >> x;
        array.push_back(x);
    }

    for (i = 0; i < n; i++)
    {
        left = i + 1;
        rigth = n - 1;
        while (1)
        {
            tmp = array[left] + array[rigth];
            if (tmp == target)
            {
                cout << '[' << left << ',' << rigth << ']' << '\n';
                left++;
                rigth--;
                break;
            }
            else if (tmp < target)
                left++;
            else
                rigth--;
        }

        cout << "IMPOSSIBLE" << '\n';
    }

    return EXIT_SUCCESS;
}