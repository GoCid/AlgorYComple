//
//  main.c
//  BinariaRecursiva
//
//  Created by Leonardo Alejandro González López on 01/10/21.
//  Copyright © 2021 UASLP. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 1000

void createArray (int arr[N]);
void printArray (int arr[N]);
int binarySearch(int arr[], int low, int high, int x);

int main()
{
    static int arr[N];
    createArray (arr);
    //printArray (arr);

    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 14;
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? printf("\nElement %d is not present in array\n", x)
                    : printf("\n\nX(%d) esta en la posicion %d\n", x, result +1);
    return 0;
}


int binarySearch(int arr[N], int low, int high, int x)
{
    int mid;

    if (high >= low) {
        mid = (low + high) / 2;

        if (arr[mid] == x){
            return mid;
        } else if (arr[mid] > x){
            return binarySearch(arr, low, mid - 1, x);
        } else
        return binarySearch(arr, mid + 1, high, x);
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
      array[i] = rand() % 60;
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

