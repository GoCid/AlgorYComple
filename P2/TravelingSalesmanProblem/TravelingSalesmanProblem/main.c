//
//  main.c
//  TravelingSalesmanProblem
//
//  Created by Leonardo Alejandro González López on 27/10/21.
//  Copyright © 2021 UASLP. All rights reserved.
//

#include<stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#define N 10
/*int P[N][N]={ {0,8,12,18,20},
                {3,0,7,8,10},
                {4,11,0,10,7},
                {6,6,7,0,11},
                {10,6,2,1,0},
            };
 */
int P[N][N];
int completado[N],n=N/* <--- The number of cityx */,costo=0;
void fillGraph(void);
void printCost(void);
void costoMin(int ciudad);
int minimo(int c);

int main(){
    clock_t t_ini, t_end;
    double t_elapsed;
    t_ini = clock();
    //WARNING ONLY FOR SMALL N VALUES
    //printCost();
    fillGraph();
    printf("\nThe way is:\n");
    costoMin(0);
    printf("\nMinimum costo is %d\n ",costo);
    t_end = clock() - t_ini;
    t_elapsed = ((double)t_end)/CLOCKS_PER_SEC;
    printf("\nTotal time: %f segs\n", t_elapsed);
 
}
//
void printCost(void){
    int i, j;
    printf("\n\nThe costo matrix is:");
    
       for( i=0;i < n;i++){
           printf("\n");
    
           for(j=0;j < n;j++)
               printf("\t%d",P[i][j]);
       }
}
//
void costoMin(int ciudad){
    int nciudad;
 
    completado[ciudad]=1;
 
    printf("%d->",ciudad+1);
    nciudad=minimo(ciudad);
 
    if(nciudad==INT_MAX){
        nciudad=0;
        printf("%d",nciudad+1);
        costo+=P[ciudad][nciudad];
 
        return;
    }
 
    costoMin(nciudad);
}
//
int minimo(int c){
    int i,nc=INT_MAX;
    int min=INT_MAX,kmin = 0;
 
    for(i=0;i < n;i++){
        if((P[c][i]!=0)&&(completado[i]==0))
            if(P[c][i]+P[i][c] < min){
                min=P[i][0]+P[c][i];
                kmin=P[c][i];
                nc=i;
            }
    }
 
    if(min!=INT_MAX){
        costo+=kmin;
    }
    return nc;
}
void fillGraph(void){
    
    srand((unsigned)time(NULL));
    int i, j, aux;
    
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            if (i==j) {
                P[i][j]=0;
            }else{
                aux = 1+rand()%30;
                if (aux%5 == 0) {
                    P[i][j]=INT_MAX;
                }else{
                    P[i][j] = aux;
                }
            }
        }
    }
}
