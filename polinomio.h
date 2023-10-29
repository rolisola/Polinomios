#ifndef POLINOMIO_H_INCLUDED
#define POLINOMIO_H_INCLUDED

#include <stdbool.h>
/*
    Nessa implementação utilizamos um único cabeçalho para diversos arquivos de
    implementação.
*/

typedef struct {
    float *coefficients; // ponteiro para alocação dos coeficientes
    int degree;            // grau do polinômio
} POLINOMIO;

/*------------------------------------------------------------------------------
    Funções básicas do struct. Implementado em polinomio.c
------------------------------------------------------------------------------*/

POLINOMIO new_polynomial(int degree);
POLINOMIO new_polynomial_from_file(char *filename);
bool polynomial_is_null(POLINOMIO polynomial);
void polynomial_free(POLINOMIO *polynomial);
float polynomial_result(POLINOMIO polynomial, float x);
void polynomial_print(POLINOMIO polynomial);

/*------------------------------------------------------------------------------
    Soma, subtração e produto. Implementado em somasubprod.c
------------------------------------------------------------------------------*/

POLINOMIO polynomial_sum(POLINOMIO polynomial_1, POLINOMIO polynomial_2);
POLINOMIO polynomial_subtract(POLINOMIO polynomial_1, POLINOMIO polynomial_2);
POLINOMIO polynomial_multiply(POLINOMIO polynomial_1, POLINOMIO polynomial_2);

/*------------------------------------------------------------------------------
    Derivada e integral. Implementado em drv_int.c
------------------------------------------------------------------------------*/

POLINOMIO polynomial_derivate(POLINOMIO polynomial);
POLINOMIO polynomial_integrate(POLINOMIO polynomial, float constant);
float polynomial_definite_integral(POLINOMIO polynomial, float inferior_limit, float upper_limit);

/*------------------------------------------------------------------------------
    Método de Newton-Raphson. Implementado em newraph.c
------------------------------------------------------------------------------*/

float newton_raphson(POLINOMIO polynomial, float x_0, float epsilon, int max_iteration);

#endif // POLINOMIO_H_INCLUDED
