#include "heapSort.h"

void swap(int *n1, int *n2)
{
	int temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

int* buildHeap(int* arreglo, int size, int i)
{
	int maximo = i;
	int hijoIzquierda = 2 * i + 1;
	int hijoDerecha = 2 * i +2;

	if(hijoIzquierda < size && arreglo[hijoIzquierda] > arreglo[maximo])
	{
		maximo = hijoIzquierda;
	}
	if(hijoDerecha < size && arreglo[hijoDerecha] > arreglo[maximo])
	{
		maximo = hijoDerecha;
	}
	return arreglo;
}


int* heapSort(int* arreglo, int size)
{
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		buildHeap(arreglo, size, i);
	}
	for (int i = size - 1; i>= 0; i--)
	{
		swap(&arreglo[0], &arreglo[i]);
		buildHeap(arreglo,i,0);
	}
	return arreglo;
}
