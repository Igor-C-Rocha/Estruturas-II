#include <stdio.h>

#define M 4

void matriz(){

    int matriz[M][M], soma = 0;

    printf("Digite os numeros da matriz 4x4:\n");

for(int i = 0; i < M; i++){
    for(int j = 0; j < M; j++){
        printf("coluna [%d] numero [%d]:\n", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
for(int i = 0; i < M; i++){
    soma += matriz[i][i];
    }
    printf("Soma da diagonal principal: %d\n", soma);
}

int main(){

    matriz();

return 0;
}