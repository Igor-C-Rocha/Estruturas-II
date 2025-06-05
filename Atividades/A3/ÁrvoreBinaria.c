#include <stdio.h>
#include <stdlib.h>

typedef struct no{

    int valor;              
    struct no* esquerda;   
    struct no* direita;

}No;

No* criar(int valor){

    No * novo = (No*)malloc(sizeof(No));
        if(novo == NULL){
    printf("Erro!\n");
        exit(1);
    }

    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
return novo;
}

No* inserir(No* raiz, int aux){

    if(raiz == NULL){
        return criar(aux);
    }

    if(aux < raiz->valor){

        raiz->esquerda = inserir(raiz->esquerda, aux);
    }else if(aux > raiz->valor){

        raiz->direita = inserir(raiz->direita, aux);
    }
return raiz;
}

No* buscar(No* raiz, int aux){

    if(raiz == NULL || raiz->valor == aux){
        return raiz;
    }
    if(aux < raiz->valor){

        return buscar(raiz->esquerda, aux);
    }else{

        return buscar(raiz->direita, aux);
    }
}

No* Minimo(No* raiz){

    while(raiz && raiz->esquerda != NULL){

        raiz = raiz->esquerda;
    }
return raiz;
}

No* remover(No* raiz, int aux){

    if(raiz == NULL){
        return NULL;
    }
    if(aux < raiz->valor){

        raiz->esquerda = remover(raiz->esquerda, aux);
    }else if(aux > raiz->valor){

        raiz->direita = remover(raiz->direita, aux);
    }else{
        if(raiz->esquerda == NULL){

        No* temp = raiz->direita;

        free(raiz);
            return temp;
        }else if(raiz->direita == NULL){

        No* temp = raiz->esquerda;

        free(raiz);
            return temp;
        }
        No* temp = Minimo(raiz->direita);

    raiz->valor = temp->valor;
    raiz->direita = remover(raiz->direita, temp->valor);
    }
return raiz;
}

int Altura(No* raiz){

    int alturaDireita, alturaEsquerda;

    if(raiz == NULL){
        return -1;
    }

    alturaEsquerda = Altura(raiz->esquerda);
    alturaDireita = Altura(raiz->direita);

return 1 + (alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita);
}

int Profundidade(No* raiz, int aux){

int profundidadeEsq, profundidadeDir;

    if(raiz == NULL){
        return -1;
    }
    if(raiz->valor == aux){
        return 0; 
    }
    if(aux< raiz->valor){

        profundidadeEsq = Profundidade(raiz->esquerda, aux);
    return(profundidadeEsq == -1) ? -1 : 1 + profundidadeEsq;
    }else{

        profundidadeDir = Profundidade(raiz->direita, aux);
    return (profundidadeDir == -1) ? -1 : 1 + profundidadeDir;
    }
}

int somarValores(No* raiz){

    if(raiz == NULL){
        return 0;
    }
return raiz->valor + somarValores(raiz->esquerda) + somarValores(raiz->direita);
}

int calcularNivel(No* raiz, int aux, int nivelAtual){

    if(raiz == NULL){
        return -1;
    }
    if(raiz->valor == aux){
        return nivelAtual;
    }
    if(aux < raiz->valor){

        return calcularNivel(raiz->esquerda, aux, nivelAtual + 1);
    }else{

        return calcularNivel(raiz->direita, aux, nivelAtual + 1);
    }
}

int contarNos(No* raiz){

    if(raiz == NULL){
        return 0;
    }
return 1 + contarNos(raiz->esquerda) + contarNos(raiz->direita);
}

int contarFolhas(No* raiz){

    if(raiz == NULL){
        return 0;
    }
    if(raiz->esquerda == NULL && raiz->direita == NULL){
        return 1; 
    }

return contarFolhas(raiz->esquerda) + contarFolhas(raiz->direita);
}

void preOrdem(No* raiz){

    if(raiz != NULL){
        printf("\n%d ", raiz->valor);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

void Ordem(No* raiz){

    if(raiz != NULL){
        Ordem(raiz->esquerda);
        printf("\n%d ", raiz->valor);
        Ordem(raiz->direita);
    }
}

void posOrdem(No* raiz){

    if(raiz != NULL){
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf("\n%d ", raiz->valor);
    }
}

int main(){

    No* raiz = NULL;
    int valorBusca = 80;
    No* resultado;

    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 60);
    raiz = inserir(raiz, 80);

resultado = buscar(raiz, valorBusca);

    printf("Em ordem: ");
        Ordem(raiz);
    printf("\n");

    printf("Pre ordem: ");
        preOrdem(raiz);
    printf("\n");

    printf("Pos ordem: ");
        posOrdem(raiz);
    printf("\n");

    if(resultado != NULL){
        printf("Valor %d encontrado\n", valorBusca);
        printf("\n");
    }else{
        printf("Valor %d nao encontrado.\n", valorBusca);
        printf("\n");
    }

    printf("Altura da arvore: %d\n", Altura(raiz));
    printf("\n");
    printf("Profundidade do no %d: %d\n", valorBusca, Profundidade(raiz, valorBusca));
    printf("\n");
    printf("Soma dos valores na arvore: %d\n", somarValores(raiz));
    printf("\n");
    printf("Numero de nos: %d\n", contarNos(raiz));
    printf("\n");
    printf("Numero de folhas: %d\n", contarFolhas(raiz));

raiz = remover(raiz, 30);

    printf("\n");
    printf("Apos remover 30, em ordem: ");
        Ordem(raiz);
    printf("\n");
return 0;
}