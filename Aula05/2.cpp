#include <bits/stdc++.h>
using namespace std;

int main()
{
    int array[] = {1, 2, 4, 5, 12};
    int n = 6, i, j, left, rigthh, tmp, target = 19;

    // output esperado = [1, 3, 4] = sum[2, 5, 12] = 19 
    
    for (i = 0; i < n; i++)
    {
        left = i + 1;
        rigthh = n - 1;
        while (left < rigthh)
        {
            tmp = array[i] + array[left] + array[rigthh];
            if (tmp == target)
            {
                cout << '[' << i << ',' << left << ',' << rigthh << ',' << ']' << '\n';
                left++;
                rigthh--;
            }
            else if (tmp < target)
                left++;
            else
                rigthh--;
        }
    }

    return EXIT_SUCCESS;
}