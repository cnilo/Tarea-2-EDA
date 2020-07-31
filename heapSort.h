#ifndef HEAP_SORT_DOT_H
#define HEAP_SORT_DOT_H
 
#include <stdio.h>
#include <stdlib.h>

void swap(int *n1, int *n2);

int* buildHeap(int* arreglo, int size, int i);

int* heapSort(int* arreglo, int size);
	

#endif