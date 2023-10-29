#include <stdio.h>
#include <math.h>
#include "polinomio.h"

float newton_raphson(POLINOMIO polinomio, float x_0, float epsilon, int iteracao_maxima) {
    POLINOMIO derivada = derivar_polinomio(polinomio);
    int iteracao = 0;
    float x = x_0;
    float erro = epsilon + 1;

    while (erro > epsilon && iteracao < iteracao_maxima) {
        float f = calcular_polinomio(polinomio, x);
        float f_derivada = calcular_polinomio(derivada, x);

        if (f_derivada == 0) {
            printf("Divisão por 0\n");
            liberar_polinomio(&derivada);
            return x;
        }

        float proximo_x = x - f / f_derivada;

        erro = fabs(proximo_x - x);
        x = proximo_x;
        iteracao++;
    }

    liberar_polinomio(&derivada);
    if(iteracao == iteracao_maxima){
        printf("Raiz não obtida dentro de %d iterações, retornando lixo", iteracao);
    }
    if(iteracao != iteracao_maxima){
        printf("Precisão em %d iterações.\n", iteracao);
    }

    return x;
}
