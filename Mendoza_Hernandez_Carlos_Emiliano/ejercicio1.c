#include <stdio.h>
#include <string.h>

// Definicion de la estructura Coche
typedef struct {
    char marca[20];
    char modelo[20];
    int anio;
    float precio;
} Coche;

int main() {
    // Declaramos una variable de tipo Coche
    Coche miCoche;
    // Creamos un apuntador de tipo Coche
    Coche *miCochePtr = &miCoche;

    // Asignamos valores a los campos de la estructura usando el apuntador
    strcpy(miCochePtr->marca, "Toyota");
    strcpy(miCochePtr->modelo, "Corolla");
    miCochePtr->anio = 2020;
    miCochePtr->precio = 20000.50;

    // Imprimimos los valores de la estructura
    printf("Marca: %s\n", miCochePtr->marca);
    printf("Modelo: %s\n", miCochePtr->modelo);
    printf("Anyo: %d\n", miCochePtr->anio);
    printf("Precio: $%.2f\n", miCochePtr->precio);

    return 0;
}