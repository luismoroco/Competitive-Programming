#include <bits/stdc++.h>

int main()
{
    /*
       Comprobar si un número es potencia de 
         2 o no

         ((n & (n-1)) == 0)
        
         digamos que:
         n = 5 -> (n-1) = 4

         5: 0101
         4: 0100   --> Ahora aplicamos &&(AND)
         -------
         &  0100     


         Recordemos que una potencia de 2 : 
         tiene la forma : 00100000 <- termina en 0
         cuando le restamos -1 : 01111111 <- termina en 1 
         entonces para que sea potencia de 2:


         --> 10000000
         &    1111111
         ----------------
               10000000 <-- obtenemos la forma de potencia

        <-----binary-- --> 
        n     n    n-1  n&(n-1)
        --------------------------
        0   0000  0111  0000 
        1   0001  0000  0000 *
        2   0010  0001  0000 *
        3   0011  0010  0010 
        4   0100  0011  0000 *
    */
   
    return EXIT_SUCCESS;
}