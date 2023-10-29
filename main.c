#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include "polinomio.h"

#define MAXC 128

int main() {
    setlocale(LC_ALL,"");
    char nome_arquivo[] = "poli1.txt";
    char nome_arquivo2[] = "poli2.txt";
    POLINOMIO poli_1;
    POLINOMIO poli_2;
    POLINOMIO auxiliar;


    printf("Nome do arquivo do primeiro polinômio:\n");
    // scanf("%s", nome_arquivo);
    // filename = "poli1.txt";
    poli_1 = criar_polinomio_arquivo(nome_arquivo);
    printf("Primeiro polinômio:\n");
    imprimir_polinomio(poli_1);
    auxiliar = derivar_polinomio(poli_1);
    printf("Derivada do primeiro polinômio:\n");
    imprimir_polinomio(auxiliar);
    liberar_polinomio(&auxiliar);


    printf("Nome do arquivo do segundo polinômio:\n");
    // scanf("%s", nome_arquivo);
    poli_2 = criar_polinomio_arquivo(nome_arquivo2);
    printf("Segundo polinômio:\n");
    imprimir_polinomio(poli_2);
    auxiliar = derivar_polinomio(poli_2);
    printf("Derivada do segundo polinômio:\n");
    imprimir_polinomio(auxiliar);
    liberar_polinomio(&auxiliar);
    if(!verificar_polinomio_vazio(auxiliar)){
        printf("Erro: polinômio não foi liberado!\n");
        exit(1);
    }
    

    printf("Soma dos polinômios:\n");
    auxiliar = somar_polinomio(poli_1,poli_2);
    imprimir_polinomio(auxiliar);
    liberar_polinomio(&auxiliar);
    if(!verificar_polinomio_vazio(auxiliar)){
        printf("Erro: polinômio não foi liberado!\n");
        exit(1);
    }

    printf("Subtração dos polinômios:\n");
    auxiliar = subtrair_polinomio(poli_1,poli_2);
    imprimir_polinomio(auxiliar);
    liberar_polinomio(&auxiliar);
    if(!verificar_polinomio_vazio(auxiliar)){
        printf("Erro: polinômio não foi liberado!\n");
        exit(1);
    }

    printf("Multiplicação dos polinômios:\n");
    auxiliar = multiplicar_polinomio(poli_1,poli_2);
    imprimir_polinomio(auxiliar);
    liberar_polinomio(&auxiliar);
    if(!verificar_polinomio_vazio(auxiliar)){
        printf("Erro: polinômio não foi liberado!\n");
        exit(1);
    }

    float limite_inferior=0, limite_superior=1;
    printf("Digite os limites inferior e superio de integração: \n");
    //scanf("%f", &limite_inferior);
    //scanf("%f", &limite_superior);
    printf("Valor da integral definida do primeiro polinômio: %f\n", integraldef_polinomio(poli_1,limite_inferior,limite_superior));
    printf("Valor da integral definida do segundo polinômio: %f\n", integraldef_polinomio(poli_2,limite_inferior,limite_superior));
    


    //printf("\nResultado: %f\n",calcular_polinomio(poli_1,10));


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
