#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "polinomio.h"

#define MAXC 128

int main() {
    char filename[] = "poli1.txt";
    POLINOMIO poli_1;
    printf("Nome do arquivo do primeiro polinômio:\n");
    // scanf("%s", filename);
    // filename = "poli1.txt";
    poli_1 = polinomio_from_file(filename);
    print_polinomio(poli_1);
    printf("\nResultado: %f\n",valor_polinomio(poli_1,10));
    return 0;
}

/*
    printf("%s\n", filename);
    file_pointer = fopen(filename,"r");
    if(file_pointer == NULL){
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }
    if(1){
    for(int i=0;i<5;i++){
        fscanf(file_pointer,"%f",&vetor[i]);
    }
    for(int i=0;i<5;i++){
        printf("%f\n",vetor[i]);
    }
    printf("%ld",ftell(file_pointer));
}

    fseek(file_pointer,0,SEEK_SET);

    while(!feof(file_pointer)){
        float temp;
        fscanf(file_pointer, "%f", &temp);
        tamanho++;

        //printf("%f",temp);
    }
    vetor = malloc(tamanho*sizeof(float));
    for(int i=0; i<= sizeof(vetor)/sizeof(vetor[0]);i++){
        fscanf(file_pointer,"%l", vetor[i]);
        printf("%f\n", vetor[i]);
    }
    printf("\n%ld",ftell(file_pointer));
*/
