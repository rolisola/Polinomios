#include <math.h>
#include "polinomio.h"

// Calcula derivada do polinômio
POLINOMIO polynomial_derivate(POLINOMIO polynomial) {
    POLINOMIO derivated_polynomial = new_polynomial(polynomial.degree - 1);
    
    derivated_polynomial.degree = polynomial.degree - 1;

    for (int i = 0; i <= derivated_polynomial.degree; ++i) {
        derivated_polynomial.coefficients[i] = polynomial.coefficients[i + 1] * (i + 1);
    }
    return derivated_polynomial;
}

// Calcula integral indefinida do polinômio pela constante fornecida
POLINOMIO polynomial_integrate(POLINOMIO polynomial, float constant) {
    POLINOMIO indefinite_integral = new_polynomial(polynomial.degree + 1);

    for (int i = 0; i <= polynomial.degree; i++) {
        indefinite_integral.coefficients[i + 1] = polynomial.coefficients[i] / (i + 1);
    }
    indefinite_integral.coefficients[0] = constant;

    return indefinite_integral;
}

// Calcula integral definida do polinômio nos limites fornecidos
float polynomial_definite_integral(POLINOMIO polynomial, float inferior_limit, float upper_limit) {
    POLINOMIO definite_integral = polynomial_integrate(polynomial, 0); // Calcula a integral indefinida (com constante 0)

    float infferior_result = 0, upper_result = 0;

    upper_result = polynomial_result(definite_integral, upper_limit);
    infferior_result = polynomial_result(definite_integral, inferior_limit);

    float integral_result = upper_result - infferior_result;

    return integral_result;
}
