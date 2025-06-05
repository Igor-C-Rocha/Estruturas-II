#include <stdio.h>
#include <time.h>

#define MAX 1000

long long x_iterativo(int n){

if(n <= 1){
    return 1;
}
    long long prev2 = 1;
    long long prev1 = 1;
    long long atual = 0;

for(int i = 2; i <= n; i++){
    atual = prev1 + prev2;
    prev2 = prev1;
    prev1 = atual;
    }
return atual;
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

    clock_t start = clock();
    long long resultado = x_iterativo(n);
    clock_t end = clock();
    double tempo = (double)(end - start) / CLOCKS_PER_SEC;
fprintf(fp, "%d %.6f\n", n, tempo);
printf("n = %d, x(n) = %I64d, tempo = %.6f segundos\n", n, resultado, tempo);
    }
    fclose(fp);
return 0;
}