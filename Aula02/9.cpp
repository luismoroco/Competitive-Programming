#include <bits/stdc++.h>

int fib(int n){
    if (n <= 1) return n;
    else 
        return (fib(n - 1) + fib(n - 2));
}

int main(){
    int n;
    
    puts("Ingresa el nth");
    std::cin >> n;

    std::cout << "Respuesta:" << fib(n);
}