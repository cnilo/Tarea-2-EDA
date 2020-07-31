#include "heapSort.h"

int* buildHeap(int* arreglo, int size)
{
	for(int i = size / 2; i >= 0; i--){
         siftDown(arreglo, arreglo[i], i, size);
     }
}

int* heapSort(int* arreglo, int size)
{
	buildHeap(arreglo,size);
	for(int ultimo = size - 1; ultimo > 0; ultimo--)
	{
         int ultimoNodo = arreglo[ultimo];
         arreglo[ultimo] = arreglo[0];
         arreglo[0] = ultimoNodo;
         siftDown(arreglo, ultimoNodo, 0, ultimo -1);
     }
}

void siftDown(int arreglo[], int valor, int raiz, int ultimo){
     int hijoIzquierdo = 2 * raiz + 1 ;
     while(hijoIzquierdo <= ultimo)
     	{ 
         if(hijoIzquierdo < ultimo)
        	{
            	if(arreglo[hijoIzquierdo + 1] > arreglo[hijoIzquierdo])
            	{
                	hijoIzquierdo++;
            	}

        	}
         if(valor >= arreglo[hijoIzquierdo])
         {
            break;
         }
         else
         {
            arreglo[raiz] = arreglo[hijoIzquierdo];
            raiz = hijoIzquierdo;
            hijoIzquierdo = 2 * raiz + 1;
         }
         arreglo[raiz] = valor;
     	}	
}