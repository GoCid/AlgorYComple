//
//  main.c
//  MergeIterativo
//
//  Created by Leonardo Alejandro González López on 01/10/21.
//  Copyright © 2021 UASLP. All rights reserved.
//

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

// Total size of the array

#define N 20

void createArray (int array[N]);
void printArray (int array[N]);


void mergeSort(int arr[], int n);
void merge(int arr[], int l, int m, int r);
int min(int x, int y);


int main ()
{
   static int arr[N];
   int n = sizeof(arr)/sizeof(arr[0]);

   clock_t t_ini, t_end;
   double t_elapsed;

   
   createArray (arr);
   
   printf ("\n\nUNSORTED ARRAY:\n");
   printArray (arr);
   t_ini = clock();
   printf ("\n\nInitial time: %f", ((double)t_ini));
   mergeSort(arr, n);


   t_end = clock() - t_ini;
   printf ("\nFinal time: %f", ((double)t_end));
   t_elapsed = ((double)t_end)/CLOCKS_PER_SEC;
   printf ("\nTotal time: %f segs", t_elapsed);

   // WARNING: Only print the array for testing purposes and if N is small
   printf ("\n\nSORTED ARRAY:\n");
   printArray (arr);
    printf("\n");
   return 0;
}

//iterativemerge
void mergeSort(int arr[], int n)
{
   int curr_size;
                   
   int left_start;
                   
   for (curr_size=1; curr_size<=n-1; curr_size = 2*curr_size)
   {
       
       for (left_start=0; left_start<n-1; left_start += 2*curr_size)
       {
           
           int mid = min(left_start + curr_size - 1, n-1);

           int right_end = min(left_start + 2*curr_size - 1, n-1);

           merge(arr, left_start, mid, right_end);
       }
   }
}


void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    
    int L[n1], R[n2];

   
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

  
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

int min(int x, int y) { return (x<y)? x :y; }


// Prints an array of size N
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
   time_t t;

   srand((unsigned) time(&t));

   for (i = 0; i < N; i++)
   {
      // NOTE: If N is large try to have large numbers in the array
      // otherwise the array would contain many repeated elements
      array[i] = rand() % 2000;
   }
}


