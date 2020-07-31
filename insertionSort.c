#include "insertionSort.h"
int* insertionSort(int* arreglo, int size) 
{ 
    int i, llave, j; 
    for (i = 1; i < size; i++) { 
        llave = arreglo[i]; 
        j = i - 1; 

        while (j >= 0 && arreglo[j] > llave) { 
            arreglo[j + 1] = arreglo[j]; 
            j = j - 1; 
        } 
        arreglo[j + 1] = llave; 
    } 
    return arreglo;
} 