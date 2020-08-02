#ifndef HEAP_SORT_DOT_H
#define HEAP_SORT_DOT_H

#include <stdio.h>
#include <stdlib.h>

int* buildHeap(int* arreglo, int size);

int* heapSort(int* arreglo, int size);

void siftDown(int* arreglo, int valor, int raiz, int ultimo);

void siftup(int n, int* arreglo);

void insert(int* arreglo, int valor, int ultimo);
	

#endif