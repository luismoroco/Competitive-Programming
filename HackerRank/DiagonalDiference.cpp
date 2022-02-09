#include <bits/stdc++.h>

using namespace std;


int diagonalDifference(vector<vector<int>> arr) {

    int right = 0, left = 0;
    int tam = arr.size() - 1;
    
    int i = 0, j = 0;
    while (i <= tam && j <= tam) {
        left += arr[i][j];
        ++i; ++j;
    }

    i = 0, j = tam;
    while (i <= tam && j >= 0) {
        right += arr[i][j];
        ++i; --j;
    }

    return abs(right-left);
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> mt(3, vector<int>(3));
    mt = {{1, 2, 3},{4, 5, 6},{9, 8, 9}};

    cout << diagonalDifference(mt) << '\n';

    return 0;
}
