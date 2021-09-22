#include <bits/stdc++.h>

void sort(std::stack<int> s)
{
    std::stack<int> aux;
    while (!s.empty())
    {
        int temp = s.top();
        s.pop();
        while (!aux.empty() && aux.top() < temp)
        {
            s.push(aux.top());
            aux.pop();
        }
        aux.push(temp);
    }

    while (!aux.empty())
    {
        std::cout << aux.top() << ' ';
        aux.pop();
    }
}

int main()
{
    std::stack<int> pila;
    pila.push(5);
    pila.push(1);
    pila.push(4);

    sort(pila);

    return 0;
}
