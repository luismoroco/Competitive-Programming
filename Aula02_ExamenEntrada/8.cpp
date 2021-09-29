#include <bits/stdc++.h>
using namespace std;

/*
* Escriba una función que determine el número de bits 
* requeridos para transformar un numero entero A en un
* numero entero B. Ejemplo
* Input: 31, 14
* Output: 2
*/

vector<int> convert(int x)
{
    vector<int> ret;
    while (x)
    {
        if (x & 1)
            ret.push_back(1);
        else
            ret.push_back(0);
        x >>= 1;
    }
    reverse(ret.begin(), ret.end());

    for (auto v : ret)
        cout << v << ' ';
    cout << '\n';

    return ret;
}

int main()
{
    vector<int> first = convert(19);
    vector<int> target = convert(23);

    int numbit = 0, tam = first.size();

    for ( int i = 0; i < tam; ++i)
    {
        if (first[i] == target[i]) continue;
        else ++numbit;
    }

    cout << numbit << '\n';

    return EXIT_SUCCESS;
}