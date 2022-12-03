//
//  main.c
//  DivideNconquer
//
//  Created by Leonardo Alejandro González López on 17/10/21.
//  Copyright © 2021 UASLP. All rights reserved.
//

#include <stdio.h>
#include <time.h>
int coeficienteBinomialDyV(int n, int k)
{
    if(k == 0 || n == k)
        return 1;
    else
        return coeficienteBinomialDyV(n - 1, k - 1) + coeficienteBinomialDyV(n - 1, k);
}

int main()
{
    int n = 60, k =53;
    clock_t t_ini, t_end;
    double t_elapsed;
    t_ini = clock();
    printf("Coeficiente binomial es(%d, %d): %d", n, k, coeficienteBinomialDyV(n, k));
    t_end = clock() - t_ini;
    t_elapsed = ((double)t_end)/CLOCKS_PER_SEC;
    printf("\nTotal time: %f segs\n", t_elapsed);
}
