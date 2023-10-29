#include <math.h>
#include "polinomio.h"

POLINOMIO derivar_polinomio(POLINOMIO polinomio) {
    POLINOMIO polinomio_derivado = criar_polinomio(polinomio.grau - 1);
    polinomio_derivado.grau = polinomio.grau - 1;
    for (int i = 0; i <= polinomio_derivado.grau; ++i) {
        polinomio_derivado.coeficientes[i] = polinomio.coeficientes[i + 1] * (i + 1);
    }
    return polinomio_derivado;
}

POLINOMIO integrar_polinomio(POLINOMIO polinomio, float constante) {
    POLINOMIO integral_indefinida;
    integral_indefinida = criar_polinomio(polinomio.grau + 1);

    for (int i = 1; i <= polinomio.grau; i++) {
        integral_indefinida.coeficientes[i] = polinomio.coeficientes[i - 1] / (i);
    }
    integral_indefinida.coeficientes[0] = constante;

    return integral_indefinida;
}

float integraldef_polinomio(POLINOMIO polinomio, float limite_inferior, float limite_superior) {
    POLINOMIO integral_definida;
    integral_definida = integrar_polinomio(polinomio, 0); // Calcula a integral indefinida (com constante 0)

    float resultado_inferior = 0, resultado_superior = 0;

    for (int i = 0; i <= integral_definida.grau; ++i) {
        resultado_superior += integral_definida.coeficientes[i] * pow(limite_superior, integral_definida.grau - i);
    }

    for (int i = 0; i <= integral_definida.grau; ++i) {
        resultado_inferior += integral_definida.coeficientes[i] * pow(limite_inferior, integral_definida.grau - i);
    }

    float resultado_integral = resultado_superior - resultado_inferior;

    liberar_polinomio(&integral_definida);

    return resultado_integral;
}
