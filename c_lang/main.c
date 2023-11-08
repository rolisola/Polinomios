#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include "polinomio.h"

#define MAXC 128

int main() {
    setlocale(LC_ALL, "");
    char filename[MAXC];
    char filename_2[MAXC];
    POLINOMIO poli_1;
    POLINOMIO poli_2;
    POLINOMIO auxiliar;

    // Bloco do primeiro arquivo
    printf("Nome do arquivo do primeiro polinômio:\n");
    scanf("%s", filename);
    poli_1 = new_polynomial_from_file(filename);
    printf("Primeiro polinômio:\n");
    polynomial_print(poli_1);
    auxiliar = polynomial_derivate(poli_1);
    printf("Derivada do primeiro polinômio:\n");
    polynomial_print(auxiliar);
    polynomial_free(&auxiliar);

    // Bloco do segundo arquivo
    printf("Nome do arquivo do segundo polinômio:\n");
    scanf("%s", filename_2);
    poli_2 = new_polynomial_from_file(filename_2);
    printf("Segundo polinômio:\n");
    polynomial_print(poli_2);
    auxiliar = polynomial_derivate(poli_2);
    printf("Derivada do segundo polinômio:\n");
    polynomial_print(auxiliar);
    polynomial_free(&auxiliar);
    if (!polynomial_is_null(auxiliar)) {
        printf("Erro: polinômio não foi liberado!\n");
        exit(1);
    }

    // Bloco da soma
    printf("Soma dos polinômios:\n");
    auxiliar = polynomial_sum(poli_1, poli_2);
    polynomial_print(auxiliar);
    polynomial_free(&auxiliar);
    if (!polynomial_is_null(auxiliar)) {
        printf("Erro: polinômio não foi liberado!\n");
        exit(1);
    }

    // Bloco da subtração
    printf("Subtração dos polinômios:\n");
    auxiliar = polynomial_subtract(poli_1, poli_2);
    polynomial_print(auxiliar);
    polynomial_free(&auxiliar);
    if (!polynomial_is_null(auxiliar)) {
        printf("Erro: polinômio não foi liberado!\n");
        exit(1);
    }

    // Bloco da multiplicação
    printf("Multiplicação dos polinômios:\n");
    auxiliar = polynomial_multiply(poli_1, poli_2);
    polynomial_print(auxiliar);
    polynomial_free(&auxiliar);
    if (!polynomial_is_null(auxiliar)) {
        printf("Erro: polinômio não foi liberado!\n");
        exit(1);
    }

    // Bloco da integral definida
    float inferior_limit, upper_limit;
    printf("Digite os limites inferior e superio de integração: ");
    scanf("%f", &inferior_limit);
    scanf("%f", &upper_limit);
    printf("Valor da integral definida do primeiro polinômio: %f\n", polynomial_definite_integral(poli_1, inferior_limit, upper_limit));
    printf("Valor da integral definida do segundo polinômio: %f\n", polynomial_definite_integral(poli_2, inferior_limit, upper_limit));

    // Bloco de Newton-Raphson
    int max_iteration;
    float x, epsilon;
    printf("Digite os parâmetros para o método de Newton-Raphson:\n");
    printf("Valor inicial de x: ");
    scanf("%f", &x);
    printf("Valor da precisão numérica: ");
    scanf("%f", &epsilon);
    printf("Número máximo de iterações: ");
    do{
        scanf("%d", &max_iteration);
        printf("Número de iterações deve ser maior que 1. Tente novamente!!!\n");

    }while(max_iteration<1);
    printf("Uma raíz do primeiro polinômio é (aproximadamente) %f\n", newton_raphson(poli_1, x, epsilon, max_iteration));
    printf("Uma raíz do segundo polinômio é (aproximadamente) %f\n", newton_raphson(poli_2, x, epsilon, max_iteration));

    // Bloco da limpeza da memória
    polynomial_free(&poli_1);
    if (!polynomial_is_null(poli_1)) {
        printf("Erro: polinômio não foi liberado!\n");
        exit(1);
    }
    polynomial_free(&poli_2);
    if (!polynomial_is_null(poli_2)) {
        printf("Erro: polinômio não foi liberado!\n");
        exit(1);
    }

    return 0;
}
