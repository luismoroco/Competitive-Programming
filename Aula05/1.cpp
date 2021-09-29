#include <bits/stdc++.h>
using namespace std;

int main()
{
    int array[] = {1, 2, 7, 9, 11, 15};
    int n = 6, i, j, left, rigthh, tmp, target = 9;

    // output esperada = [1, 2] = sum[2, 7] = 9

    for (i = 0; i < n; i++)
    {
        left = i + 1;
        rigthh = n - 1;
        while (left < rigthh)
        {
            tmp = array[left] + array[rigthh];
            if (tmp == target)
            {
                cout << '[' << left << ',' << rigthh << ']' << '\n';
                left++;
                rigthh--;
                break;
            }
            else if (tmp < target)
                left++;
            else
                rigthh--;
        }
    }

    return EXIT_SUCCESS;
}