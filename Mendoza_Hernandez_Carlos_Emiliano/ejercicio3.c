#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definicion de la estructura Punto
typedef struct {
    int x;
    int y;
} Punto;

// Funcion para generar puntos aleatorios
Punto generarPuntoAleatorio(int maxX, int maxY) {
    Punto p;
    p.x = rand() % (maxX+1); // Genera un numero aleatorio entre 0 y maxX
    p.y = rand() % (maxY+1); // Genera un numero aleatorio entre 0 y maxY
    return p;
}

int main() {
    // Semilla para la generacion de numeros aleatorios
    srand(time(NULL));

    // Definimos un arreglo de 10 puntos
    Punto puntos[10];

    // Generamos puntos aleatorios y los almacenamos en el arreglo
    for (int i = 0; i < 10; i++) {
        puntos[i] = generarPuntoAleatorio(100, 100); // Genera puntos en un rango de 0 a 100
    }

    // Imprimimos los puntos generados
    printf("Puntos generados:\n");
    for (int i = 0; i < 10; i++) {
        printf("Punto %d: (%d, %d)\n", i+1, puntos[i].x, puntos[i].y);
    }
    return 0;
}