//
//  main.c
//  TorresHanoi
//
//  Created by Leonardo Alejandro González López on 03/10/21.
//  Copyright © 2021 UASLP. All rights reserved.
//

#include "stdio.h"
#include "stdlib.h"
void hanoi(char From, char To, char Other, int n);
int main()
{
    int n = 6, acum = 0;
    hanoi('A','B','C', n);
    printf("%d", acum);
}

void hanoi(char From, char To, char Other, int n)
{
    if (n == 0) {
        return;
    }
    hanoi(From, Other, To, n-1);
    printf("Moviendo disco en la posicion %c a %c\n", From, To);
    hanoi(Other, To, From, n-1);
    
}

