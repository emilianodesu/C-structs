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
    strcpy(libro->titulo, titulo);
    strcpy(libro->autor, autor);
    libro->year = year;
}

int main() {
    //Declara las variables globales que se utilizarán
    char titulo[50];
    char autor[50];
    int year;
    int numLibros;

    printf("Introduce el número de libros: ");
    scanf("%d", &numLibros);

    //Reserva memoria para el arreglo dinámico de libros usando malloc, según el número de libros
    struct Libro *libros = (struct Libro *)malloc(numLibros * sizeof(struct Libro));

    //Asigna valores a los libros con un ciclo for
    for (int i = 0; i < numLibros; i++) {       //Desde 0 hasta uno menos numLibros nos da el total de libros
        printf("Introduce el título del libro %d: ", i + 1);
        scanf("%s", titulo);
        printf("Introduce el autor del libro %d: ", i + 1);
        scanf("%s", autor);
        printf("Introduce el año del libro %d: ", i + 1);
        scanf("%d", &year);
        asignarLibro(&libros[i], titulo, autor, year);  //Llama a la función para asignar valores, recibe el libro, el título, el autor y el año
    }

    // Imprime la información de los libros
    printf("\nLista de Libros:\n");
    for (int i = 0; i < numLibros; i++) {       //Ciclo for para imprimir los libros
        printf("Libro %d: Título: %s, Autor: %s, Año: %d\n", i + 1, libros[i].titulo, libros[i].autor, libros[i].year);
    }

    //Libera la memoria reservada para los libros
    free(libros);

    return 0;
}
