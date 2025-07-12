#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CARGA_INICIAL 4
#define FATOR_CARGA 0.75f //f assegura que 0.75 sera tratado como float.

typedef struct Node{

    char* key;
    int valor;
    struct Node* next;

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

    node->key = strdup(key);
    node->valor = valor;
    node->next = NULL;

    return node;
}

HashTabela* criartabela(int capacidade){

    HashTabela* tabela = malloc(sizeof(HashTabela));
    tabela->capacidade = capacidade;
    tabela->size = 0;
    tabela->balde = calloc(capacidade, sizeof(Node*));
    return tabela;
}

void freetabela(HashTabela* tabela){

    for(int i = 0; i < tabela->capacidade; ++i){

        Node* aux = tabela->balde[i];
        while (aux){
            Node* tmp = aux;
            aux = aux->next;
            free(tmp->key);
            free(tmp);
        }
    }
    free(tabela->balde);
    free(tabela);
}

/*Dobra a capacidade da tabela quando o fator de carga é ultrapassado.
Todos os elementos existentes são realocados para suas novas posições.*/
void reajuste(HashTabela* tabela){
    
    int nova_capacidade = tabela->capacidade * 2;
    Node** novo_balde = calloc(nova_capacidade, sizeof(Node*));

    for(int i = 0; i < tabela->capacidade; ++i){
        Node* aux = tabela->balde[i];
        while(aux){
            Node* next = aux->next;
            unsigned int novo_index = hash(aux->key, nova_capacidade);
            aux->next = novo_balde[novo_index];
            novo_balde[novo_index] = aux;
            aux = next;
        }
    }
// Atualiza o balde e a capacidade
    free(tabela->balde);
    tabela->balde = novo_balde;
    tabela->capacidade = nova_capacidade;
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
    aux = aux->next;
    }
// Se não encontrou, insere um novo nó
    Node* novo_node = criarnode(key, valor);
    novo_node->next = tabela->balde[index];
    tabela->balde[index] = novo_node;
    tabela->size++;
}
    
int* get(HashTabela* table, const char* key){

    unsigned int index = hash(key, table->capacidade);
    Node* aux = table->balde[index];

    while(aux){
        if (strcmp(aux->key, key) == 0)
            return &aux->valor;
        aux = aux->next;
    }
    return NULL;
}

void imprimir_tabela(HashTabela* tabela){

    printf("Tabela Hash (Capacidade: %d, Size: %d)\n", tabela->capacidade, tabela->size);

    for(int i = 0; i < tabela->capacidade; ++i){
        Node* aux = tabela->balde[i];
        if(aux != NULL){
            printf("Bucket %d: ", i);
            while(aux){
                printf("(%s: %d) -> ", aux->key, aux->valor);
                aux = aux->next;
            }
            printf("NULL\n");
        }
    }
}

// Função principal
int main(){

    HashTabela* tabela = criartabela(CARGA_INICIAL);

    printf("Antes do reajuste:\n");
    imprimir_tabela(tabela);  // Imprimir a tabela antes do reajuste

    atribuir(tabela, "chave1", 10);
    atribuir(tabela, "chave2", 20);
    atribuir(tabela, "chave3", 30);
    atribuir(tabela, "chave4", 40); // Deve causar resize
    atribuir(tabela, "chave5", 50);

    printf("\nApos o reajuste:\n");
    imprimir_tabela(tabela);  // Imprimir a tabela após o reajuste

    int* val = get(tabela, "chave3");
    if (val) printf("Valor de chave3: %d\n", *val);

    freetabela(tabela);
    return 0;
}