//invertexto.com/rzak36
#include <stdio.h>
#include <stdlib.h>

// Definição do nó da árvore binária
typedef struct Node{

    int valor;
    struct Node *esquerda;
    struct Node *direita;

}Node;

Node* criarNo(int valor){

Node* novo = malloc(sizeof(Node));

    if(novo){
        novo->direita = NULL;
        novo->esquerda = NULL;
        novo->valor = valor;
    }
return novo;
}

Node* inserir(Node* raiz, int valor){

    if(raiz == NULL){
        return criarNo(valor);
    }
    if(valor < raiz->valor){
        raiz->esquerda = inserir(raiz->esquerda, valor);
    }else{
        raiz->direita = inserir(raiz->direita, valor);
    }
return raiz;
}

void preOrdem(Node* raiz){

    if(raiz != NULL){
        printf("%d\n", raiz->valor);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

void Ordem(Node* raiz){

    if(raiz != NULL){
        Ordem(raiz->esquerda);
        printf("%d\n", raiz->valor);
        Ordem(raiz->direita);
    }
}

void posOrdem(Node* raiz){

    if(raiz != NULL){
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf("%d\n", raiz->valor);
    }
}

int maior(int a, int b){

    if(a > b){
        return a;
    }
return b;
}

int h(Node* no){

    if(no == NULL){
        return -1;
    }
return maior(h(no->esquerda), h(no->direita)) + 1;
}

int main(){

    Node* raiz = NULL;
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 15);
    raiz = inserir(raiz, 18);
    raiz = inserir(raiz, 23);
    raiz = inserir(raiz, 31);
    preOrdem(raiz);
    printf("\n");
    Ordem(raiz);
    printf("\n");
    posOrdem(raiz);
    printf("\n");
    printf("Altura 20: %d\n", h(raiz));

return 0;
}