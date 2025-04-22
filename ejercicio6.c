#include <stdio.h>  
#include <stdlib.h>
#include <string.h>
//Crea la estructura Libro
struct Libro {
    char titulo[50];
    char autor[50];
    int year;
};
//Función para asignar valores a un libro
void asignarLibro(struct Libro *libro, char titulo[], char autor[], int year) {
    strcpy(libro->titulo, titulo);          //Usamos strcpy para copiar cadenas. Libro->titulo es un apuntador
    strcpy(libro->autor, autor);
    libro->year = year;
}
//Función para añadir un libro al catálogo
void añadirLibro(struct Libro **libros, int *numLibros, char titulo[], char autor[], int year) {
    //Aumenta el tamaño del arreglo de libros
    *libros = realloc(*libros, (*numLibros + 1) * sizeof(struct Libro));        //Realloc redimensiona el bloque de memoria
    //Asigna valores al nuevo libro con la función asignarLibro
    asignarLibro(&(*libros)[*numLibros], titulo, autor, year);
    (*numLibros)++;
}
//Función para eliminar un libro del catálogo
void eliminarLibro(struct Libro **libros, int *numLibros, int indice) {          
    if (indice < 0 || indice >= *numLibros) {     //Verifica si el índice está entre 0 y el número de libros, es decir, si es válido
        printf("Índice inválido.\n");
        return;
    }
    //Desplaza los libros hacia la izquierda para eliminar el libro en el índice dado
    for (int i = indice; i < *numLibros - 1; i++) {
        (*libros)[i] = (*libros)[i + 1];
    }
    //Reduce el tamaño del arreglo de libros
    *libros = realloc(*libros, (*numLibros - 1) * sizeof(struct Libro));
    (*numLibros)--;
}
//Función para mostrar los libros en el catálogo
void imprimirLibros(struct Libro *libros, int numLibros) {
    printf("\nLista de Libros:\n");
    for (int i = 0; i < numLibros; i++) {
        printf("Libro %d: Título: %s, Autor: %s, Año: %d\n", i + 1, libros[i].titulo, libros[i].autor, libros[i].year);
    }
}


int main() {
    //Declara las variables globales que se utilizarán
    char titulo[50];
    char autor[50];
    int year;
    int numLibros = 0;
    struct Libro *libros = NULL;        //Inicializa el puntero a NULL

    //Añade 7 libros iniciales al catálogo
    for (int i = 0; i < 7; i++) {
        printf("Introduce el título del libro %d: ", i + 1);
        scanf("%s", titulo);
        printf("Introduce el autor del libro %d: ", i + 1);
        scanf("%s", autor);
        printf("Introduce el año del libro %d: ", i + 1);
        scanf("%d", &year);
        añadirLibro(&libros, &numLibros, titulo, autor, year);
    }

    //Imprime la lista de libros
    imprimirLibros(libros, numLibros);

    //Elimina 3 libros específicos
    for (int i = 0; i < 3; i++) {
        int index;
        printf("Introduce el índice del libro a eliminar (1-%d): ", numLibros);
        scanf("%d", &index);
        eliminarLibro(&libros, &numLibros, index - 1); // Resta 1 para ajustar al índice base cero
    }

    //Imprime la lista de libros actualizada
    imprimirLibros(libros, numLibros);

    //Libera la memoria reservada para los libros
    free(libros);

    return 0;
}