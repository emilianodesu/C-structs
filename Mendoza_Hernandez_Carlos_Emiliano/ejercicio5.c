#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// Definicion de la estrcutra libro
typedef struct {
    char titulo[50];
    char autor[50];
    int anyo;
    float precio;
} Libro;

// Firmas de funciones
void agregarLibro(Libro*, char*, char*, int, float);
void imprimirLibro(Libro*);

int main() {
    // Crear un arreglo de libros
    Libro biblioteca[5];

    // Agregar libros a la biblioteca
    agregarLibro(&biblioteca[0], "Cien anyos de soledad", "Gabriel Garcia Marquez", 1967, 19.99);
    agregarLibro(&biblioteca[1], "El amor en los tiempos del colera", "Gabriel Garcia Marquez", 1985, 15.99);
    agregarLibro(&biblioteca[2], "La sombra del viento", "Carlos Ruiz Zafon", 2001, 12.99);
    agregarLibro(&biblioteca[3], "El juego del angel", "Carlos Ruiz Zafon", 2008, 14.99);
    agregarLibro(&biblioteca[4], "El alquimista", "Paulo Coelho", 1988, 10.99);

    // Imprimir los libros de la biblioteca
    printf("Libros en la biblioteca:\n");
    for (int i = 0; i < 5; i++) {
        printf("\nLibro %d:\n", i+1);
        imprimirLibro(&biblioteca[i]);
    }
    return 0;
}

void agregarLibro(Libro *libro, char *titulo, char *autor, int anyo, float precio) {
    // Copiar los datos del libro a la estructura
    strcpy(libro->titulo, titulo);
    strcpy(libro->autor, autor);
    libro->anyo = anyo;
    libro->precio = precio;
}

void imprimirLibro(Libro *libro) {
    // Imprimir los datos del libro
    printf("Titulo: %s\n", libro->titulo);
    printf("Autor: %s\n", libro->autor);
    printf("Anyo de publicacion: %d\n", libro->anyo);
    printf("Precio: $%.2f\n", libro->precio);
}