#include "insertionSort.h"

int* crearArreglo(const char nombredearchivo[200], int* size)
{
    int *arreglo=malloc(sizeof(int));
    FILE *pfile;
    pfile = fopen(nombredearchivo ,"r");  
    char linea[48];
    int contador = 0;
    while(!feof(pfile)){
        arreglo=realloc(arreglo, sizeof(int)*(contador+1));
        char *actual=fgets(linea,8,pfile);
        arreglo[contador]=atoi(actual);
        contador++;
    }
    fclose(pfile);
    arreglo=realloc(arreglo, sizeof(int)*(contador+1));
    arreglo[contador]=-1;
    *size = contador;
    return arreglo;

	                  
}

void printArray(int* arreglo, int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        printf("%d ", arreglo[i]); 
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int size = 0;
	int* arreglo = crearArreglo(argv[1], &size);
    int n = sizeof(arreglo) / sizeof(arreglo[0]);
    printArray(arreglo,size);
    insertionSort(arreglo,size);
    printf("\n Arreglo ordenado: \n");
    printArray(arreglo,size);
    
	return 0;
}
