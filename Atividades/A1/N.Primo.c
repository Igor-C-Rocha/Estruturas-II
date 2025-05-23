#include <stdio.h>
#include <stdbool.h>

bool primo(int n){

    if(n <= 1){return false;}  
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){return false;}
    }
return true;
}

int main(){

    int inicio, fim;
    
    printf("informe o numero inicial:\n");
    scanf("%d", &inicio);
    printf("informe o numero final:\n");
    scanf("%d", &fim);

    printf("Numeros primos entre %d e %d:\n", inicio, fim);
    for(int i = inicio; i <= fim; i++){
        if (primo(i)){
            printf("%d ", i);
        }
    }
    printf("\n");
return 0;
}