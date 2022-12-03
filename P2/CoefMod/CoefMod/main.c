//
//  main.c
//  CoefMod
//
//  Created by Leonardo Alejandro González López on 14/10/21.
//  Copyright © 2021 UASLP. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int minimum(int i, int k);
int coeficienteBinomialMod(int n, int k);

int main()
{
    int n = 6, k = 3;
    printf("Coeficiente binomial es(%d, %d): %d\n", n, k, coeficienteBinomialMod(n, k));
}

int coeficienteBinomialMod(int n, int k)
{
    int i, j, r;
    int *B = (int*)malloc(sizeof(k+1));
    B[0]=1;
    for(i=1;i<=k;i++)
    B[i]=0;

    for(i=1;i<=n;i++)
    {
        for(j=minimum(i,k);j>0;j--)
        B[j]=B[j]+B[j-1];
    }
    
    free(B);
    r=B[k];
    return r;
}

int minimum(i, k)
{
    if (i < k)
        return i;
    else
        return k;
}

