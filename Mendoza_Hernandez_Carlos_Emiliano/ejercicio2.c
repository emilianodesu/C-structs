#include <stdio.h>
#include <string.h>

// Definicion de la estructura Producto
typedef struct {
    char nombre[30];
    float precio;
    int cantidad;
} Producto;

// Funcion para ingresar datos de un producto
void setProducto(Producto *p, char*, float, int);

int main() {
    // Declaramos un arreglo de Productos
    Producto inventario[5];

    // Llenamos el arreglo con datos de productos
    setProducto(&inventario[0], "Laptop", 1200.50, 10);
    setProducto(&inventario[1], "Mouse", 25.99, 50);
    setProducto(&inventario[2], "Teclado", 45.75, 30);
    setProducto(&inventario[3], "Monitor", 199.99, 15);
    setProducto(&inventario[4], "Impresora", 150.00, 8);

    // Sumamos el precio total de los productos
    float total = 0.0;
    for (int i = 0; i < 5; i++) {
        total += inventario[i].precio * inventario[i].cantidad;
    }

    // Imprimimos el total
    printf("El precio total de los productos es: $%.2f\n", total);
    return 0;
}

void setProducto(Producto *p, char *nombre, float precio, int cantidad) {
    // Asignamos valores a los campos de la estructura usando el apuntador
    strcpy(p->nombre, nombre);
    p->precio = precio;
    p->cantidad = cantidad;
}