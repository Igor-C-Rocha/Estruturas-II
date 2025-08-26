#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include<locale.h>

typedef struct racao Racao;
typedef struct usuario Usuario;

extern const char arq_racoes[];
extern const char arq_usuarios[];

extern Usuario* usuarios;
extern Racao* racoes;

void inserir_racao(Racao** lista, Racao* novo);
void quicksort(Racao** lista);
void listar_racoes(Racao* lista);
void buscar_racao();
void cadastrar_racao();
void salvar_racoes();
void carregar_racoes();

void inserir_usuario(Usuario** lista, Usuario* novo);
int email_valido(char email[]);
void cadastrar_usuario();
int fazer_login();
void salvar_usuarios();
void carregar_usuarios();

void inicializar_sistema();
void boas_vindas();
void menu_principal();
