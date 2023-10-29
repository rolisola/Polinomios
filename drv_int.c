#include "polinomio.h"
#include <math.h>

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

    for (int i = 0; i <= polinomio.grau; i++) {
        integral_indefinida.coeficientes[i + 1] = polinomio.coeficientes[i] / (i + 1);
    }
    integral_indefinida.coeficientes[0] = constante;

    return integral_indefinida;
    // POLINOMIO integral;
    // integral.grau = polinomio.grau + 1;
    // integral.coeficientes = (float *)malloc((integral.grau + 1) * sizeof(float));
    // for (int i = 0; i <= polinomio.grau; ++i) {
    //     integral.coeficientes[i + 1] = polinomio.coeficientes[i] / (i + 1);
    // }
    // integral.coeficientes[0] = constante; // Adiciona a constante à integral
    // return integral;
}

float integraldef_polinomio(POLINOMIO polinomio, float limite_inferior, float limite_superior) {
    POLINOMIO integral_definida;
    integral_definida = integrar_polinomio(polinomio, 0); // Calcula a integral indefinida (com constante 0)

    float resultado_inferior = 0, resultado_superior = 0;

    resultado_superior = calcular_polinomio(integral_definida, limite_superior);
    resultado_inferior = calcular_polinomio(integral_definida, limite_inferior);

    float resultado_integral = resultado_superior - resultado_inferior;

    /*printf("\naqui %d\n", integral_definida.grau);
    //printf("aqui %f", integral_definida.coeficientes[0]);
    //printf("\n\n");
    //imprimir_polinomio(integral_definida);
    //printf("\n\n");
    for (int i = 0; i <= integral_definida.grau; i++) {
        //printf("Resultado Superior Old: %d: %f\n", i, resultado_superior);
       //CHECKPOINT resultado_superior += integral_definida.coeficientes[i] * pow(limite_superior,i);
       resultado_superior += integral_definida.coeficientes[i] * pow(limite_superior, i);
        printf("\npotencia i = %f\n",  pow(limite_superior, i));
        //printf("Resultado Superior %d: %f\n", i, resultado_superior);
        printf("Resultado Superior %d: %f = %f (coeficiente) * %f (limite superior) ^ %d (i) \n", i, resultado_superior, integral_definida.coeficientes[i], limite_superior, integral_definida.grau, i);
        printf("\ni = %d\n", i);
    }
    for (int i = 0; i < integral_definida.grau; ++i) {
        printf("Resultado Superior Old: %d: %f\n", i, resultado_superior);
        resultado_superior += integral_definida.coeficientes[i] * pow(limite_superior, integral_definida.grau - i);
        printf("Resultado Superior %d: %f\n", i, resultado_superior);
    }

    for (int i = 0; i < integral_definida.grau; i++) {
        resultado_inferior += integral_definida.coeficientes[i] * pow(limite_inferior, integral_definida.grau - i);
        printf("Resultado Inferior %d: %f\n", i, resultado_inferior);
    }*/

    // liberar_polinomio(&integral_definida);

    return resultado_integral;
}
