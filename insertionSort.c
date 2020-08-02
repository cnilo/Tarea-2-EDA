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
/* Insertion Sort se realizó mediante el seudocódigo que nos entregó el profe. se itera I para los elementos del arreglo y J
que toma como valor la posición anterior del arreglo para hacer la comparación. */