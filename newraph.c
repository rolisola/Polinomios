#include <stdio.h>
#include <math.h>
#include "polinomio.h"

float newton_raphson(POLINOMIO polynomial, float x_0, float epsilon, int max_iteration) {
    POLINOMIO derivated_polynomial = polynomial_derivate(polynomial);
    int iteration = 0;
    float x = x_0;
    float error = epsilon + 1;

    while (error > epsilon && iteration < max_iteration) {
        float f = polynomial_result(polynomial, x);
        float f_derivated = polynomial_result(derivated_polynomial, x);

        if (f_derivated == 0) {
            printf("Divisão por 0\n");
            polynomial_free(&derivated_polynomial);
            return x;
        }

        float next_x = x - f / f_derivated;

        error = fabs(next_x - x);
        x = next_x;
        iteration++;
    }

    polynomial_free(&derivated_polynomial);
    
    if (iteration == max_iteration) {
        printf("Raiz não obtida dentro de %d iterações, retornando lixo.\n", iteration);
    }
    if (iteration != max_iteration) {
        printf("Precisão em %d iterações.\n", iteration);
    }

    return x;
}
