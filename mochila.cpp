#include <iostream>
#include <vector>
#include <limits>

std::vector<std::vector<int>> memo;

int g(int i, int C, std::vector<int>& p, std::vector<int>& b) {
    if (i == 0 || C == 0) {
        return 0;
    }

    if (memo[i][C] != -1) {
        return memo[i][C];
    }

    if (p[i - 1] > C) {
        memo[i][C] = g(i - 1, C, p, b);
    } else {
        memo[i][C] = std::max(g(i - 1, C, p, b), g(i - 1, C - p[i - 1], p, b) + b[i - 1]);
    }

    return memo[i][C];
}

std::vector<int> reconstruirSolucion(int i, int C, std::vector<int>& p, std::vector<int>& b) {
    std::vector<int> solucion;

    while (i > 0 && C > 0) {
        if (memo[i][C] != memo[i - 1][C]) {
            solucion.push_back(1);
            C -= p[i - 1];
        } else {
            solucion.push_back(0);
        }
        --i;
    }

    return solucion;
}

std::vector<int> mochila(int N, std::vector<int>& p, std::vector<int>& b, int M) {
    memo.assign(N + 1, std::vector<int>(M + 1, -1));

    int maxGanancia = g(N, M, p, b);
    std::cout << "Maxima ganancia: " << maxGanancia << std::endl;

    return reconstruirSolucion(N, M, p, b);
}

int main() {
    int N = 4;
    std::vector<int> p = {1, 3, 2, 4};
    std::vector<int> b = {10, 20, 15, 20};
    int M = 5;

    std::vector<int> solucion = mochila(N, p, b, M);

    // Mostrar la solución
    std::cout << "Solucion: ";
    for (int i = 0;i < N; i++) {
        std::cout <<  solucion[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
