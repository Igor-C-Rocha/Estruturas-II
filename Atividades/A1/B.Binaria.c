#include <stdio.h>

int buscaBinaria(int vetor[], int tamanho, int valor){

    int inicio = 0, fim = tamanho - 1;

while(inicio <= fim){

    int meio = (inicio + fim) / 2;
    
    if(vetor[meio] == valor){
        return meio;
    }
    if(valor < vetor[meio]){
        fim = meio - 1;
    }else{
        inicio = meio + 1;
    }
}
return -1;
}

int main(){

    int vetor[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]), valor, resultado;

    printf("de 1 a 10, informe o numero q deseja achar: ");
        scanf("%d", &valor);
resultado = buscaBinaria(vetor, tamanho, valor);

    if(resultado != -1){
        printf("Valor %d encontrado na posicao %d.\n", valor, resultado);
    }else{
        printf("Valor %d nao encontrado.\n", valor);
    }
return 0;
}