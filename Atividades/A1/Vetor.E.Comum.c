#include <stdio.h>

void verifica(int x[], int y[]){

    int k = 0;
    int comuns[10];

for(int i = 0; i < 10; i++){
    for (int j = 0; j < 10; j++){
        if(x[i] == y[j]){
int existe = 0;

for(int m = 0; m < k; m++){
    if(comuns[m] == x[i]){
        existe = 1;
    break;
    }
}
    if(!existe){
        comuns[k] = x[i];
    k++;
    }
    }
}
}
printf("\nNumeros comuns:\n");

    if(k == 0){
        printf("Nenhum numero comum.\n");
    }else{
        for(int i = 0; i < k; i++){
            printf("%d ", comuns[i]);
        }
    printf("\n");
    }
}

int main(){

    int A[10], B[10];
    
    printf("Digite 10 numeros para o vetor A:\n");
    for (int i = 0; i < 10; i++){
        scanf("%d", &A[i]);
    }
    printf("Digite 10 numeros para o vetor B:\n");
    for (int i = 0; i < 10; i++){
        scanf("%d", &B[i]);
    }
    verifica(A, B);

return 0;
}