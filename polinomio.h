#ifndef POLINOMIO_H_INCLUDED
#define POLINOMIO_H_INCLUDED

#include <stdbool.h>
/*
    Nessa implementação utilizamos um único cabeçalho para diversos arquivos de
    implementação.
*/

typedef struct {
    float *coeficientes; // ponteiro para alocação dos coeficientes
    int grau;            // grau do polinômio
} POLINOMIO;

/*------------------------------------------------------------------------------
    Funções básicas do struct. Implementado em polinomio.c
------------------------------------------------------------------------------*/

POLINOMIO new_polinomio(int n);
POLINOMIO polinomio_from_file(char *filename);
bool polinomio_is_null(POLINOMIO polinomio);
void free_polinomio(POLINOMIO *polinomio);
float valor_polinomio(POLINOMIO polinomio, float x);
void print_polinomio(POLINOMIO polinomio);

/*------------------------------------------------------------------------------
    Soma, subtração e produto. Implementado em somasubprod.c
------------------------------------------------------------------------------*/

POLINOMIO soma_polinomio(POLINOMIO p, POLINOMIO q);
POLINOMIO sub_polinomio(POLINOMIO p, POLINOMIO q);
POLINOMIO prod_polinomio(POLINOMIO p, POLINOMIO q);

/*------------------------------------------------------------------------------
    Derivada e integral. Implementado em drv_int.c
------------------------------------------------------------------------------*/

POLINOMIO deriva_polinomio(POLINOMIO p);
POLINOMIO integra_polinomio(POLINOMIO p, float C);
float integraldef_polinomio(POLINOMIO p, float a, float b);

/*------------------------------------------------------------------------------
    Método de Newton-Raphson. Implementado em newraph.c
------------------------------------------------------------------------------*/

float newton_raphson(POLINOMIO polinomio, float x_0, float epsilon, int t_max);

#endif // POLINOMIO_H_INCLUDED
