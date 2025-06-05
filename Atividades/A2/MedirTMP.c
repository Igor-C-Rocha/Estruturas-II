#include <stdio.h>
#include <time.h>

int x(int n){

    if (n <= 1){ 
        return 1;
    }
return x(n - 1) + x(n - 2);
}

int main(){

    FILE *fp = fopen("dados_tempo.txt", "w");
    int NMin = 1;
    int NMax = 40;

if(fp == NULL){
    perror("Erro ao abrir o arquivo");
return 1;
} 

for(int n = NMin; n <= NMax; n++){

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