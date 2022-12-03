//
//  main.c
//  Subconjuntos
//
//  Created by Leonardo Alejandro González López on 05/09/21.
//  Copyright © 2021 UASLP. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10 //20 //25
//
void genera(int arr[]);
void imprime(int arr[]);
int buscaNum(int n, int arr[]);
void subconjunto(int arr[]);
//

int main(int argc, const char * argv[]) {
    int arr[N];
    genera(arr);
    imprime(arr);
    subconjunto(arr);
}
//
void imprime(int arr[]){
    int i;
    printf("\n Los datos son:\n");
    for (i=0; i<N; i++) {
        printf(" %d, ", arr[i]);
    }
}
//
void genera(int arr[]){
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
//
void subconjunto(int arr[]){
    int i;
    for (i=0; i<4; i++) {
        if (i<4) {
            printf("%d", arr[i]);
            subconjunto(arr);
        }
    }
}
//recursiva?
