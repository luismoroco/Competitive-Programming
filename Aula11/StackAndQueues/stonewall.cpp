#include <bits/stdc++.h>
using namespace std;

// https://app.codility.com/programmers/lessons/7-stacks_and_queues/stone_wall/

int solution(vector<int> &A) 
{
    sort(A.begin(), A.end());
    int size = (int)A.size();
    
    return max(A[0] * A[1] * A[size - 1], 
                A[size - 3] * A[size - 2] * A[size - 1]); 
}

int main()
{
    vector<int> x = {8, 8, 5, 7, 9, 8, 7, 4, 8};
    solution(x);

    return 0;   
}