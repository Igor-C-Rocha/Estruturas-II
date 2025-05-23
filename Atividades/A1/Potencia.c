#include <stdio.h>

int potencia(int base, int expoente){

    int resultado = 1;

    for(int i = 0; i < expoente; i++){
        resultado = resultado * base;
    }
return resultado;
}

void verifica(int base, int expoente){

    int resultado;

    if(expoente < 0){
        printf("Expoente negativo nao eh permitido.\n");
    }else{
    resultado = potencia(base, expoente);
        printf("%d^%d = %d\n", base, expoente, resultado);
    }
}

int main(){
    
    int base, expoente;

    printf("Digite a base:\n");
    scanf("%d", &base);
    printf("Digite o expoente com um numero positivo ou zero:\n");
    scanf("%d", &expoente);
    verifica(base, expoente);

return 0;
}