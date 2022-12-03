//
//  main.c
//  Ejercicio6
//
//  Created by Leonardo Alejandro González López on 02/10/21.
//  Copyright © 2021 UASLP. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#define N 6

void createArray (int array[N]);
void printArray (int array[N]);
int divideYagrega(int arr[N], int x);
int mayor(int a,int b);
int findMay(int arr[]);
int findMaxRec(int arr[], int i, int sumCalculated, int sumTotal);
int main ()
{
//    static int arr[N];
   // Create the array with random elements
//    createArray (arr);
   // WARNING: Only print the array for testing purposes and if N is small
    static int arr[] = {8, 4, 3, 7, 10, 9};
   // WARNING: Only print the array for testing purposes and if N is small
   
    printArray (arr);
    printf("\n La diferencia es: %d ", findMay(arr));
   return 0;
}

// Function to find the max sum
int findMaxRec(int arr[], int i, int sumCalculated, int sumTotal)
{
    
    if (i==0){
        return abs((sumTotal-sumCalculated) - sumCalculated);
    }else{
  
    return mayor(findMaxRec(arr, i-1, sumCalculated+arr[i-1], sumTotal), findMaxRec(arr, i-1, sumCalculated, sumTotal));
    }
}
  
int findMay(int arr[])
{
    
    int sumTotal = 0;
    for (int i=0; i<N; i++){
        sumTotal += arr[i];
    }
    return findMaxRec(arr, N, 0, sumTotal);
}

int mayor(int a,int b) {
    if (a>b) {
        return a;
    }else{
        return b;
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

// Fills an existing array with random values
void createArray (int array[N])
{
   int i;

   for (i = 0; i < N; i++)
   {
      // NOTE: If N is large try to have large numbers in the array
      // otherwise the array would contain many repeated elements
      array[i] = rand() % 10;
   }
}
