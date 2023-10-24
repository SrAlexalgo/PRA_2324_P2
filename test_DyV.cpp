#include <iostream>
#include "DyV.h"

int main() {
    std::vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int X = 7;

    int result = BusquedaBinaria(X, a, 0, a.size() - 1);

    if (result != -1) {
        std::cout << "El valor " << X << " se encuentra en la posición " << result << std::endl;
    } else {
        std::cout << "El valor " << X << " no se encuentra en el vector." << std::endl;
    }

    a = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    result = BusquedaBinaria_INV(X, a, 0, a.size() - 1);

    if (result != -1) {
        std::cout << "El valor " << X << " se encuentra en la posición " << result << std::endl;
    } else {
        std::cout << "El valor " << X << " no se encuentra en el vector." << std::endl;
    }

    return 0;
}
