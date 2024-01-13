#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

int mostrarMenu() {
    int opcion;

    printf("\nMenú:\n");
    printf("1. Agregar un nuevo producto\n");
    printf("2. Mostrar lista de productos\n");
    printf("3. Editar producto\n");
    printf("4. Quitar un producto\n");
    printf("5. Salir\n");

    printf("Seleccione una opción: ");
    scanf("%d", &opcion);

    return opcion;
}
