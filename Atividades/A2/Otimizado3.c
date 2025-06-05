#include <stdio.h>
#include <time.h>
#include <math.h>

long long x_binet(int n){

    double sqrt5 = sqrt(5.0);
    double phi = (1 + sqrt5) / 2;
    double psi = (1 - sqrt5) / 2;
    double result = (pow(phi, n) - pow(psi, n)) / sqrt5;

return (long long)(result + 0.5); 
}

int main(){

    FILE *fp = fopen("dados_tempo.txt", "w");
    int NMin = 1;
    int NMax = 1000;

if(fp == NULL){
        perror("Erro ao abrir o arquivo");
    return 1;
    }  
for(int n = NMin; n <= NMax; n++){

    clock_t start = clock();
    long long resultado = x_binet(n);
    clock_t end = clock();
    double tempo = (double)(end - start) / CLOCKS_PER_SEC;
        fprintf(fp, "%d %.6f\n", n, tempo);
        printf("n = %d, x(n) = %lld, tempo = %.6f segundos\n", n, resultado, tempo);
    }
    fclose(fp);
return 0;
}