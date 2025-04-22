#include <stdio.h>
#include <stdlib.h>

struct Producto {
    char nombre[20];
    float precio;
    int cantidad;
};  //Define la estructura Producto con nombre, precio y cantidad

//Función para asignar valores a un producto
void asignarProducto(struct Producto *p, char nombre[], float precio, int cantidad) {
    strcpy(p->nombre, nombre);  //Copia el nombre al campo nombre de la estructura
    p->precio = precio;         //Asigna el precio al campo precio de la estructura
    p->cantidad = cantidad;     //Asigna la cantidad al campo cantidad de la estructura
}

//Función para calcular el valor total del inventario
float calcularValorTotal(struct Producto *productos, int numProductos) { //Recibe un arreglo de productos y su tamaño
    float total = 0.0;  //Inicializa el total a 0
    for (int i = 0; i < numProductos; i++) {
        total += productos[i].precio * productos[i].cantidad;  //Suma el valor de cada producto al total
    }
    return total;  //Devuelve el valor total del inventario
}

int main(){
    struct Producto productos[3]; // Declara un arreglo de 3 estructuras Producto
    //Asigna valores a los productos usando la función asignarProducto
    asignarProducto(&productos[0], "Producto1", 10.0, 5); 
    asignarProducto(&productos[1], "Producto2", 20.0, 3); 
    asignarProducto(&productos[2], "Producto3", 15.0, 10); 

    float valorTotal = calcularValorTotal(productos, 3); // Calcula el valor total del inventario
    printf("El valor total del inventario es: %.2f\n", valorTotal); // Imprime el valor total del inventario

    return 0;
}
