#include <bits/stdc++.h>
using namespace std;
int temp, i, j, x, cont, n, k, xx;

struct compare{
    bool operator()(const int& l, const int& r){
        return l < r;
    }
};

int process(int arr[], int n){
    int mid = arr[n/2];
	int mid1 = arr[(n/2)-1];
	int res = 0, res1 = 0;
    
	for(int i = 0; i < n; i++){
		res = res + abs(arr[i] - mid);
		res1 = res1 + abs(arr[i] - mid1);
	}
    return res < res1 ? res : res1;
}

typedef multiset<int, compare> iArr;
int main()
{
    /*
    // ejecutarlo en un paso

    int array[] = {2, 4, 3, 5, 8, 1, 2, 1}; // 243 435 358 ... 121
    int n = 8, k = 3;
    int dyna[k]; 
    */

    cin >> n >> k;
    xx = n;
    int array[n];
    int dyna[k];
    
    int x = 0;
    while (xx--){
        cin >> array[x];
        ++x;
    }
    
    for (i = 0; i <= n - k; ++i){
        iArr arr;
        for (j = 0; j < k; ++j) arr.insert(array[i+j]);
        
        cont = 0;
        for (auto c : arr){
            dyna[cont] = c;
            ++cont;
        }
        cout << process(dyna,k) << ' ';
    }

    return EXIT_SUCCESS;
}