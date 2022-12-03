//
//  main.c
//  NumeroMayor
//
//  Created by Leonardo Alejandro González López on 05/09/21.
//  Copyright © 2021 UASLP. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//
void genera(int arr[], int tam);
void imprime(int arr[], int tam);
void ordena(int arr[], int tam);
void mayor(int arr[], int m);
int buscaNum(int n, int arr[], int r);
//
int main() {
    srand((unsigned)time(NULL));
    int tam, m;
    printf("\n De que tamaño es el areglo?\n");
    scanf("%d",&tam);
    printf("\n Cuantos mayores quieres conocer?\n");
    scanf("%d",&m);
    int arr[tam];
    genera(arr,tam);
    imprime(arr,tam);
    ordena(arr,tam);
    mayor(arr,m);
}

//
void genera(int arr[], int tam){
    int i, control, aux;
    for (i=0; i<tam; i++) {
        do{
            aux= 1+rand()%90;
            control = buscaNum(aux,arr,tam);
        }while (control);
        arr[i]=aux;
    }
}
//
int buscaNum(int n, int arr[], int tam){
    int i,control=0;
    for (i=0; i<tam && control==0; i++) {
        if (arr[i]==n) {
            control=1;
        }
    }
    return control;
}
//
void imprime(int arr[], int tam){
    int i;
    printf("\n Los datos son:\n");
    for (i=0; i<tam; i++) {
        printf(" %d, ", arr[i]);
    }
}
//
void ordena(int arr[], int tam){
    int i, j, aux;
    for (i=1; i<=tam-1; i++)
            for (j=0;j<=tam-2;j++)
                if (arr[j]>arr[j+1])
                {
                    aux=arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = aux;
                }
}
//
void mayor(int arr[], int m){
    int i;
    printf("\n Los %d numeros mayores son: \n", m);
    for (i=0; i<m; i++) {
        printf(" %d, ", arr[i]);
    }
    printf("\n");
}
