#ifndef DYV_H
#define DYV_H

#include <vector>
#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>

template <typename T>
int BusquedaBinaria(const T& x, const std::vector<T>& V, int ini, int fin) {
    if (ini > fin) {
        return -1;
    }

    int medio = (ini + fin) / 2;

    if (V[medio] == x) {
        return medio;
    } else if (V[medio] > x) {
        return BusquedaBinaria(x, V, ini, medio - 1);
    } else {
        return BusquedaBinaria(x, V, medio + 1, fin);
    }
}

template <typename T>
int BusquedaBinaria_INV(const T& x, const std::vector<T>& V, int ini, int fin) {
    if (ini > fin) {
        return -1;
    }

    int medio = (ini + fin) / 2;

    if (V[medio] == x) {
        return medio;
    } else if (V[medio] < x) {
        return BusquedaBinaria_INV(x, V, ini, medio - 1);
    } else {
        return BusquedaBinaria_INV(x, V, medio + 1, fin);
    }
}

template <typename T>
int Partition(std::vector<T>& V, int ini, int fin) {
    T x = V[fin];
    int i = ini;

    for (int j = ini; j < fin; j++) {
        if (V[j] <= x) {
            std::swap(V[i], V[j]);
            i++;
        }
    }

    std::swap(V[i], V[fin]);
    return i;
}

template <typename T>
void QuickSort(std::vector<T>& V, int ini, int fin) {
    if (ini < fin) {
        int pivot = Partition(V, ini, fin);
        QuickSort(V, ini, pivot - 1);
        QuickSort(V, pivot + 1, fin);
    }
}

template <typename T>
void QuickSortFirst(std::vector<T>& V, int ini, int fin) {
    if (ini < fin) {
	std::swap(V[ini], V[fin]);
	
        int pivot = Partition(V, ini, fin);
        QuickSortFirst(V, ini, pivot - 1);
        QuickSortFirst(V, pivot + 1, fin);
    }
}

template <typename T>
void QuickSortCentral(std::vector<T>& V, int ini, int fin) {
    if (ini < fin) {
        int middle = (ini + fin) / 2;
        std::swap(V[middle], V[fin]);

        int pivot = Partition(V, ini, fin);
        QuickSortCentral(V, ini, pivot - 1);
        QuickSortCentral(V, pivot + 1, fin);
    }
}

template <typename T>
void QuickSortRandom(std::vector<T>& V, int ini, int fin) {
    if (ini < fin) {
    	int randomIndex = ini + rand() % (fin - ini + 1);
    	std::swap(V[randomIndex], V[fin]);

        int pivot = Partition(V, ini, fin);
        QuickSortCentral(V, ini, pivot - 1);
        QuickSortCentral(V, pivot + 1, fin);
    }
}

template <typename T>
float MeasureQuickSortTime(void(*sortFunction)(std::vector<T>&, int, int), std::vector<T>& V, int ini, int fin) {
    auto start = std::chrono::high_resolution_clock::now();
    sortFunction(V, ini, fin);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float, std::milli> duration = end - start;
    return duration.count();
}

#endif
