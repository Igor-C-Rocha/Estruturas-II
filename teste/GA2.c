#include <stdio.h>
#include <math.h>

// Questão 49 Capítulo 6 Pagina 145
// Função para calcular a distância de um ponto ao plano
float distancia(float a, float b, float c, float d, float x, float y, float z){

    float numerador = a*x + b*y + c*z + d, denominador = sqrt(a*a + b*b + c*c);
return fabs(numerador)/ denominador;
}
// Função para calcular a projeção ortogonal de P sobre o plano
void ortogonal(float a, float b, float c, float d,float x, float y, float z,float *xp, float *yp, float *zp, float *t){

    *t = -(a*x + b*y + c*z + d) / (a*a + b*b + c*c);
    *xp = x + a * (*t);
    *yp = y + b * (*t);
    *zp = z + c * (*t);
}
// Função para calcular o ponto simétrico de P em relação ao plano
void simetrico(float x, float y, float z,float a, float b, float c, float t,float *xs, float *ys, float *zs){

    *xs = x + 2 * a * t;
    *ys = y + 2 * b * t;
    *zs = z + 2 * c * t;
}

int main(){

float x, y, z, a, b, c, d, xp, yp, zp, xs, ys, zs, t, dist; 

    printf("Informe os valores do ponto P(x y z):\n");
        scanf("%f %f %f", &x, &y, &z);
    printf("Informe os valores do plano (a b c d) da seguinte formula ax + by + cz + d = 0:\n");
        scanf("%f %f %f %f", &a, &b, &c, &d);

    // a) Equações paramétricas da reta perpendicular ao plano
    printf("\nEquacoes parametricas da reta perpendicular ao plano passando por P:\n");
    printf("x = %.1f + %.1ft\n", x, a);
    printf("y = %.1f + %.1ft\n", y, b);
    printf("z = %.1f + %.1ft\n", z, c);

    // b) Projeção ortogonal
ortogonal(a, b, c, d, x, y, z, &xp, &yp, &zp, &t);
    printf("\nProjecao ortogonal de P sobre o plano: (%.1f, %.1f, %.1f)\n", xp, yp, zp);

    // c) Ponto simétrico
simetrico(x, y, z, a, b, c, t, &xs, &ys, &zs);
    printf("\nPonto simetrico de P em relacao ao plano: (%.1f, %.1f, %.1f)\n", xs, ys, zs);

    // d) Distância de P ao plano
dist = distancia(a, b, c, d, x, y, z);
    printf("\nDistancia do ponto P ao plano: %.1f\n", dist);

return 0;
}