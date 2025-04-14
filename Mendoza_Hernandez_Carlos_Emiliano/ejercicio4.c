#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definicion de la esrtructura empleado
typedef struct {
    char nombre[50];
    int edad;
    float salario;
} Empleado;

// Definicion de la estructura Departamento
typedef struct {
    char nombre[50];
    Empleado *empleados;
    int num_empleados;
} Departamento;

// Firmas de las funciones
void crearDepartamento(Departamento*, char*);
void agregarEmpleado(Departamento*, char*, int, float);
void imprimirDepartamento(Departamento*);
void vaciarDepartamento(Departamento*);

int main() {
    // Crear un departamento
    Departamento ventas;
    crearDepartamento(&ventas, "Ventas");

    // Agregar empleados al departamento
    agregarEmpleado(&ventas, "Juan Perez", 30, 45000.50);
    agregarEmpleado(&ventas, "Maria Lopez", 28, 59600.0);
    agregarEmpleado(&ventas, "Carlos Mendoza", 35, 67500.0);
    agregarEmpleado(&ventas, "Ana Torres", 32, 52500.0);
    agregarEmpleado(&ventas, "Luis Garcia", 29, 38900.0);

    // Imprimir la informacion del departamento
    imprimirDepartamento(&ventas);

    // Liberar la memoria de los empleados
    vaciarDepartamento(&ventas);
    return 0;
}

void crearDepartamento(Departamento *dpto, char *nombre) {
    // Inicializa el departamento
    strcpy(dpto->nombre, nombre);
    dpto->num_empleados = 0;
    dpto->empleados = NULL;
}

void agregarEmpleado(Departamento *dpto, char *nombre, int edad, float salario) {
    // Agrega un nuevo empleado al departamento manteniendo los anteriores
    Empleado *nuevos_empleados = (Empleado*)realloc(dpto->empleados, (dpto->num_empleados+1) * sizeof(Empleado));
    if (nuevos_empleados == NULL) {
        printf("Error al asignar memoria\n");
        return;
    }
    dpto->empleados = nuevos_empleados;
    strcpy(dpto->empleados[dpto->num_empleados].nombre, nombre);
    dpto->empleados[dpto->num_empleados].edad = edad;
    dpto->empleados[dpto->num_empleados].salario = salario;
    dpto->num_empleados++;
}

void imprimirDepartamento(Departamento *dpto) {
    // Muesta la informacion del departamento y sus empleados
    if (dpto == NULL) {
        printf("Departamento no inicializado.\n");
        return;
    }
    printf("Departamento: %s\n", dpto->nombre);
    if (dpto->num_empleados == 0) {
        printf("No hay empleados en este departamento.\n");
        return;
    }
    printf("Numero de empleados: %d\n", dpto->num_empleados);
    printf("Empleados:\n");
    for (int i = 0; i < dpto->num_empleados; i++) {
        printf("Nombre: %s, Edad: %d, Salario: %.2f\n", dpto->empleados[i].nombre, dpto->empleados[i].edad, dpto->empleados[i].salario);
    }
}

void vaciarDepartamento(Departamento *dpto) {
    // Reinicia el departamento y libera la memoria de los empleados
    if (dpto->empleados != NULL) {
        free(dpto->empleados);
        dpto->empleados = NULL;
    }
    dpto->num_empleados = 0;
}