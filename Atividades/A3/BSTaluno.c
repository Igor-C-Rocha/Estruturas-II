#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 999

typedef struct aluno{

    int matricula;
    char nome[MAX];
    float nota;

}Aluno;

typedef struct no{

    Aluno dados;
    struct no* esquerda;
    struct no* direita;

}No;

No* criar(int matricula, char* nome, float nota){

    No* novo = (No*)malloc(sizeof(No));

    if(novo == NULL){
    printf("Erro!\n");
        exit(1);
    }

    novo->dados.matricula = matricula;
    strcpy(novo->dados.nome, nome);
    novo->dados.nota = nota;
    novo->esquerda = NULL;
    novo->direita = NULL;

return novo;
}

No* inserir(No* raiz, int matricula, char* nome, float nota){

    if(raiz == NULL){
        return criar(matricula, nome, nota);
    }
    if(matricula < raiz->dados.matricula){

        raiz->esquerda = inserir(raiz->esquerda, matricula, nome, nota);
    }else if(matricula > raiz->dados.matricula){

        raiz->direita = inserir(raiz->direita, matricula, nome, nota);
    }
return raiz;
}

No* buscarNome(No* raiz, const char* nome){

    No* encontrado;

    if(raiz == NULL){
        return NULL;
    }
    if(strcmp(raiz->dados.nome, nome) == 0){
        return raiz;
    }
    encontrado = buscarNome(raiz->esquerda, nome);
    if(encontrado != NULL){
        return encontrado;
    }
return buscarNome(raiz->direita, nome);
}

void somarNotas(No* raiz, float* soma, int* quantidade){

    if(raiz == NULL){ 
        return;
    }

    *soma += raiz->dados.nota;
    (*quantidade)++;

    somarNotas(raiz->esquerda, soma, quantidade);
    somarNotas(raiz->direita, soma, quantidade);
}

float calcularMediaNotas(No* raiz){

    float soma = 0.0;
    int quantidade = 0;

    somarNotas(raiz, &soma, &quantidade);

    if(quantidade == 0){
        return 0.0;
    }  
return soma / quantidade;
}

void Ordem(No* raiz){

    if(raiz != NULL){

    Ordem(raiz->esquerda);
        printf("Matracula: %d \n Nome: %s \n Nota: %.2f\n",raiz->dados.matricula, raiz->dados.nome, raiz->dados.nota);
    Ordem(raiz->direita);
    }
}

int main(){

    No* raiz = NULL;
    char nomeBusca[] = "Carla";
    No* encontrado;
    float media;

    raiz = inserir(raiz, 102, "Ana", 8.5);
    raiz = inserir(raiz, 101, "Bruno", 7.0);
    raiz = inserir(raiz, 105, "Carla", 9.2);
    raiz = inserir(raiz, 103, "Daniel", 6.4);

    printf("\n");
    printf("Alunos em ordem de matricula:\n");
    printf("\n");
    Ordem(raiz);   

encontrado = buscarNome(raiz, nomeBusca);

    if(encontrado != NULL){

        printf("\nAluno encontrado:\nMatracula: %d \n Nome: %s \n Nota: %.2f\n",encontrado->dados.matricula, encontrado->dados.nome, encontrado->dados.nota);
    }else{
        printf("\nAluno %s nao encontrado.\n", nomeBusca);
    }

media = calcularMediaNotas(raiz);

    printf("\nMedia das notas dos alunos: %.2f\n", media);

return 0;
}