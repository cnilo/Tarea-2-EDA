#include "heapSort.h"

int* buildHeap(int* arreglo, int size) // Construimos nuestro heap a partir del arreglo realizando iterativamente siftDown
{
	for(int i = size / 2; i >= 0; i--){
         siftDown(arreglo, arreglo[i], i, size);
     }
}

int* heapSort(int* arreglo, int size) // heapSort construye un heap a partir de un arreglo y luego realiza iterativamente siftDown comparando posiciones para ordenarlo
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

/* siftDown inicializa el hijo izquierdo de un elemento del heap además recibe el último valor del heap. Realiza un while que 
compara que hijo izquierdo sea menor que el último valor (eso significa que tiene hijos) luego compara estos hijos y en caso de que
el heap se encuentre desordenado, hace el intercambio. */

void siftDown(int* arreglo, int valor, int raiz, int ultimo){
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

/* siftUp por su parte realiza un proceso similar, sólo que en el caso contrario, es decir sube un nivel el nodo */

void siftup(int n, int* arreglo) 
{
	int i, j, temp;
	for (j=n; j>1; j=i) 
	{ 
		i=j/2; 
		if ( arreglo[i] <= arreglo[j] )
		break; 
	temp = arreglo[j]; arreglo[j]= arreglo[i]; arreglo[i]=temp;
	}
}

void insert(int* arreglo, int valor, int ultimo)
{
	ultimo++;
	arreglo[ultimo]= valor; 
	siftup(ultimo, arreglo); 
}

