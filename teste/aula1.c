#include <stdio.h>
/*
gcc -g -o main aula1.c
gdb main
*/

int fib(int n){

    if (n < 2){
        return 1;
    }else{
        return fib(n-1) + (n-2);
    }
}

int main(){
    int n = 5;
        printf("%d\n", fib(n));
    return 0;
}