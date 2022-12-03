//
//  main.c
//  CoefBinomDYNAMIC
//
//  Created by Leonardo Alejandro González López on 17/10/21.
//  Copyright © 2021 UASLP. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int minimum(int i, int k);
int coeficienteBinomialPD(int n, int k);

int main()
{
    int n = 60, k = 53;
    clock_t t_ini, t_end;
    double t_elapsed;
    t_ini = clock();
    printf("\n\nTiempo inicial: %f\n\n", ((double)t_ini));
    printf("Coeficiente binomial de %d y %d es: %d\n",n,k, coeficienteBinomialPD(n, k));
    t_end = clock() - t_ini;
    printf("\nTiempo final: %f", ((double)t_end));
    t_elapsed = ((double)t_end)/CLOCKS_PER_SEC;
    printf("\nTotal time: %f segs", t_elapsed);
}

int coeficienteBinomialPD(int n, int k)
{
    int i, j;
    int B[n+1][k+1];

    for(i = 0; i <= n; i++)
        for(j = 0; j <= minimum(i, k); j++)
            if(j == 0 || j == i)
                B[i][j] = 1;
            else
                B[i][j] = B[i - 1][j - 1] + B[i - 1][j];

    return B[n][k];
}

int minimum(i, k)
{
    if (i < k)
        return i;
    else
        return k;
}

