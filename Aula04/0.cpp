#include <bits/stdc++.h>
using namespace std;

int main()
{
    int array[] = {1, 2, 3};
    int n = 3, x = 3;

    int a, b, cont = 0;
    for (a = 0; a < n; a++)
    {
        int sum = 0;
        for (b = a; b < n; b++)
        {
            sum += array[b];
            if (sum == x)
                ++cont;
        }
    }
    cout << cont << '\n';

    /*
    ------------------------------------------------
    
    class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
            
        int a, b, cont = 0;
        for (a = 0; a < nums.size(); a++)
        {
            int sum = 0;
            for (b = a; b < nums.size(); b++)
            {
                sum += nums[b];
                if (sum == k)
                    ++cont;
            }
        }
        return cont;
            
        }
    };

    */

    return EXIT_SUCCESS;
}
