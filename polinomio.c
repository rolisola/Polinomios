#include "polinomio.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

POLINOMIO new_polinomio(int grau) {
    POLINOMIO polinomio;

    polinomio.grau = grau;
    polinomio.coeficientes = (float *)malloc((grau + 1) * sizeof(float));
    /*for(int i=0;i<=grau;i++){
        polinomio.coeficientes[i]=i;
        printf("%f\n",polinomio.coeficientes[i]);
    }
    printf("grau%d\n",grau);
    int len = sizeof(polinomio.coeficientes)/sizeof(polinomio.coeficientes[0]);
    printf("sizeof%d\n", sizeof(polinomio.coeficientes));
    printf("size%f\n", len);*/
    return polinomio;
}

POLINOMIO polinomio_from_file(char *filename) {
    FILE *file_pointer = NULL;
    float coef = 0;
    int grau = -1;// inicializa em -1 para contar o x^0 na determinação do grau do polinômio

    file_pointer = fopen(filename, "r");

    if (file_pointer == NULL) {
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }

    while (!feof(file_pointer)) {
        if (fscanf(file_pointer, "%f", &coef) == 1) {
            grau++;
        } else {
            printf("Erro ao ler valor!\n");
            exit(1);
        }
    }

    POLINOMIO polinomio = new_polinomio(grau);

    fseek(file_pointer, 0, SEEK_SET);

    for (int i = 0; i <= polinomio.grau; i++) {
        // printf("yyyyyyyyyyy\n");
        if (fscanf(file_pointer, "%f", &polinomio.coeficientes[i]) == 1) {
            // printf("i: %d\n",i);
            // printf("coef: %f\n", polinomio.coeficientes[i]);
        } else {
            printf("Erro ao atribuir valor!\n");
            exit(1);
        }
    }

    /*if (polinomio_is_null(polinomio)) {
        printf("Polinomio esta vazio!\n");
        exit(1);
    }else{
        printf("Polinomio nao esta vazio!\n");
    }*/

    /*
    for(int i = 0; i < grau; i++){
        printf("%f\n", polinomio.coeficientes[i]);
    }*/
    /*while(!foef(file_pointer)){
        if(fscanf(file_pointer, "%f", polinomio.coeficientes[i]) == 1){
        }else{
            printf("Erro ao ler valor!\n");
            exit(1);
        }
    }*/

    // polinomio.coeficientes = coeficientes;

    return polinomio;
}

bool polinomio_is_null(POLINOMIO polinomio) {
    /*if(polinomio.coeficientes == NULL || polinomio.grau == 0){
        return true;
    } else {
        return false;
    }*/
    return (polinomio.coeficientes == NULL || polinomio.grau == 0);
}

void free_polinomio(POLINOMIO *polinomio) {
    free(polinomio->coeficientes);
    polinomio->grau = 0;
}

double potencia(double base, int expoente) {
    if (expoente == 0) {
        return 1;
    } else if (expoente > 0) {
        return base * potencia(base, expoente - 1);
    } else {
        return 1 / (base * potencia(base, -expoente - 1));
    }
}

float valor_polinomio(POLINOMIO polinomio, float x) {
    if(polinomio_is_null(polinomio)){
        printf("Polinomio vazio!\n");
        exit(1);
    }

    float resultado = polinomio.coeficientes[0];
    for(int i = 1; i <= polinomio.grau; i++){
        resultado = resultado + polinomio.coeficientes[i] * potencia(x, i);
    }

    return resultado;
}

void print_polinomio(POLINOMIO polinomio) {
    printf("p(x) = (%f)", polinomio.coeficientes[0]);
    for (int i = 1; i <= polinomio.grau; i++) {
        printf("+(%f)x^%d", polinomio.coeficientes[i], i);
    }
    printf("\n");
}
