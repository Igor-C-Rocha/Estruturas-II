#include <stdio.h>
#include <math.h>
#define PI 3.14159265

// Função para converter graus em radianos
double GrausRadianos(double graus){
    return graus * PI / 180.0;
}

// a) Área do triângulo determinado por u e v
double Triangulo(double u, double v, double rad){

    double area_triangulo;
    area_triangulo = 0.5 * u * v * sin(rad);
return area_triangulo;
}

// b) Área do paralelogramo determinado por u e (-v)
double UV(double u, double v, double rad){
    double area_uv;
    area_uv = u * v * sin(rad);
return area_uv;
}

// c) Área do paralelogramo determinado por (u + v) e (u - v)
double Diferenca(double u, double v, double rad){
    double area_soma_diferenca;
    area_soma_diferenca = 2 * u * v * sin(rad);
return area_soma_diferenca;
}

int main(){

double u, v, graus, rad;
double triangulo, uv, soma_diferenca;

// Entrada de dados
    printf("Digite o modulo do vetor u:");
        scanf("%lf", &u);
    printf("Digite o modulo do vetor v:");
        scanf("%lf", &v);
    printf("Digite o angulo entre u e v (em graus):");
        scanf("%lf", &graus);

// Converter para radianos
rad = GrausRadianos(graus);

// Calcular as áreas
triangulo = Triangulo(u, v, rad);
uv = UV(u, v, rad);
soma_diferenca = Diferenca(u, v, rad);

    printf("\nArea do triangulo: %.2lf\n", triangulo);
    printf("Area do paralelogramo (u e -v): %.2lf\n", uv);
    printf("Area do paralelogramo (u+v e u-v): %.2lf\n", soma_diferenca);

return 0;
}