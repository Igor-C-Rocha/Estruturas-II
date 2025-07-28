#include "FUN.h"

#define N 999
#define CARGA_INICIAL 10
#define FATOR_CARGA 0.70f //f assegura que 0.75 sera tratado como float.

typedef struct Node{

    char* key;
    int valor;
    struct Node* prox;

}Node;

typedef struct Tabela{

    Node** balde;
    int capacidade;
    int size;

}HashTabela;

unsigned int hash(const char* key, int capacidade){
//Hash com 5381 dá uma boa distribuição de valores usando strings como chaves.
    unsigned long hash = 5381;
    int c;

    while ((c = *key++))
        hash = ((hash << 5) + hash) + c;
    return hash % capacidade;
}

Node* criarnode(const char* key, int valor){
Node* node = malloc(sizeof(Node));

    if(node == NULL){
        printf("Erro ao criar\n");
        exit(1);
    }
    node->key = strdup(key);
    node->valor = valor;
    node->prox = NULL;

    return node;
}

HashTabela* criarTabela(int capacidade){
HashTabela* tabela = malloc(sizeof(HashTabela));

    tabela->capacidade = capacidade;
    tabela->size = 0;
    tabela->balde = calloc(capacidade, sizeof(Node*));

    return tabela;
}

void reajuste(HashTabela* tabela){

int novaCapacidade = tabela->capacidade * 2;
Node** novoBalde = calloc(novaCapacidade, sizeof(Node*));

    for(int i = 0; i < tabela->capacidade; i++){
Node* atual = tabela->balde[i];
        while(atual){
        Node* proximo = atual->prox;
            // Re-hash das chaves com a nova capacidade
            unsigned int novoIndex = hash(atual->key, novaCapacidade);
            atual->prox = novoBalde[novoIndex];
            novoBalde[novoIndex] = atual;
        atual = proximo;
        }
    }
    free(tabela->balde);
    tabela->balde = novoBalde;
    tabela->capacidade = novaCapacidade;
}

void atribuir(HashTabela* tabela, const char* key, int valor){

    if((float)tabela->size / tabela->capacidade > FATOR_CARGA){
        reajuste(tabela);
    }

unsigned int index = hash(key, tabela->capacidade);
Node* aux = tabela->balde[index];

    while(aux){
        if(strcmp(aux->key, key) == 0){
            aux->valor = valor;
            return;
        }
        aux = aux->prox; 
    }
Node* novo_node = criarnode(key, valor);
    novo_node->prox = tabela->balde[index];  
    tabela->balde[index] = novo_node;
    tabela->size++;
}

int buscar(HashTabela* tabela, const char* key, int* valor_encontrado){

unsigned int index = hash(key, tabela->capacidade);
Node* aux = tabela->balde[index];
    while(aux){
        if(strcmp(aux->key, key) == 0){
            *valor_encontrado = aux->valor;
            return 1; 
        }
        aux = aux->prox;
    }
    return 0;
}

int remover(HashTabela* tabela, const char* key){

unsigned int index = hash(key, tabela->capacidade);
Node* atual = tabela->balde[index];
Node* anterior = NULL;

    while(atual){
        if(strcmp(atual->key, key) == 0){
            if(anterior){
                anterior->prox = atual->prox;
            }else{
                tabela->balde[index] = atual->prox;
            }
    free(atual->key);
    free(atual);
    tabela->size--;
return 1;
        }
        anterior = atual;
        atual = atual->prox;
    }
    return 0;
}

void liberar(HashTabela* tabela){

    for(int i = 0; i < tabela->capacidade; i++){
Node* atual = tabela->balde[i];
        while(atual){
            Node* temp = atual;
            atual = atual->prox;
            free(temp->key);
            free(temp);
        }
    }
    free(tabela->balde);
    free(tabela);
}

void imprimir(HashTabela* tabela){

    for(int i = 0; i < tabela->capacidade; i++){
        printf("Balde %d: ", i);
Node* atual = tabela->balde[i];
        while(atual){
            printf("(%s, %d) -> ", atual->key, atual->valor);
            atual = atual->prox;
        }
        printf("NULL\n");
    }
}

void menu(){

HashTabela* tabela = criarTabela(CARGA_INICIAL);

    char key[N];
    int valor, valor_encontrado;
    int opcao;

while(1){

    printf("\nEscolha uma opcao:\n");
    printf("1 - Atribuir\n");
    printf("2 - Buscar\n");
    printf("3 - Remover\n");
    printf("4 - Imprimir tabela\n");
    printf("5 - Sair\n");
    printf("Opcao: ");
        
        if(scanf("%d", &opcao) != 1){
            while(getchar() != '\n'){}  // limpar o buffer
                printf("Tente novamente.\n");
        continue;
        }
        
    switch(opcao){
            case 1:
                // Atribuir chave-valor
            printf("Digite a chave: ");
                scanf("%s", key);
            printf("Digite o valor: ");
                scanf("%d", &valor);
        atribuir(tabela, key, valor);
            printf("Chave '%s' com valor '%d' inserida.\n", key, valor);
            break;
                
            case 2:
                // Buscar chave
            printf("Digite a chave para buscar: ");
                scanf("%s", key);
                if(buscar(tabela, key, &valor_encontrado)){
                    printf("Valor encontrado para a chave '%s': %d\n", key, valor_encontrado);
                }else{
                    printf("Chave '%s' nao encontrada.\n", key);
                }
            break;

            case 3:
                // Remover chave-valor
            printf("Digite a chave para remover: ");
                scanf("%s", key);
                if(remover(tabela, key)){
                    printf("Chave '%s' removida com sucesso.\n", key);
                }else{
                    printf("Chave '%s' nao encontrada.\n", key);
                }
            break;

            case 4:
                // Imprimir a tabela
            printf("\nTabela Hash atual:\n");
                imprimir(tabela);
                break;
                
            case 5:
                // Liberar memória e sair
        liberar(tabela);
            printf("Memoria liberada. Programa encerrado.\n");
                return;
            default:
            printf("Opcao invalida.\n");
        }
    }
    return;
}

int main(){

    menu();

return 0;
}