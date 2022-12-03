//
//  main.c
//  Palindromo
//
//  Created by Leonardo Alejandro González López on 20/10/21.
//  Copyright © 2021 UASLP. All rights #

#include <stdio.h>
#include <string.h>
#include <time.h>
#define MAX(a,b) (((a)>(b))?(a):(b))
unsigned long n;
int findLongestPalindrome(char *x);
void setDiagonal(int a[][n]);
void palindrome(char *x, int a[][n]);


int main(){
    clock_t t_ini, t_end;
    double t_elapsed;
    t_ini = clock();
    char *x = "poasierioseorsiawipoasierioseorsiawipoasierioseorsiawipoasierioseorsiawipoasierioseorsiawipoasierioseorsiawipoasierioseorsiawipoasierioseorsiawipoasierioseorsiawipaoudhfpqoweuqpwefpqubcqppoasierioseorsiawipoasierioseorsiawipoasierioseorsiawipoasierioseorsiawipoasierioseorsiawipoasierioseorsiawipoasierioseorsiawipoasierioseorsiawipoasierioseorsiawipaoudhfpqoweuqpwefpqubcqppoasierioseorsiawipoasierioseorsiawipoasierioseorsiawipoasierioseorsiawipoasierioseorsiawipoasierioseorsiawipoasierioseorsiawipoasierioseorsiawipoasierioseorsiawipaoudhfpqoweuqpwefpqubcqppoasierioseorsiawipoasierioseorsiawipoasierioseorsiawipoasierioseorsiawipoasierioseorsiawipoasierioseorsiawipoasierioseorsiawipoasierioseorsiawipoasierioseorsiawipaoudhfpqoweuqpwefpqubcqppoasierioseorsiawipoasierioseorsiawipoasierioseorsiawipoasierioseorsiawipoasierioseorsiawipoasierioseorsiawipoasierioseorsiawipoasierioseorsiawipoasierioseorsiawipaoudhfpqoweuqpwefpqubcqppoasierioseorsiawipoasierioseorsiawipoasierioseorsiawipoasierioseorsiawipoasierioseorsiawipoasierioseorsiawipoasierioseorsiawipoasierioseorsiawipoasierioseorsiawipaoudhfpqoweuqpwefpqubcqppqpoirehfpqoiwreipoasierioseorsiawipoasierioseorsiawipoasierioseorsiawipaoudhfpqoweuqpwefpqubcqppoasierioseorsiawipoasierioseorsiawipoasierioseorsiawipoasierioseorsiawipoasierioseorsiawipoasierioseorsiawipoasierioseorsiawipoasierioseorsiawipoasierioseorsiawipaoudhfpqoweuqpwefpqubqoiwherfoiqwcasdasdfaartyhfeqwetrfwerwpowerty";
    n = strlen(x);
    printf(" The sequence is: \n The size of the sequence is: %lu\n", n);
    int a[n][n];
    palindrome(x, a);
    t_end = clock() - t_ini;
    t_elapsed = ((double)t_end)/CLOCKS_PER_SEC;
    printf("\nTotal time: %f segs", t_elapsed);//    for (int i=0; i<n; i++) {
//        for (int j=0; j<n; j++) {
//            printf("%i\t", a[i][j]);
//        }
//        printf("\n");
//    }
//    printf(" Lenght of palindrome is: %d\n", findLongestPalindrome(x));
}
//
int findLongestPalindrome(char *x){
    long n = strlen(x);
    int i, j, cl;
    int L[n][n];
    for (i=0; i<n; i++) {
        L[i][i]=1;
    }
    for (cl=2; cl<=n; cl++) {
        for (i=0; i<n-cl+1; i++) {
            j=i+cl-1;
            if (x[i]==x[j]&&cl==2) {
                L[i][j]=2;
            }else if (x[i]==x[j]){
                L[i][j]=L[i+1][j-1]+2;
            }else{
                L[i][j]= MAX(L[i][j-1], L[i+1][j]);
            }
        }
    }
    return L[0][n-1];
}
//
void setDiagonal(int a[][n]){
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i==j) {
                a[i][j]=1;
            }else{
                a[i][j]=0;
            }
        }
    }
}
//
void palindrome(char *x, int a[][n]){
    setDiagonal(a);
    int l = 1;
    while(l <= n-1){
        int i = 0;
        while(i+l <=n-1){
            int j = i+l;
            if(x[i] == x[j])
                a[i][j] = a[i+1][j-1] + 2;
            else
            {
                if(a[i+1][j] > a[i][j-1])
                    a[i][j] = a[i+1][j];
                else
                     a[i][j] = a[i][j-1];
            }
            
            i = i + 1;
        }
        
        l = l + 1;
    }
    int palLenght = a[0][n-1];
    char palindromo[palLenght];
    int i = 0, palStart = 0, palEnd = palLenght-1;
    unsigned long j = n-1;
    
    while (palEnd -palStart >= 1) {
        if (x[i]==x[j]) {
            palindromo[palStart]= x[i];
            palindromo[palEnd] = x[i];
            palStart = palStart + 1;
            palEnd = palEnd - 1;
            i = i+1;
            j = j-1;
        }else if (a[i+1][j]>a[i][j-1]){
            i=i+1;
        }else{
            j = j -1;
        }
    }
    if (palEnd==palStart) {
        palindromo[palEnd]= x[i];
    }
    printf(" The palindrome is %s\n", palindromo);
}
