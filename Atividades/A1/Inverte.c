#include <stdio.h>
#include <string.h>

#define MAX 9999

void inverte(char str[]){

    int inicio = 0;
    int fim = strlen(str) - 1;

while(inicio < fim){
    char aux;

    aux = str[inicio];
    str[inicio] = str[fim];
    str[fim] = aux;

    inicio++;
    fim--;
    }
}

int main(){

    char num[MAX];

    printf("Informe os numeros:\n");
    fgets(num, sizeof(num), stdin);
    inverte(num);
    printf("%s", num);

return 0;
}