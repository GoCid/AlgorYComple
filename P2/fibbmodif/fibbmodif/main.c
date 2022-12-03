//
//  main.c
//  fibbmodif
//
//  Created by Leonardo Alejandro González López on 25/10/21.
//  Copyright © 2021 UASLP. All rights reserved.
//

//Fibonacci Series using Dynamic Programming
#include<stdio.h>

int fib(int n);

int main ()
{
int n = 6;
printf("\n%d", fib(n));

return 0;
}

int fib(int n){

int f[n+2];
int i;

f[0] = 0;
f[1] = 1;

for (i = 2; i <= n; i++){
   
    f[i] = f[i-1] + f[i-2];
    
}
    for (i=0; i<=n; i++) {
        printf("%i ", f[i]);
    }
return f[n];
}

int operation(int n, int x){
    int r;
    
    return r;
}
