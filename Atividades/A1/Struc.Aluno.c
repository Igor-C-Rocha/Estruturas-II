#include <stdio.h>
#include <stdlib.h>

#define NOME 999

typedef struct aluno{

    char nome[NOME];
    int matricula;
    float media;

}Aluno;

Aluno * cadastro(int n){

Aluno *aluno = (Aluno*)malloc(n * sizeof(Aluno));
    if (aluno == NULL){
        printf("Erro\n");
    exit(1);
    }

for(int i = 0; i < n; i++){

    printf("\nAluno %d:\n", i + 1);
    printf("Nome: ");
        scanf(" %[^\n]", aluno[i].nome);
    printf("Matricula: ");
        scanf("%d", &aluno[i].matricula);
    printf("Media: ");
        scanf("%f", &aluno[i].media);
    }

return aluno;
}

void aprovado(Aluno * aluno, int n){

for(int i = 0; i < n; i++){
    if(aluno[i].media >= 7.0){
        printf("Nome:%s\n Matricula:%d\n Media:%.2f\n",aluno[i].nome, aluno[i].matricula, aluno[i].media);
        }
    }
}

int main(){

    Aluno * aluno;
    int n;

    printf("Quantos alunos registrar?\n");
        scanf("%d", &n);
    aluno = cadastro(n);
    printf("alunos aprovados:\n");
    aprovado(aluno, n);
    free(aluno);

return 0;
}