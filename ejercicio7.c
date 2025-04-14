#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura Paciente
typedef struct Paciente {
    char nombre[50];
    int edad;
    char diagnostico[100];
    int prioridad;
    struct Paciente *siguiente;
} Paciente;

//Firmas de funciones
Paciente* crearPaciente(char*, int, char*, int);
void imprimirLista(Paciente*);
void vaciarLista(Paciente*);
void agregarAlInicio(Paciente**, Paciente*);
int eliminarPaciente(Paciente**, char*);
void ordenarLista(Paciente**);

int main() {
    // Declaramos la lista de pacientes
    Paciente *lista = NULL;

    // Creamos 10 pacientes con diferentes prioridades
    agregarAlInicio(&lista, crearPaciente("Juan Perez", 30, "Fiebre", 3));
    agregarAlInicio(&lista, crearPaciente("Maria Lopez", 25, "Tos", 3));
    agregarAlInicio(&lista, crearPaciente("Carlos Sanchez", 40, "Diabetes", 2));
    agregarAlInicio(&lista, crearPaciente("Ana Torres", 35, "Fractura", 1));
    agregarAlInicio(&lista, crearPaciente("Luis Garcia", 50, "Cancer", 1));
    agregarAlInicio(&lista, crearPaciente("Laura Martinez", 28, "Dolor de cabeza", 3));
    agregarAlInicio(&lista, crearPaciente("Pedro Ramirez", 45, "Hipertension", 2));
    agregarAlInicio(&lista, crearPaciente("Sofia Gonzalez", 32, "Asma", 2));
    agregarAlInicio(&lista, crearPaciente("Javier Morales", 29, "Alergia", 3));
    agregarAlInicio(&lista, crearPaciente("Claudia Ruiz", 38, "Gripe", 3));

    // Imprimimos la lista de pacientes
    printf("Lista de pacientes:\n");
    imprimirLista(lista);

    // Se eiminan dos pacientes en especifico
    eliminarPaciente(&lista, "Juan Perez");
    eliminarPaciente(&lista, "Ana Torres");

    // Imprimimos la lista de pacientes después de eliminar
    printf("Lista de pacientes despues de eliminar:\n");
    imprimirLista(lista);
    return 0;
}

Paciente* crearPaciente(char *nombre, int edad, char *diagnostico, int prioridad) {
    // Crea un nuevo paciente y asigna los valores
    Paciente *nuevo = (Paciente*)malloc(sizeof(Paciente));
    if (nuevo == NULL) {
        printf("Error al asignar memoria\n");
        return NULL;
    }
    strcpy(nuevo->nombre, nombre);
    nuevo->edad = edad;
    strcpy(nuevo->diagnostico, diagnostico);
    nuevo->prioridad = prioridad;
    nuevo->siguiente = NULL;
    return nuevo;
}

void imprimirLista(Paciente *lista) {
    // Imprime la lista de pacientes
    if (lista == NULL) {
        printf("No hay pacientes en la lista.\n\n");
        return;
    }
    Paciente *actual = lista;
    while (actual != NULL) {
        printf("Nombre: %s, Edad: %d, Prioridad: %d\n", actual->nombre, actual->edad, actual->prioridad);
        printf("Diagnostico: %s\n", actual->diagnostico);
        actual = actual->siguiente;
    }
    printf("\n");
}

void vaciarLista(Paciente *lista) {
    // Libera la memoria de la lista de pacientes
    Paciente *actual = lista;
    while (actual != NULL) {
        Paciente *temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
}

void agregarAlInicio(Paciente **lista, Paciente *nuevo) {
    // Agrega un nuevo paciente al inicio de la lista y ordena por prioridad
    nuevo->siguiente = *lista;
    *lista = nuevo;
    ordenarLista(lista);
}

int eliminarPaciente(Paciente **lista, char *nombre) {
    // Elimina un paciente de la lista por su nombre
    Paciente *actual = *lista;
    Paciente *anterior = NULL;
    
    while (actual != NULL) {
        if (strcmp(actual->nombre, nombre) == 0) {
            if (anterior == NULL) {
                *lista = actual->siguiente;
            } else {
                anterior->siguiente = actual->siguiente;
            }
            free(actual);
            return 0;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
    return -1;
}

void ordenarLista(Paciente **lista) {
    // Ordena la lista de pacientes por prioridad
    if (*lista == NULL || (*lista)->siguiente == NULL) return;

    Paciente *prioridades[3] = {NULL, NULL, NULL};
    Paciente *finales[3] = {NULL, NULL, NULL};
    Paciente *actual = *lista;

    while (actual != NULL) {
        Paciente *siguiente = actual->siguiente;
        int prioridad = actual->prioridad - 1;
        if (prioridades[prioridad] == NULL) {
            prioridades[prioridad] = actual;
            finales[prioridad] = actual;
        } else {
            finales[prioridad]->siguiente = actual;
            finales[prioridad] = actual;
        }
        actual->siguiente = NULL;
        actual = siguiente;
    }

    Paciente *nuevaLista = NULL;
    Paciente *ultimo = NULL;
    for (int i = 0; i < 3; i++) {
        if (prioridades[i] != NULL) {
            if (nuevaLista == NULL) {
                nuevaLista = prioridades[i];
            } else {
                ultimo->siguiente = prioridades[i];
            }
            ultimo = finales[i];
        }
    }
    *lista = nuevaLista;
}