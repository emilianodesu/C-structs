#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Crea la estructura Empleado y Departamento
struct Empleado {
    char nombre[20];
    float salario;
};
struct Departamento {
    char nombre[20];
    struct Empleado *empleados;         //Apuntador a un arreglo dinámico de empleados
    int numEmpleados;
};

// Función para asignar valores a un empleado
void asignarEmpleado(struct Empleado *e, char nombre[], float salario) {
    strcpy(e->nombre, nombre);          //Copia el nombre al campo nombre de la estructura
    e->salario = salario;               //Asigna el salario al campo salario de la estructura
}

int main (){
    //Declara las variables globales que se utilizarán
    char nombre[20];
    float salario;

    struct Departamento departamento;           //Declara una variable de tipo Departamento
    printf("Introduzca el nombre del departamento: ");
    scanf("%s", departamento.nombre);           //Lee el nombre del departamento

    printf("Introduce el número de empleados: ");
    scanf("%d", &departamento.numEmpleados);    //Lee el número de empleados

    //Reserva memoria para el arreglo dinámico de empleados usando malloc
    departamento.empleados = (struct Empleado *)malloc(departamento.numEmpleados * sizeof(struct Empleado));

    //Ciclo para asignar valores a los empleados
    for (int i = 0; i < departamento.numEmpleados; i++) {
        printf("Introduce el nombre del empleado %d: ", i + 1);
        scanf("%s", nombre);
        printf("Introduce el salario del empleado %d: ", i + 1);
        scanf("%f", &salario);
        asignarEmpleado(&departamento.empleados[i], nombre, salario); // Asigna valores al empleado
    }

    // Imprime la información del departamento y sus empleados
    printf("\nDepartamento: %s\n", departamento.nombre);
    for (int i = 0; i < departamento.numEmpleados; i++) {
        printf("Empleado %d: %s, Salario: %.2f\n", i + 1, departamento.empleados[i].nombre, departamento.empleados[i].salario);
    }

    // Libera la memoria reservada para los empleados
    free(departamento.empleados);

    return 0;
}