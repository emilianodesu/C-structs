#include <stdio.h>
#include <stdlib.h>

struct coche {
    char marca[20];
    char modelo[20];
    int year;
};

int main(){
    struct coche *ptr_coche; //Declaración del apuntador a la estructura coche
    struct coche mi_coche;   //Declaración de una variable de tipo coche

    ptr_coche = &mi_coche;   //Inicialización del apuntador con la dirección de mi_coche

    printf("Introduce la marca del coche: ");       
    scanf("%s", ptr_coche->marca);                  //Almacena la marca con -> en la estructura a la que apunta ptr_coche
    printf("Introduce el modelo del coche: ");
    scanf("%s", ptr_coche->modelo);                 //Almacena el modelo con -> en la estructura a la que apunta ptr_coche
    printf("Introduce el año del coche: ");
    scanf("%d", &ptr_coche->year);  

    printf("\nMarca: %s\nModelo: %s\nAño: %d\n", ptr_coche->marca, ptr_coche->modelo, ptr_coche->year);

    return 0;
}