#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "polinomio.h"

// Cria polinômio a partir do grau recebido
POLINOMIO new_polynomial(int degree) {
    POLINOMIO polynomial;

    polynomial.degree = degree;
    polynomial.coefficients = (float *)malloc((degree + 1) * sizeof(float));
    return polynomial;
}

// Cria polinômio a partir do arquivo recebido
POLINOMIO new_polynomial_from_file(char *filename) {
    FILE *file_pointer = NULL;
    float coefficient = 0;
    int degree = -1; // inicializa em -1 por conta do x^0 na determinação do grau do polinômio

    // Tratamento de incompetência de usuário
    file_pointer = fopen(filename, "r");
    while (file_pointer == NULL) {
        printf("Arquivo não encontrado. Tente novamente!\n");
        scanf("%s", filename);
        file_pointer = fopen(filename, "r");
    }

    // Realiza leitura para contagem do grau do polinômio
    while (!feof(file_pointer)) {
        if (fscanf(file_pointer, "%f", &coefficient) == 1) {
            degree++;
        } else {
            printf("Erro ao ler valor, valor inválido!\n");
            exit(1);
        }
    }

    POLINOMIO polynomial = new_polynomial(degree);

    fseek(file_pointer, 0, SEEK_SET);

    // Realiza leitura para atribuição de valores
    for (int i = 0; i <= polynomial.degree; i++) {
        if (fscanf(file_pointer, "%f", &polynomial.coefficients[i]) == 1) {
        } else {
            printf("Erro ao atribuir valor!\n");
            exit(1);
        }
    }

    fclose(file_pointer);

    return polynomial;
}

// Verifica se o polinômio está vazio
bool polynomial_is_null(POLINOMIO polynomial) {
    /*if(polynomial.coefficients == NULL || polynomial.degree == 0){
        return true;
    } else {
        return false;
    }*/
    return (polynomial.coefficients == NULL || polynomial.degree == 0);
}

// Libera alocação do polinômio
void polynomial_free(POLINOMIO *polynomial) {
    free(polynomial->coefficients);
    polynomial->degree = 0;
}

// Calcula resultado do polinômio por x
float polynomial_result(POLINOMIO polynomial, float x) {
    if (polynomial_is_null(polynomial)) {
        printf("Polinômio vazio!\n");
        exit(1);
    }

    float result = polynomial.coefficients[0];
    for (int i = 1; i <= polynomial.degree; i++) {
        result = result + polynomial.coefficients[i] * pow(x, i);
    }

    return result;
}

// Imprime polinômio
void polynomial_print(POLINOMIO polynomial) {
    printf("p(x) = (%.2f)", polynomial.coefficients[0]);
    for (int i = 1; i <= polynomial.degree; i++) {
        printf("+(%.2f)x^%d", polynomial.coefficients[i], i);
    }
    printf("\n");
}
