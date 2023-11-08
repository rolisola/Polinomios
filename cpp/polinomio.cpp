#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

struct POLINOMIO {
    int degree;
    std::vector<float> coefficients;
};

// Cria polinômio a partir do grau recebido
POLINOMIO new_polynomial(int degree) {
    POLINOMIO polynomial;
    polynomial.degree = degree;
    polynomial.coefficients.resize(degree + 1);
    return polynomial;
}

// Cria polinômio a partir do arquivo recebido
POLINOMIO new_polynomial_from_file(std::string filename) {
    std::ifstream file_pointer(filename);
    if (!file_pointer) {
        std::cout << "Arquivo não encontrado. Tente novamente!" << std::endl;
        std::cin >> filename;
        file_pointer.open(filename);
        while (!file_pointer) {
            std::cout << "Arquivo não encontrado. Tente novamente!" << std::endl;
            std::cin >> filename;
            file_pointer.open(filename);
        }
    }
    float coefficient = 0;
    int degree = -1;
    while (file_pointer >> coefficient) {
        degree++;
    }
    POLINOMIO polynomial = new_polynomial(degree);
    file_pointer.clear();
    file_pointer.seekg(0, std::ios::beg);
    for (int i = 0; i <= polynomial.degree; i++) {
        if (file_pointer >> polynomial.coefficients[i]) {
        } else {
            std::cout << "Erro ao atribuir valor!" << std::endl;
            exit(1);
        }
    }
    file_pointer.close();
    return polynomial;
}

// Verifica se o polinômio está vazio
bool polynomial_is_null(POLINOMIO polynomial) {
    return (polynomial.coefficients.empty() || polynomial.degree == 0);
}

// Libera alocação do polinômio
void polynomial_free(POLINOMIO *polynomial) {
    polynomial->coefficients.clear();
    polynomial->degree = 0;
}

// Calcula resultado do polinômio por x
float polynomial_result(POLINOMIO polynomial, float x) {
    if (polynomial_is_null(polynomial)) {
        std::cout << "Polinômio vazio!" << std::endl;
        exit(1);
    }
    float result = polynomial.coefficients[0];
    for (int i = 1; i <= polynomial.degree; i++) {
        result = result + polynomial.coefficients[i] * std::pow(x, i);
    }
    return result;
}

// Imprime polinômio
void polynomial_print(POLINOMIO polynomial) {
    std::cout << "p(x) = (" << polynomial.coefficients[0] << ")";
    for (int i = 1; i <= polynomial.degree; i++) {
        std::cout << "+(" << polynomial.coefficients[i] << ")x^" << i;
    }
    std::cout << std::endl;
}


