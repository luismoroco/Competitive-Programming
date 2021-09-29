#include <bits/stdc++.h>
using namespace std;

/*
 * Dados dos arrays ordenados A y B con n y m valores 
 * respectivamente.Considere que el array A tiene espacio
 * suficiente para contener a los elementos de B.
 * Escriba una función que copie los elementos de B en A
 * manteniendo el orden.
*/

void merge(vector<int> &x, vector<int> &y)
{
    vector<int> anwr;
    int steps = x.size() + y.size();

    int xi = 0, yi = 0;
    while (xi + yi != steps)
    {
        if (xi < x.size() && yi < y.size())
        {
            if (x[xi] < y[yi])
            {
                anwr.push_back(x[xi]);
                ++xi;
            }
            else
            {
                anwr.push_back(y[yi]);
                ++yi;
            }
        }
        else if (xi < x.size())
        {
            anwr.push_back(x[xi]);
            ++xi;
            continue;
        }
        else if (yi < y.size())
        {
            anwr.push_back(y[yi]);
            ++yi;
            continue;
        }
        else
            break;
    }

    for (auto v : anwr)
        cout << v << ' ';
}

int main()
{
    vector<int> A = {9, 12, 34, 56, 111};
    vector<int> B = {8, 57, 98, 123, 200};
    merge(A, B);

    return 0;
}