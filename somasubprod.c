#include "polinomio.h"
#include <stdlib.h>

POLINOMIO somar_polinomio(POLINOMIO polinomio_1, POLINOMIO polinomio_2) {
    int grau_resultante;

    if (polinomio_1.grau > polinomio_2.grau) {
        grau_resultante = polinomio_1.grau;
    } else {
        grau_resultante = polinomio_2.grau;
    }
    // grau_resultante = (polinomio_1.grau > polinomio_2.grau) ? polinomio_1.grau : polinomio_2.grau;

    POLINOMIO polinomio_resultante = criar_polinomio(grau_resultante);

    for (int i = 0; i <= grau_resultante; i++) {

        polinomio_resultante.coeficientes[i] = 0;

        if (i <= polinomio_1.grau) {
            polinomio_resultante.coeficientes[i] += polinomio_1.coeficientes[i];
        }
        if (i <= polinomio_2.grau) {
            polinomio_resultante.coeficientes[i] += polinomio_2.coeficientes[i];
        }
    }

    return polinomio_resultante;
}

POLINOMIO subtrair_polinomio(POLINOMIO polinomio_1, POLINOMIO polinomio_2) {
    int grau_resultante;

    if (polinomio_1.grau > polinomio_2.grau) {
        grau_resultante = polinomio_1.grau;
    } else {
        grau_resultante = polinomio_2.grau;
    }
    // grau_resultante = (polinomio_1.grau > polinomio_2.grau) ? polinomio_1.grau : polinomio_2.grau;

    POLINOMIO polinomio_resultante = criar_polinomio(grau_resultante);
    if(polinomio_resultante.coeficientes==NULL){
        exit(1);
    }
    for (int i = 0; i <= grau_resultante; i++) {

        polinomio_resultante.coeficientes[i] = 0;

        if (i <= polinomio_1.grau) {
            polinomio_resultante.coeficientes[i] += polinomio_1.coeficientes[i];
        }
        if (i <= polinomio_2.grau) {
            polinomio_resultante.coeficientes[i] -= polinomio_2.coeficientes[i];
        }
    }

    return polinomio_resultante;
}

POLINOMIO multiplicar_polinomio(POLINOMIO polinomio_1, POLINOMIO polinomio_2) {
    int grau_resultante;
    grau_resultante = polinomio_1.grau + polinomio_2.grau;

    POLINOMIO polinomio_resultante = criar_polinomio(grau_resultante);

    for (int i = 0; i <= polinomio_resultante.grau; i++) {
        polinomio_resultante.coeficientes[i] = 0;
        for (int j = 0; j <= polinomio_1.grau; j++) {
            if (i - j >= 0 && i - j <= polinomio_2.grau) {
                polinomio_resultante.coeficientes[i] += polinomio_1.coeficientes[j] * polinomio_2.coeficientes[i - j];
            }
        }
    }

    return polinomio_resultante;
}
