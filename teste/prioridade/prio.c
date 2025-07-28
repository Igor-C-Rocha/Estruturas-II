#include <stdio.h>
#include <stdlib.h>

typedef struct no{

    int valor;
    struct no *prox;

}No;

void inserir(No **fila, int num){

No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->prox = NULL;
    if(*fila == NULL){
            *fila = novo;
        }else{
            aux = *fila;
        while(aux->prox){
            aux = aux->prox;
            }
    aux->prox = novo;
        }
    }else{
        printf("Erro\n");
    }
}

void inserir_prioridade(No **fila, int num){

No *aux, *ant = NULL, *novo = malloc(sizeof(No));
novo->valor = num;
novo->prox = NULL;

    if(!novo){
        printf("Erro\n");
    return;
    }

    if(*fila == NULL){
        *fila = novo;
    }else if (num <= 59){
        //não prioritária
            aux = *fila;
        while(aux->prox){
            aux = aux->prox;
        }
        aux->prox = novo;
    }else{
        //prioridade decrescente
            aux = *fila;
        //prioridade crescente
        if(aux->valor <= 59 || aux->valor < num){
            novo->prox = *fila;
            *fila = novo;
        }else{
            while(aux && aux->valor >= 60 && aux->valor >= num){
                ant = aux;
                aux = aux->prox;
            }
            novo->prox = aux;
            ant->prox = novo;
        }
    }
}

No* remover(No **fila){

No *remover = NULL;

    if(*fila){
        remover = *fila;
        *fila = (*fila)->prox;
    }else{
        printf("Fila vazia\n");
    }
    return remover;
}

void imprimir(No *fila){

printf("------ FILA ------\n");
    while(fila){
        printf("%d\n", fila->valor);
    fila = fila->prox;
    }
}

int main(){

    No *r, *fila = NULL;
    int opcao, valor;

    do{
        printf("\n1 - inserir\n");
        printf("2 - inserir com irioridade\n");
        printf("3 - remover\n");
        printf("4 - imprimir\n");
        printf("5 - sair\n");
        printf("escolha: ");
        scanf("%d", &opcao);

    switch(opcao){
            case 1:
                printf("digite um valor: ");
                    scanf("%d", &valor);
                inserir(&fila, valor);
        break;
            case 2:
                printf("digite um valor: ");
                    scanf("%d", &valor);
                inserir_prioridade(&fila, valor);
        break;
            case 3:
                r = remover(&fila);
                if(r != NULL){
                    free(r);
                }
        break;
            case 4:
                imprimir(fila);
        break;
            case 5:
                printf("saindo\n");
                exit(0);
        default:
                printf("errado\n");
        }

    }while(opcao != 0);
return 0;
}