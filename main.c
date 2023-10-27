#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXC 128

typedef struct {
    float *coeficientes;
    int grau;
}POLINOMIO;

//polinomio new_polinomio(int n);
POLINOMIO new_polinomio(int n);
void free_polinomio(POLINOMIO *p);
bool polinomio_is_null(POLINOMIO p);
float valor_polinomio(POLINOMIO p, float x);
POLINOMIO polinomio_from_file(char *filename);
void print_polinomio(POLINOMIO p);

int main()
{
    char filename[] = "poli1.txt";
    POLINOMIO poli_1;
    printf("Nome do arquivo do primeiro polinômio:\n");
    //scanf("%s", filename);
    //filename = "poli1.txt";
    poli_1 = polinomio_from_file(filename);
    print_polinomio(poli_1);


    return 0;
}

POLINOMIO new_polinomio(int grau){
    POLINOMIO polinomio;

    polinomio.grau = grau;
    polinomio.coeficientes = (float*)malloc((grau+1)*sizeof(float));
    /*for(int i=0;i<=grau;i++){
        printf("%f\n",polinomio.coeficientes[i]);
    }*/

    return polinomio;
}

POLINOMIO polinomio_from_file(char *filename){
    FILE *file_pointer = NULL;
    float coef = 0;
    int grau = 0;

    file_pointer = fopen(filename, "r");

    if(file_pointer == NULL){
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }

    while(!feof(file_pointer)){
        if(fscanf(file_pointer, "%f", &coef) == 1){
            grau++;
        }else{
            printf("Erro ao ler valor!\n");
            exit(1);
        }
    }

    POLINOMIO polinomio = new_polinomio(grau);

    fseek(file_pointer, 0, SEEK_SET);

    for(int i = 0; i < polinomio.grau; i++){
        //printf("yyyyyyyyyyy\n");
        if(fscanf(file_pointer, "%f", &polinomio.coeficientes[i]) == 1){
            //printf("i: %d\n",i);
            //printf("coef: %f\n", polinomio.coeficientes[i]);
        }else{
            printf("Erro ao atribuir valor!\n");
            exit(1);
        }
    }





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

    //polinomio.coeficientes = coeficientes;

    return polinomio;
}

void free_polinomio(POLINOMIO *poli){
    free(poli->coeficientes);
    poli->grau = 0;
}

void print_polinomio(POLINOMIO polinomio){
    printf("p(x) = (%f)", polinomio.coeficientes[0]);
    for(int i = 1; i < polinomio.grau; i++){
        printf("+(%f)x^%d",polinomio.coeficientes[i],i);
    }
    printf("\n");
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
