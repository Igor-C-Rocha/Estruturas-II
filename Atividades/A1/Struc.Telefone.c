#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CONTATO 999
#define MAX 999

typedef struct contato{

    char nome[MAX];
    char telefone[10];

}Contato;

int existe(Contato contato[], int n, const char *nome){

for(int i = 0; i < n; i++){
    if(strcmp(contato[i].nome, nome) == 0){
        return 1;
        }
    }
    return 0;
}

void adiciona(Contato contato[], int *n){

    char aux[MAX];

if(*n >= CONTATO){

    printf("sem espaco\n");    
return;
    }
    printf("\nCadastra contato %d:\n", *n + 1);
    printf("Nome: ");
        scanf(" %[^\n]", aux);
if(existe(contato, *n, aux)){

    printf("\nnome existente.\n");
return;
    }
        strcpy(contato[*n].nome, aux);
    printf("Telefone: ");
        scanf(" %[^\n]", contato[*n].telefone);
    (*n)++;
    printf("adicionado\n");
}

void buscar(Contato contato[], int n){

    char Busca[MAX];
    int encontrado = 0;

    printf("\ninforme o nome q deseja buscar:");
        scanf(" %[^\n]", Busca);

for(int i = 0; i < n; i++){
    if(strcmp(contato[i].nome, Busca) == 0){
        
        printf("\nencontrado:\n");
        printf("Nome: %s\n", contato[i].nome);
        printf("Telefone: %s\n", contato[i].telefone);
        encontrado = 1;
    break;
        }
    }
if(!encontrado){

    printf("\nNao encontrado\n");
    }
}

void lista(Contato contato[], int n){

    printf("\nLista de contatos:\n");

for(int i = 0; i < n; i++){

        printf("Contato %d:\n", i + 1);
        printf("Nome: %s\n", contato[i].nome);
        printf("Telefone: %s\n", contato[i].telefone);
    }
}

void menu(){

    Contato contatos[CONTATO];
    int n = 0;
    int opcao;

do{
    printf("\n1 Adicionar contato\n");
    printf("2 Buscar contato por nome\n");
    printf("3 Listar todos os contatos\n");
    printf("4 Sair\n");
    printf("informe sua opcao: ");
        scanf("%d", &opcao);

    switch(opcao){
        case 1:
                adiciona(contatos, &n);
            break;
        case 2:
                buscar(contatos, n);
            break;
        case 3:
                lista(contatos, n);
            break;
        case 4:
                printf("fechando\n");
                exit(0);
            break;
    default:
                printf("errado\n");
        }
    } while(opcao != 0);
}

int main(){

    menu();

return 0;
}