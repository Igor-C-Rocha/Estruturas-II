#include <stdio.h>

void frequencia(int num[]){

    int Contado[10] = {0};

    printf("\nFrequencia do numeros:\n");
    for (int i = 0; i < 10; i++){
        if (Contado[i]){
            continue;
        }
    int cont = 1;
        for(int j = i + 1; j < 10; j++){
            if(num[i] == num[j]){
                cont++;
                Contado[j] = 1; 
            }
        }
    printf("%d apareceu %d vez(es)\n", num[i], cont);
    }
}

int main(){

    int num[10];
    
    printf("Digite dez numeros inteiros:\n");
    for(int i = 0; i < 10; i++){
        scanf("%d", &num[i]);
    }
    frequencia(num);

return 0;
}