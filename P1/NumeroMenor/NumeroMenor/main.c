//
//  main.c
//  NumeroMenor
//
//  Created by Leonardo Alejandro González López on 05/09/21.
//  Copyright © 2021 UASLP. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 25
//
void genera(int arr[N]);
void imprime(int arr[N]);
void busca(int arr[N]);
void menor(int arr[N]);
int buscaNum(int n, int arr[N], int r);
//
int main() {
    srand((unsigned)time(NULL));
    int arr[N];
    genera(arr);
    imprime(arr);
    busca(arr);
    
}

//
void genera(int arr[N]){
    int i, control, aux;
    for (i=0; i<N; i++) {
        do{
            aux= 1+rand()%90;
            control = buscaNum(aux,arr,N);
        }while (control);
        arr[i]=aux;
    }
}
//
int buscaNum(int n, int arr[N], int r){
    int i,control=0;
    for (i=0; i<r && control==0; i++) {
        if (arr[i]==n) {
            control=1;
        }
    }
    return control;
}
//
void imprime(int arr[N]){
    int i;
    printf("\n Los datos son:\n");
    for (i=0; i<N; i++) {
        printf(" %d, ", arr[i]);
    }
}
//
void busca(int arr[N]){
    int menor = arr[0], i;
    for (i=1; i<N; i++) {
        if (arr[i]<menor) {
            menor = arr[i];
        }
    }
    printf("\n El numero menor es: %d\n", menor);
}
