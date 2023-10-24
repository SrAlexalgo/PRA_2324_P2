#ifndef DYV_H
#define DYV_H

#include <vector>
#include <iostream>

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

#endif