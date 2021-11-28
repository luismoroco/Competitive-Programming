#include <bits/stdc++.h>
using namespace std;

// https://www.beecrowd.com.br/judge/es/problems/view/2917

int cutTheString(int t, vector<int> &v) {
    int max_sum = 0;
    int sum = 0;
    for (int i = 0; i < v.size(); ++i) {
        sum += v[i];
        if (sum > max_sum) {
            max_sum = sum;
        }
        if (sum < 0) {
            sum = 0;
        }
    }
    return max_sum;
}

int main(int argc, char const *argv[])
{
    int t = 1;
    vector<int> x = {1, 2, 3, 4, 5, -6, -7, -8, -9, 1};
    cout << cutTheString(t, x) << '\n';

    return 0;
}