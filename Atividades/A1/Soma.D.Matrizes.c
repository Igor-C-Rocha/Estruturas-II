#include <stdio.h>

#define N 3

void Soma(int A[][N], int B[][N], int S[][N]){

for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
        S[i][j] = A[i][j] + B[i][j];
        }
    }
}

void exibe(int S[][N]){

    printf("\nMatriz resultante (A + B):\n");
for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
        printf("%d\t", S[i][j]);
    }
    printf("\n");
    } 
}

int main(){

    int A[N][N], B[N][N], resultado [N][N];

    printf("Informe os numeros da matriz A(3x3):\n");
for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
        printf("A [%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
    printf("\nInforme os numeros da matriz B(3x3):\n");
for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
        printf("B [%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }
    Soma(A, B, resultado);
    exibe(resultado);
    
return 0;
}