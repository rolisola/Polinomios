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

POLINOMIO criar_polinomio(int grau);
POLINOMIO criar_polinomio_arquivo(char *nome_arquivo);
bool verificar_polinomio_vazio(POLINOMIO polinomio);
void liberar_polinomio(POLINOMIO *polinomio);
float calcular_polinomio(POLINOMIO polinomio, float x);
void imprimir_polinomio(POLINOMIO polinomio);

/*------------------------------------------------------------------------------
    Soma, subtração e produto. Implementado em somasubprod.c
------------------------------------------------------------------------------*/

POLINOMIO somar_polinomio(POLINOMIO polinomio_1, POLINOMIO polinomio_2);
POLINOMIO subtrair_polinomio(POLINOMIO polinomio_1, POLINOMIO polinomio_2);
POLINOMIO multiplicar_polinomio(POLINOMIO polinomio_1, POLINOMIO polinomio_2);

/*------------------------------------------------------------------------------
    Derivada e integral. Implementado em drv_int.c
------------------------------------------------------------------------------*/

POLINOMIO derivar_polinomio(POLINOMIO polinomio);
POLINOMIO integrar_polinomio(POLINOMIO polinomio, float constante);
float integraldef_polinomio(POLINOMIO polinomio, float limite_inferior, float limite_superior);

/*------------------------------------------------------------------------------
    Método de Newton-Raphson. Implementado em newraph.c
------------------------------------------------------------------------------*/

float newton_raphson(POLINOMIO polinomio, float x_0, float epsilon, int t_max);

#endif // POLINOMIO_H_INCLUDED
