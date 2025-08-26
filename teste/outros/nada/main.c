#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include "dis.h"

extern const char arq_racoes[];
extern const char arq_usuarios[];

extern Usuario* usuarios;
extern Racao* racoes;

typedef struct racao {
    char sabor[50];
    char marca[50];
    char animal[50];
    int tamanho;
    float preco;
    struct racao *prox;
} Racao;

typedef struct usuario {
    char email[50];
    char usuario[50];
    char senha[50];
    struct usuario *prox;
} Usuario;
/*
const char arq_racoes[] = "racoes.txt";
const char arq_usuarios[] = "usuarios.txt";
Usuario* usuarios = NULL;
Racao* racoes = NULL;
Racao* criar_racao(char sabor[], char marca[], char animal[], int tamanho, float preco);
void inserir_racao(Racao** lista, Racao* novo);
void quicksort(Racao** lista);
Racao* partition(Racao* head, Racao* end, Racao** newHead, Racao** newEnd);
Racao* quicksort_rec(Racao* head, Racao* end);
Racao* buscar_racao_ordenada(Racao* lista, char sabor[]);
Usuario* criar_usuario(char email[], char usuario[], char senha[]);
void inserir_usuario(Usuario** lista, Usuario* novo);
Usuario* buscar_usuario(Usuario* lista, char usuario[]);
int email_valido(char email[]);
void cadastrar_usuario();
int fazer_login();
void inicializar_sistema();
void boas_vindas();
void menu_principal();
void listar_racoes(Racao* lista);
void buscar_racao();
void cadastrar_racao();
void salvar_usuarios();
void salvar_racoes();
*/
Racao* criar_racao(char sabor[], char marca[], char animal[], int tamanho, float preco) {
    Racao* nova = (Racao*)malloc(sizeof(Racao));
    if (nova) {
        strcpy(nova->sabor, sabor);
        strcpy(nova->marca, marca);
        strcpy(nova->animal, animal);
        nova->tamanho = tamanho;
        nova->preco = preco;
        nova->prox = NULL;
    }
    return nova;
}

