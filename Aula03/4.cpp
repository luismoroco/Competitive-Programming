#include <bits/stdc++.h>
using namespace std;

int main()
{
    int array[] = {2, 3, 6, 1, 8, 9};
    int n = 6, k = 5, ans = 0;

    for (int a = 0; a < n; a++)
    {
        for (int b = a; b < n; b++)
        {
            int sum = 0;
            vector<int> vec;

            for (int k = a; k <= b; k++)
            {
                vec.push_back(array[k]);
                sum += array[k];
            }

            if (sum % k == 0)
            {
                for (auto i : vec)
                    cout << i << ' ';

                cout << '\n';
                ++ans;
            }
        }
    }

    return EXIT_SUCCESS;
}
