#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 1000  

long long memo[MAX];  

long long x(int n){

    if(n <= 1){
        return 1;
    }
    if(memo[n] != -1){
        return memo[n];  
    }

    memo[n] = x(n - 1) + x(n - 2);  
return memo[n];
}

int main(){

    FILE *fp = fopen("dados_tempo.txt", "w");
    int NMin = 1;
    int NMax = 100;

if(fp == NULL){
        perror("Erro ao abrir o arquivo");
    return 1;
    }  

for(int n = NMin; n <= NMax; n++){
    for(int i = 0; i < MAX; i++){
        memo[i] = -1;
    }
    clock_t start = clock();
        x(n);
    clock_t end = clock();
    double tempo = (double)(end - start) / CLOCKS_PER_SEC;
        fprintf(fp, "%d %.6f\n", n, tempo);
        printf("n = %d, tempo = %.6f segundos\n", n, tempo);
    }
    fclose(fp);
return 0;
}