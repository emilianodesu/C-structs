#include <stdio.h>
#include <stdlib.h>
//Crea la estructura Punto con coordenadas x & y
struct Punto {
    int x;      
    int y;
};
//Crea la función coordenadas que devuelve un struct Punto
struct Punto coordenadas() {
    
    struct Punto p;     //Declara una variable de tipo Punto
    p.x = rand() % 100; //Genera un número aleatorio entre 0 y 99
    p.y = rand() % 100; //Genera un número aleatorio entre 0 y 99
    
    return p;           //Devuelve la variable p, que es de tipo struct Punto
}

int main() {
    struct Punto p1;    //Declara una variable de tipo Punto
    printf("Bienvenido al programa de coordenadas\n");
    printf("Coordenadas iniciales de P1: (%d, %d)\n", p1.x, p1.y); //Imprime las coordenadas iniciales de p1
    // Llamada a la función coordenadas para obtener las coordenadas de p1
    p1 = coordenadas();
    printf("Coordenadas de P1: (%d, %d)\n", p1.x, p1.y);
    // Llamada a la función coordenadas para obtener otras coordenadas
    p1 = coordenadas();
    printf("Coordenadas de P1 segunda vuelta: (%d, %d)\n", p1.x, p1.y);    
    return 0;
}