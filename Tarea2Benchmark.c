#include "heapSort.h"
#include "insertionSort.h"
#include <string.h>
#include <time.h>

int* crearArreglo(const char nombredearchivo[200], int* size) // Se crea esta función para crear un arreglo dinámico de enteros recorriendo el archivo
{       
    int *arreglo=malloc(sizeof(int)); // Se pide memoria dinámica.
    FILE *pfile; //Se crea un puntero al archivo
    pfile = fopen(nombredearchivo ,"r");  // Se abre el archivo en modo lectura
    char linea[48]; // Esta variable guardará lo que el programa encuentre en cada línea
    int contador = 0; //Se añade un contador para recorrer el arreglo
    while(!feof(pfile)){
        arreglo=realloc(arreglo, sizeof(int)*(contador+1)); //Por cada linea pedimos memoria consistente con la cantidad de lineas recorrodas
        char *actual=fgets(linea,8,pfile); //Extraemos el contenido de la línea
        arreglo[contador]=atoi(actual); // Se guarda en el arreglo casteándose a entero.
        contador++;
    }
    fclose(pfile);
    arreglo=realloc(arreglo, sizeof(int)*(contador+1));
    arreglo[contador]=-1;
    *size = contador; //pasamos por referenicia a size el largo del arreglo para poder utilizarlo en otras funciones.
    return arreglo;              
}


void printArray(int* arreglo, int size) // Función sencilla que imprimirá uno por uno los elementos de nuestro arreglo.
{ 
    int i; 
    for (i = 0; i < size; i++) //Iteramos sobre el arreglo y por cada iteración imprimimos el elemento i.
        printf("%d ", arreglo[i]); 
    printf("\n");
}


int main(int argc, char const *argv[]) // Implementamos la función main con argc y argv que nos servirán para recibir como parámetros tanto la función como el nombre del arhivo
{
    clock_t inicio = clock();
    int size = 0; // Inicializamos tamaño, que pasaremos por referencia a crearArreglo para poder recibir el tamaño del arreglo.
	int* arreglo = crearArreglo(argv[1], &size); // En arreglo guardaremos un arreglo, creado por crear arreglo con el nombre de archivo dado en consola

    if(!strcmp(argv[2], "insertionSort")) // Comparamos el string dado en argv[2] y en caso de ser insertionSort, imprimimos el arreglo desordenado, realizamos insertion sort e imprimimos el arreglo ordenado
    {
        insertionSort(arreglo,size);
        clock_t fin = clock();
        double tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
        printf("Runtime: %f [s]", tiempo);
       

    }

    if(!strcmp(argv[2], "heapSort")) // Mismo caso para heap sort
    {

        heapSort(arreglo,size);
        clock_t fin = clock();
        double tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
        printf("Runtime: %f [s]", tiempo);
    }

    else
    {
        printf("Compruebe que el nombre del algoritmo ha sido ingresado correctamente.\n");
    }

	return 0;
}
