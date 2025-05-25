#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 999

int palindromo(char str[]){

    int inicio = 0, fim = strlen(str) - 1;

while(inicio < fim){

    while(inicio < fim && !isalpha(str[inicio])) inicio++;
        while(inicio < fim && !isalpha(str[fim])) fim--;
    
if(tolower(str[inicio]) != tolower(str[fim]))
    return 0;
        inicio++;
        fim--;
    }
    return 1; 
}

int main(){

    char palavra[MAX];

    printf("Digite uma palavra ou frase:\n");
        fgets(palavra, sizeof(palavra), stdin);
    palavra[strcspn(palavra, "\n")] = 0;
    
if(palindromo(palavra)){
        printf("e um palindromo\n");
    }else{
        printf("Nao e palindromo\n");
    }
return 0;
}