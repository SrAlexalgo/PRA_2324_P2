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

    std::vector<int> b = {9, 7, 5, 2, 8, 1, 4, 10, 6, 3};
    int ini = 0;
    int fin = b.size() - 1;
    srand(time(0));

    float timeFirst = MeasureQuickSortTime(QuickSortFirst, b, ini, fin);
    std::cout << "QuickSort (Pivote en el primer elemento) - Tiempo: " << timeFirst << " ms" << std::endl;

    for(int i = 0; i <= fin; i++){
	std::cout <<  b[i] << " ";
    } std::cout << std::endl;

    b = {9, 7, 5, 2, 8, 1, 4, 10, 6, 3};

    float time = MeasureQuickSortTime(QuickSort, b, ini, fin);
    std::cout << "QuickSort (Pivote en la última posición) - Tiempo: " << time << " ms" << std::endl;

    for(int i = 0; i <= fin; i++){
	std::cout <<  b[i] << " ";
    } std::cout << std::endl;

    b = {9, 7, 5, 2, 8, 1, 4, 10, 6, 3};

    float timeCentral = MeasureQuickSortTime(QuickSortCentral, b, ini, fin);
    std::cout << "QuickSort (Pivote en el elemento central) - Tiempo: " << timeCentral << " ms" << std::endl;

    for(int i = 0; i <= fin; i++){
	std::cout <<  b[i] << " ";
    } std::cout << std::endl;

b = {9, 7, 5, 2, 8, 1, 4, 10, 6, 3};

    float timeRandom = MeasureQuickSortTime(QuickSortRandom, b, ini, fin);
    std::cout << "QuickSort (Pivote en el elemento random) - Tiempo: " << timeRandom << " ms" << std::endl;

    for(int i = 0; i <= fin; i++){
	std::cout <<  b[i] << " ";
    } std::cout << std::endl;

    return 0;
}
