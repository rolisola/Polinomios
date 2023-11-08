#include <iostream>
#include <cmath>
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
            std::cout << "Divisão por 0" << std::endl;
            polynomial_free(&derivated_polynomial);
            return x;
        }
        float next_x = x - f / f_derivated;
        error = std::fabs(next_x - x);
        x = next_x;
        iteration++;
    }
    polynomial_free(&derivated_polynomial);
    if (iteration == max_iteration) {
        std::cout << "Raiz não obtida dentro de " << iteration << " iterações, retornando lixo." << std::endl;
    }
    if (iteration != max_iteration) {
        std::cout << "Precisão em " << iteration << " iterações." << std::endl;
    }
    return x;
}


