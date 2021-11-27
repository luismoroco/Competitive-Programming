#include <bits/stdc++.h>

int main()
{
    std::string w = "hola";
    std::string w1 = "olah";

    std::list<char> wchar;
    std::list<char> w1char;

    for (char c : w)
        wchar.push_back(c);
    for (char c : w1)
        w1char.push_back(c);

    wchar.sort();
    w1char.sort();
    
    if (wchar == w1char)
        std::cout << "Sí";

    return 0;
}