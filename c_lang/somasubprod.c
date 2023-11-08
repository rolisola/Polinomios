#include <stdlib.h>
#include "polinomio.h"

// Soma polinômios
POLINOMIO polynomial_sum(POLINOMIO polynomial_1, POLINOMIO polynomial_2) {
    int result_degree;

    if (polynomial_1.degree > polynomial_2.degree) {
        result_degree = polynomial_1.degree;
    } else {
        result_degree = polynomial_2.degree;
    }
    // result_degree = (polynomial_1.degree > polynomial_2.degree) ? polynomial_1.degree : polynomial_2.degree;

    POLINOMIO polynomial_result = new_polynomial(result_degree);

    for (int i = 0; i <= result_degree; i++) {

        polynomial_result.coefficients[i] = 0;

        if (i <= polynomial_1.degree) {
            polynomial_result.coefficients[i] += polynomial_1.coefficients[i];
        }
        if (i <= polynomial_2.degree) {
            polynomial_result.coefficients[i] += polynomial_2.coefficients[i];
        }
    }

    return polynomial_result;
}

// Subtrai polinômios
POLINOMIO polynomial_subtract(POLINOMIO polynomial_1, POLINOMIO polynomial_2) {
    int result_degree;

    if (polynomial_1.degree > polynomial_2.degree) {
        result_degree = polynomial_1.degree;
    } else {
        result_degree = polynomial_2.degree;
    }
    // result_degree = (polynomial_1.degree > polynomial_2.degree) ? polynomial_1.degree : polynomial_2.degree;

    POLINOMIO polynomial_result = new_polynomial(result_degree);
    if (polynomial_result.coefficients == NULL) {
        exit(1);
    }
    for (int i = 0; i <= result_degree; i++) {

        polynomial_result.coefficients[i] = 0;

        if (i <= polynomial_1.degree) {
            polynomial_result.coefficients[i] += polynomial_1.coefficients[i];
        }
        if (i <= polynomial_2.degree) {
            polynomial_result.coefficients[i] -= polynomial_2.coefficients[i];
        }
    }

    return polynomial_result;
}

// Multiplica polinômios
POLINOMIO polynomial_multiply(POLINOMIO polynomial_1, POLINOMIO polynomial_2) {
    int result_degree;
    result_degree = polynomial_1.degree + polynomial_2.degree;

    POLINOMIO polynomial_result = new_polynomial(result_degree);

    for (int i = 0; i <= polynomial_result.degree; i++) {
        polynomial_result.coefficients[i] = 0;
        for (int j = 0; j <= polynomial_1.degree; j++) {
            if (i - j >= 0 && i - j <= polynomial_2.degree) {
                polynomial_result.coefficients[i] += polynomial_1.coefficients[j] * polynomial_2.coefficients[i - j];
            }
        }
    }

    return polynomial_result;
}