void inserir_racao(Racao** lista, Racao* novo) {
    if (*lista == NULL) {
        *lista = novo;
    } else {
        Racao* atual = *lista;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}

Racao* partition(Racao* head, Racao* end, Racao** newHead, Racao** newEnd) {
    Racao* pivot = end;
    Racao *prev = NULL, *cur = head, *tail = pivot;
    
    while (cur != pivot) {
        if (strcmp(cur->sabor, pivot->sabor) < 0) {
            if ((*newHead) == NULL)
                (*newHead) = cur;
            prev = cur;
            cur = cur->prox;
        } else {
            if (prev)
                prev->prox = cur->prox;
            Racao* tmp = cur->prox;
            cur->prox = NULL;
            tail->prox = cur;
            tail = cur;
            cur = tmp;
        }
    }
    
    if ((*newHead) == NULL)
        (*newHead) = pivot;
        
    (*newEnd) = tail;
    return pivot;
}

Racao* quicksort_rec(Racao* head, Racao* end) {
    if (!head || head == end)
        return head;
        
    Racao *newHead = NULL, *newEnd = NULL;
    Racao* pivot = partition(head, end, &newHead, &newEnd);
    
    if (newHead != pivot) {
        Racao* tmp = newHead;
        while (tmp->prox != pivot)
            tmp = tmp->prox;
        tmp->prox = NULL;
        
        newHead = quicksort_rec(newHead, tmp);
        
        tmp = newHead;
        while (tmp && tmp->prox)
            tmp = tmp->prox;
        if (tmp) tmp->prox = pivot;
    }
    
    pivot->prox = quicksort_rec(pivot->prox, newEnd);
    return newHead;
}

void quicksort(Racao** lista) {
    if (*lista == NULL) return;
    Racao* tail = *lista;
    while (tail->prox != NULL)
        tail = tail->prox;
        
    *lista = quicksort_rec(*lista, tail);
}

Racao* buscar_racao_ordenada(Racao* lista, char sabor[]) {
    Racao* atual = lista;
    while (atual != NULL) {
        int cmp = strcmp(atual->sabor, sabor);
        if (cmp == 0) {
            return atual;
        } else if (cmp > 0) {
            break;
        }
        atual = atual->prox;
    }
    return NULL;
}

Usuario* criar_usuario(char email[], char usuario[], char senha[]) {
    Usuario* novo = (Usuario*)malloc(sizeof(Usuario));
    if (novo) {
        strcpy(novo->email, email);
        strcpy(novo->usuario, usuario);
        strcpy(novo->senha, senha);
        novo->prox = NULL;
    }
    return novo;
}

void inserir_usuario(Usuario** lista, Usuario* novo) {
    if (*lista == NULL) {
        *lista = novo;
    } else {
        Usuario* atual = *lista;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}

Usuario* buscar_usuario(Usuario* lista, char usuario[]) {
    Usuario* atual = lista;
    while (atual != NULL) {
        if (strcmp(atual->usuario, usuario) == 0) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
}

int email_valido(char email[]) {
    char *at = strchr(email, '@');
    if (at == NULL) return 0;
    char *dot = strchr(at, '.');
    if (dot == NULL || dot == at+1) return 0;
    if (strlen(dot) < 2) return 0;
    return 1;
}

void cadastrar_usuario() {
    char email[50], usuario[50], senha[50];
    printf("Email: ");
    scanf("%49s", email);
    if (!email_valido(email)) {
        printf("Email inv?lido.\n");
        return;
    }
    printf("Usu?rio: ");
    scanf("%49s", usuario);
    printf("Senha: ");
    scanf("%49s", senha);

    if (buscar_usuario(usuarios, usuario) != NULL) {
        printf("Usu?rio j? existe.\n");
        return;
    }

    Usuario* novo = criar_usuario(email, usuario, senha);
    inserir_usuario(&usuarios, novo);
    printf("Usu?rio cadastrado com sucesso!\n");
}

int fazer_login() {
    char usuario[50], senha[50];
    printf("Usu?rio: ");
    scanf("%49s", usuario);
    printf("Senha: ");
    scanf("%49s", senha);

    Usuario* user = buscar_usuario(usuarios, usuario);
    if (user == NULL) {
        printf("Usu?rio n?o encontrado.\n");
        return 0;
    }

    if (strcmp(user->senha, senha) == 0) {
        return 1;
    } else {
        printf("Senha incorreta.\n");
        return 0;
    }
}

void carregar_usuarios() {
    FILE* arq = fopen(arq_usuarios, "r");
    if (arq == NULL) return;

    char email[50], usuario[50], senha[50];
    while (fscanf(arq, "%49s %49s %49s", email, usuario, senha) == 3) {
        Usuario* novo = criar_usuario(email, usuario, senha);
        inserir_usuario(&usuarios, novo);
    }
    fclose(arq);
}

void carregar_racoes() {
    FILE* arq = fopen(arq_racoes, "r");
    if (arq == NULL) return;

    char sabor[50], marca[50], animal[50];
    int tamanho;
    float preco;
    while (fscanf(arq, "%49s %49s %49s %d %f", sabor, marca, animal, &tamanho, &preco) == 5) {
        Racao* nova = criar_racao(sabor, marca, animal, tamanho, preco);
        inserir_racao(&racoes, nova);
    }
    fclose(arq);
}

void inicializar_sistema() {
    carregar_usuarios();
    carregar_racoes();
    if (racoes != NULL) {
        quicksort(&racoes);
    }
}

void boas_vindas() {
    printf("\nBem-vindo ao sistema de gerenciamento de ra??es!\n");
}

void listar_racoes(Racao* lista) {
    if (racoes == NULL) {
        printf("Nenhuma ra??o cadastrada.\n");
        return;
    }
    Racao* atual = racoes;
    while (atual != NULL) {
        printf("Sabor: %s, Marca: %s, Animal: %s, Tamanho: %dg, Pre?o: R$%.2f\n", 
               atual->sabor, atual->marca, atual->animal, atual->tamanho, atual->preco);
        atual = atual->prox;
    }
}

void buscar_racao() {
    char sabor[50];
    printf("Digite o sabor: ");
    scanf("%49s", sabor);
    Racao* encontrada = buscar_racao_ordenada(racoes, sabor);
    if (encontrada) {
        printf("Ra??o encontrada:\n");
        printf("Sabor: %s, Marca: %s, Animal: %s, Tamanho: %dg, Pre?o: R$%.2f\n", 
               encontrada->sabor, encontrada->marca, encontrada->animal, 
               encontrada->tamanho, encontrada->preco);
    } else {
        printf("Ra??o n?o encontrada.\n");
    }
}

void cadastrar_racao() {
    char sabor[50], marca[50], animal[50];
    int tamanho;
    float preco;

    printf("Sabor: ");
    scanf("%49s", sabor);
    printf("Marca: ");
    scanf("%49s", marca);
    printf("Animal: ");
    scanf("%49s", animal);
    printf("Tamanho (gramas): ");
    scanf("%d", &tamanho);
    printf("Pre?o: R$");
    scanf("%f", &preco);

    Racao* nova = criar_racao(sabor, marca, animal, tamanho, preco);
    inserir_racao(&racoes, nova);
    quicksort(&racoes);
    printf("Ra??o cadastrada com sucesso!\n");
}

void salvar_usuarios() {
    FILE* arq = fopen(arq_usuarios, "w");
    if (arq == NULL) {
        printf("Erro ao salvar usu?rios!\n");
        return;
    }

    Usuario* atual = usuarios;
    while (atual != NULL) {
        fprintf(arq, "%s %s %s\n", atual->email, atual->usuario, atual->senha);
        atual = atual->prox;
    }
    fclose(arq);
}

void salvar_racoes() {
    FILE* arq = fopen(arq_racoes, "w");
    if (arq == NULL) {
        printf("Erro ao salvar ra??es!\n");
        return;
    }

    Racao* atual = racoes;
    while (atual != NULL) {
        fprintf(arq, "%s %s %s %d %.2f\n", 
                atual->sabor, atual->marca, atual->animal, 
                atual->tamanho, atual->preco);
        atual = atual->prox;
    }
    fclose(arq);
}

void menu_principal() {
    int opcao;
    do {
        printf("\n========== Gerenciamento da Distribuidora de Ra??es ==========\n");
        printf("1. Listar todas as ra??es\n");
        printf("2. Buscar ra??o por sabor\n");
        printf("3. Cadastrar nova ra??o\n");
        printf("4. Sair\n");
        printf("Escolha uma op??o: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                listar_racoes();
                break;
            case 2:
                buscar_racao();
                break;
            case 3:
                cadastrar_racao();
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Op??o inv?lida!\n");
        }
    } while (opcao != 4);
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    inicializar_sistema();

    int autenticado = 0;
    while (!autenticado) {
        printf("\n========== Distribuidora de Ra??es ==========\n");
        printf("1. Fazer login\n");
        printf("2. Cadastrar novo usu?rio\n");
        printf("3. Sair\n");
        printf("Escolha uma op??o: ");
        
        int opcao;
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                autenticado = fazer_login();
                break;
            case 2:
                cadastrar_usuario();
                break;
            case 3:
                salvar_usuarios();
                salvar_racoes();
                exit(0);
            default:
                printf("Op??o inv?lida!\n");
        }
    }

    boas_vindas();
    menu_principal();

    salvar_usuarios();
    salvar_racoes();

    return 0;
}