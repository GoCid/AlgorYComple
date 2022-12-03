//
//  main.c
//  T1E7
//
//  Created by Leonardo Alejandro González López on 27/08/21.
//  Copyright © 2021 UASLP. All rights reserved.
//
/* Escriban una función en C que encuentre y regrese los m números más grandes de una lista de n números enteros.
   Pueden asumir que la lista de números está en un arreglo. Deberán programar la función para que estén
   completamente seguros de que ésta funciona. Proporcionen una captura de pantalla con la función, y 3 capturas de
   pantalla donde muestre el resultado usando los siguientes datos:
*/
#include <stdio.h>
#include <stdlib.h>
void order(int array[], int n);
void capture(int array[], int n);

int main() {
    int n;
    printf("\n Cuantos datos ingresara? ");
    scanf("%i",&n);
    int x[n];
    capture(x,n);
    int aux, aux2, temp;
    for (aux=0; aux < n; aux ++) {
        for (aux2 = 0 ; aux2 < n; aux++) {
            if (x[aux2] < x[aux2+1]) {
                temp = x[aux2+1];
                x[aux2+1] = x[aux2];
                x[aux2] = temp;
            }
        }
    }
    for (int j =0; j<n; j++) {
        printf("%i ", x[j]);
    }
    printf("\n Cuantos numeros mayores dentro del arreglo quieres conocer? :");
    int m;
    scanf("%i", &m);
    for (int i=0; i<m; i++) {
        printf("\n %i", x[n-i]);
    }

}

void capture(int array[],int n){
    int aux;
    for (aux = 0; aux< n; aux++) {
        printf(" Ingrese dato %i de %i\n", aux+1, n);
        scanf("%i", &array[aux]);
    }
}

