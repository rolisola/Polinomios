#include "polinomio.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

POLINOMIO criar_polinomio(int grau) {
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

POLINOMIO criar_polinomio_arquivo(char *nome_arquivo) {
    FILE *ponteiro_arquivo = NULL;
    float coeficiente = 0;
    int grau = -1;// inicializa em -1 para contar o x^0 na determinação do grau do polinômio

    ponteiro_arquivo = fopen(nome_arquivo, "r");

    if (ponteiro_arquivo == NULL) {
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }

    while (!feof(ponteiro_arquivo)) {
        if (fscanf(ponteiro_arquivo, "%f", &coeficiente) == 1) {
            grau++;
        } else {
            printf("Erro ao ler valor!\n");
            exit(1);
        }
    }

    POLINOMIO polinomio = criar_polinomio(grau);

    fseek(ponteiro_arquivo, 0, SEEK_SET);

    for (int i = 0; i <= polinomio.grau; i++) {
        // printf("yyyyyyyyyyy\n");
        if (fscanf(ponteiro_arquivo, "%f", &polinomio.coeficientes[i]) == 1) {
            // printf("i: %d\n",i);
            // printf("coef: %f\n", polinomio.coeficientes[i]);
        } else {
            printf("Erro ao atribuir valor!\n");
            exit(1);
        }
    }

    /*if (verificar_polinomio_vazio(polinomio)) {
        printf("Polinomio esta vazio!\n");
        exit(1);
    }else{
        printf("Polinomio nao esta vazio!\n");
    }*/

    /*
    for(int i = 0; i < grau; i++){
        printf("%f\n", polinomio.coeficientes[i]);
    }*/
    /*while(!foef(ponteiro_arquivo)){
        if(fscanf(ponteiro_arquivo, "%f", polinomio.coeficientes[i]) == 1){
        }else{
            printf("Erro ao ler valor!\n");
            exit(1);
        }
    }*/

    // polinomio.coeficientes = coeficientes;

    return polinomio;
}

bool verificar_polinomio_vazio(POLINOMIO polinomio) {
    /*if(polinomio.coeficientes == NULL || polinomio.grau == 0){
        return true;
    } else {
        return false;
    }*/
    return (polinomio.coeficientes == NULL || polinomio.grau == 0);
}

void liberar_polinomio(POLINOMIO *polinomio) {
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

float calcular_polinomio(POLINOMIO polinomio, float x) {
    if(verificar_polinomio_vazio(polinomio)){
        printf("Polinomio vazio!\n");
        exit(1);
    }

    float resultado = polinomio.coeficientes[0];
    for(int i = 1; i <= polinomio.grau; i++){
        resultado = resultado + polinomio.coeficientes[i] * potencia(x, i);
    }

    return resultado;
}

void imprimir_polinomio(POLINOMIO polinomio) {
    printf("p(x) = (%f)", polinomio.coeficientes[0]);
    for (int i = 1; i <= polinomio.grau; i++) {
        printf("+(%f)x^%d", polinomio.coeficientes[i], i);
    }
    printf("\n");
}
