//
//  main.c
//  BubbleSort
//
//  Created by Leonardo Alejandro González López on 17/09/21.
//  Copyright © 2021 UASLP. All rights reserved.
//
//Libraries
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
//Size of array
#define N 200000
//Function Declarations
void generaArr(int array[N]);
void createArray (int array[N]);
void printArr (int array[N]);
int buscaNum(int n, int arr[N]);

//Declaration of sorting functions
void burbuja(int arr[N]);  // Ø(N^2)

void selection(int arr[N]);// Ø(N^2)

void mergeSort(int arr[],int l,int r);// Ø(nlogn)
void merge(int arr[], int l, int m, int r);

void QuickSort(int start, int end, int Datos[N]);// Ø(nlogn)
void Intercambia(int* a, int* b);

// Main function
int main(int argc, const char * argv[]) {
    // Array is static so that the compiler can store it beforehand in memory
    static int arr[N];
    
    // Variables to measure time
    clock_t t_ini, t_end;
    double t_elapsed;
    // To make random numbers
    //srand((unsigned)time(NULL));
    // Create the array with non repeated numbers
//    generaArr(arr);
    // Create the array with repeated numbers
    createArray (arr);
    // WARNING: Only print the array for testing purposes and if N is small
//    printf("\nArreglo sin acomodar:\n");
//    printArr(arr);
    t_ini = clock();
    printf("\n\nTiempo inicial: %f", ((double)t_ini));
    //Sorthing algorithms
    
//    burbuja(arr);
//    selection(arr);
//    mergeSort(arr, 0, N - 1);
    QuickSort(0, N - 1, arr);
    
    // Check the final time and calculate the elapsed time
    
    t_end = clock() - t_ini;
    printf("\nTiempo final: %f", ((double)t_end));
    t_elapsed = ((double)t_end)/CLOCKS_PER_SEC;
    printf("\nTotal time: %f segs", t_elapsed);
    
    // WARNING: Only print the array for testing purposes and if N is small
//    printf ("\n\nArreglo ordenado:\n");
//    printArr(arr);
}
//SORTING METHODS
//
void burbuja(int arr[N])
{
    printf("\n BubbleSort\n");
    int c, i, aux;
    for (c=1; c<=N-1; c++)
            for (i=0;i<=N-2;i++)
                if (arr[i]>arr[i+1])
                {
                    aux=arr[i];
                    arr[i] = arr[i+1];
                    arr[i+1] = aux;
                }
}

//
void selection(int arr[N])
{
    printf("\nSelection Sort\n");
  int i, j, min, tmp;
  for(i=0; i<N; i++)
  {
    min=i;
    for(j=i+1; j<N; j++)
    {
      if(arr[min] > arr[j])
      {
        min=j;
      }
    }
    tmp = arr[min];
    arr[min] = arr[i];
    arr[i] = tmp;
  }
}

//
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
//
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
//
void QuickSort(int start, int end, int Datos[N])
{
    int left = start, right = end, pos = start, band = 1;

    while (band)
    {
        band = 0;

        while (Datos[pos] <= Datos[right] && pos != right)
        {
            right--;
        }

        if (pos != right)
        {
            Intercambia(&Datos[pos], &Datos[right]);
            pos = right;

            while (Datos[pos] >= Datos[left] && pos != left)
            {
                left++;
            }

            if (pos != left)
            {
                Intercambia(&Datos[pos], &Datos[left]);
                pos = left;
                band = 1;
            }
        }
    }

    if (pos - 1 > start)
    {
        QuickSort(start, pos - 1, Datos);
    }

    if (pos + 1 < end)
    {
        QuickSort(pos + 1, end, Datos);
    }
}
//
void Intercambia(int *a, int *b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

//END OF SORTING METHODS
// Prints an array of size N
void printArr(int array[N])
{
   int i;

   printf ("\n\n");
   for (i = 0; i < N; i++)
   {
      printf ("%d, ", array[i]);
   }
}
// Fills an existing array with NON repeated random values
void generaArr(int arr[N]){
    int i, control, aux;
    for (i=0; i<N; i++) {
        do{
            aux= 1+rand()%90;
            control = buscaNum(aux,arr);
        }while (control);
        arr[i]=aux;
    }
}
//
int buscaNum(int n, int arr[]){
    int i,control=0;
    for (i=0; i<N && control==0; i++) {
        if (arr[i]==n) {
            control=1;
        }
    }
    return control;
}
//Fills an existing array with repeated random values
void createArray (int array[N])
{
   int i;
   time_t t;

   srand((unsigned) time(&t));

   for (i = 0; i < N; i++)
   {
      // NOTE: If N is large try to have large numbers in the array
      // otherwise the array would contain many repeated elements
      array[i] = rand() % 1000000;
   }
}
