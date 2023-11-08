#include <iostream>
#include <string>
#include "polinomio.h"

int main() {
    std::string filename;
    std::string filename_2;
    POLINOMIO poli_1;
    POLINOMIO poli_2;
    POLINOMIO auxiliar;

    // Bloco do primeiro arquivo
    std::cout << "Nome do arquivo do primeiro polinômio:" << std::endl;
    std::cin >> filename;
    poli_1 = new_polynomial_from_file(filename);
    std::cout << "Primeiro polinômio:" << std::endl;
    polynomial_print(poli_1);
    auxiliar = polynomial_derivate(poli_1);
    std::cout << "Derivada do primeiro polinômio:" << std::endl;
    polynomial_print(auxiliar);
    polynomial_free(&auxiliar);

    // Bloco do segundo arquivo
    std::cout << "Nome do arquivo do segundo polinômio:" << std::endl;
    std::cin >> filename_2;
    poli_2 = new_polynomial_from_file(filename_2);
    std::cout << "Segundo polinômio:" << std::endl;
    polynomial_print(poli_2);
    auxiliar = polynomial_derivate(poli_2);
    std::cout << "Derivada do segundo polinômio:" << std::endl;
    polynomial_print(auxiliar);
    polynomial_free(&auxiliar);

    if (!polynomial_is_null(auxiliar)) {
        std::cout << "Erro: polinômio não foi liberado!" << std::endl;
        exit(1);
    }

    // Bloco da soma
    std::cout << "Soma dos polinômios:" << std::endl;
    auxiliar = polynomial_sum(poli_1, poli_2);
    polynomial_print(auxiliar);
    polynomial_free(&auxiliar);

    if (!polynomial_is_null(auxiliar)) {
        std::cout << "Erro: polinômio não foi liberado!" << std::endl;
        exit(1);
    }

    // Bloco da subtração
    std::cout << "Subtração dos polinômios:" << std::endl;
    auxiliar = polynomial_subtract(poli_1, poli_2);
    polynomial_print(auxiliar);
    polynomial_free(&auxiliar);

    if (!polynomial_is_null(auxiliar)) {
        std::cout << "Erro: polinômio não foi liberado!" << std::endl;
        exit(1);
    }

    // Bloco da multiplicação
    std::cout << "Multiplicação dos polinômios:" << std::endl;
    auxiliar = polynomial_multiply(poli_1, poli_2);
    polynomial_print(auxiliar);
    polynomial_free(&auxiliar);

    if (!polynomial_is_null(auxiliar)) {
        std::cout << "Erro: polinômio não foi liberado!" << std::endl;
        exit(1);
    }

    // Bloco da integral definida
    float inferior_limit, upper_limit;
    std::cout << "Digite os limites inferior e superior de integração: ";
    std::cin >> inferior_limit >> upper_limit;
    std::cout << "Valor da integral definida do primeiro polinômio: " << polynomial_definite_integral(poli_1, inferior_limit, upper_limit) << std::endl;
    std::cout << "Valor da integral definida do segundo polinômio: " << polynomial_definite_integral(poli_2, inferior_limit, upper_limit) << std::endl;

    // Bloco de Newton-Raphson
    int max_iteration;
    float x, epsilon;
    std::cout << "Digite os parâmetros para o método de Newton-Raphson:" << std::endl;
    std::cout << "Valor inicial de x: ";
    std::cin >> x;
    std::cout << "Valor da precisão numérica: ";
    std::cin >> epsilon;
    std::cout << "Número máximo de iterações: ";
    do {
        std::cin >> max_iteration;
        std::cout << "Número de iterações deve ser maior que 1. Tente novamente!!!" << std::endl;
    } while (max_iteration < 1);

    std::cout << "Uma raíz do primeiro polinômio é (aproximadamente) " << newton_raphson(poli_1, x, epsilon, max_iteration) << std::endl;
    std::cout << "Uma raíz do segundo polinômio é (aproximadamente) " << newton_raphson(poli_2, x, epsilon, max_iteration) << std::endl;

    // Bloco da limpeza da memória
    polynomial_free(&poli_1);
    if (!polynomial_is_null(poli_1)) {
        std::cout << "Erro: polinômio não foi liberado!" << std::endl;
        exit(1);
    }

    polynomial_free(&poli_2);
    if (!polynomial_is_null(poli_2)) {
        std::cout << "Erro: polinômio não foi liberado!" << std::endl;
        exit(1);
    }

    return 0;
}


