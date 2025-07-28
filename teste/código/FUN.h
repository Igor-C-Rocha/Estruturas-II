#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

//declaração do tipo de Tabela
typedef struct Tabela HashTabela;

//declaração do tipo de Node
typedef struct Node Node;

//gera um índice hash para a chave fornecida.
unsigned int hash(const char* key, int capacidade);

//crição do nó e inicialização
Node* criarnode(const char* key, int valor);

//criação da tabela
HashTabela* criarTabela(int capacidade);

//atribui os valores fornecidos
void atribuir(HashTabela* tabela, const char* key, int valor);

//buscar pelo valor solicitado
int buscar(HashTabela* tabela, const char* key, int* valor_encontrado);

//remove um valor da tabela
int remover(HashTabela* tabela, const char* key);

//libera toda a memória alocada pela tabela hash
void liberar(HashTabela* tabela);

//função responsavel por imprimir a tabela
void imprimir(HashTabela* tabela);

//menu do código
void menu();