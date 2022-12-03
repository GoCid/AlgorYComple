//
//  main.c
//  BinaryModif
//
//  Created by Leonardo Alejandro González López on 01/10/21.
//  Copyright © 2021 UASLP. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 1000

void createArray (int arr[N]);
void printArray (int arr[N]);
int tripleSearch(int arr[], int low, int high, int x);

int main()
{
    int arr[N];
    createArray (arr);
    //printArray (arr);

    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 15;
    int result = tripleSearch(arr, 0, n - 1, x);
    if (result == -1){
        printf("\n\nElement is not present in array\n");
    }else {
        printf("\n\nX(%d) esta en la posicion %d\n", x, result+1);
    }
    return 0;
}


int tripleSearch(int arr[N], int low, int high, int x)
{
    if (high >= low)
   {
       int midl = low + (high - low)/3;
       int midh = midl + (high - low)/3;

       if (arr[midl] == x) {
           return midl;
       }
       if (arr[midh] == x) {
           return midh;
       }
       if (arr[midl] > x) {
           return tripleSearch(arr, low, midl - 1, x);
       }
       if (arr[midh] < x){
           return tripleSearch(arr, midh+1, high, x);
       }
       return tripleSearch(arr, midl+1, midh-1, x);
   }else{
       return -1;
   }
}

void createArray (int array[N])
{
   int i;
   time_t t;

   srand((unsigned) time(&t));

   for (i = 0; i < N; i++)
   {
      array[i] = rand() % 100;
   }
}

void printArray (int array[N])
{
   int i;

   printf ("\n\n");
   for (i = 0; i < N; i++)
   {
      printf ("%d, ", array[i]);
   }
}

