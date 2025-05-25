#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRODUTOS 999
#define MAX 100

typedef struct produto{

    char nome[MAX];
    int codigo;
    int quantidade;
    float preco;

}Produto;

int existe(Produto produto[], int n, int codigo){

for(int i = 0; i < n; i++){
    if(produto[i].codigo == codigo){
        return 1; 
        }
    }
    return 0;
}

void cadastra(Produto produto[], int * n){

    int aux;

if(*n >= PRODUTOS){
    printf("Limite atingido\n");
return;
}
    printf("\nCadastro do produto %d:\n", *n + 1);
    printf("Nome: ");
        scanf(" %[^\n]", produto[*n].nome);
    printf("\nCadastro do produto %d:\n", *n + 1);
    printf("Codigo: ");
        scanf("%d", &aux);

if(existe(produto, *n, aux)){

    printf("\nproduto ja existe\n");
return;
    }
produto[*n].codigo = aux;

    printf("\nQuantidade: ");
        scanf("%d", &produto[*n].quantidade);
    printf("\nPreco: ");
        scanf("%f", &produto[*n].preco);
(*n)++;
    printf("\nProduto cadastrado\n");
}

void busca(Produto produtos[], int n){

    int codigo;

    printf("\nDigite o codigo do produto deseja: ");
        scanf("%d", &codigo);

for(int i = 0; i < n; i++){
    if(produtos[i].codigo == codigo){

        printf("\nProduto encontrado:\n");
        printf("Nome: %s\n", produtos[i].nome);
        printf("Codigo: %d\n", produtos[i].codigo);
        printf("Quantidade: %d\n", produtos[i].quantidade);
        printf("Preco: R$ %.2f\n", produtos[i].preco);
return;
    }
}
    printf("\nProduto nao encontrado\n");
}

void lista(Produto produtos[], int n){

    printf("\nLista de produtos:\n");

for(int i = 0; i < n; i++){
    printf("Produto %d:\n", i + 1);
    printf("Nome: %s\n", produtos[i].nome);
    printf("Codigo: %d\n", produtos[i].codigo);
    printf("Quantidade: %d\n", produtos[i].quantidade);
    printf("Preco: R$ %.2f\n\n", produtos[i].preco);
    }
}

void menu(void){
    
    Produto produtos[PRODUTOS];
    int n = 0, opcao;

do{
    printf("\n1 Cadastrar produto\n");
    printf("2 Buscar\n");
    printf("3 Listar produtos\n");
    printf("4 Sair\n");
    printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

    switch(opcao){
        case 1:
                cadastra(produtos, &n);
            break;
        case 2:
                busca(produtos, n);
            break;
        case 3:
                lista(produtos, n);
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