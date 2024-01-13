#include <stdio.h>
#include <string.h>
#include "funciones.h"

void mostrarListaProductos(const char* nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }
    printf("\nLista de productos ingresados:\n");
    char nombre[50];
    int cantidad;
    float precio;
    while (fscanf(archivo, "%49s %d %f\n", nombre, &cantidad, &precio) == 3) {
        printf("Nombre: %s\n", nombre);
        printf("Cantidad: %d\n", cantidad);
        printf("Precio: %.2f\n", precio);
        printf("\n");
    }
    fclose(archivo);
}

void editarProducto(char nombres[][50], int cantidades[], float precios[], int *cantidadTipos) {
    int opcion;
    printf("Ingrese el número del producto que desea editar: ");
    scanf("%d", &opcion);

    if (opcion > 0 && opcion <= *cantidadTipos) {
        gestionarProducto(nombres, cantidades, precios, cantidadTipos);
        printf("Producto editado con éxito.\n");
    } else {
        printf("Número de producto inválido.\n");
    }
}

void guardarProductosEnArchivo(char nombres[][50], int cantidades[], float precios[], int cantidadTipos, const char* nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "w"); 
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return;
    }

    for (int i = 0; i < cantidadTipos; i++) {
        fprintf(archivo, "%s %d %.2f\n", nombres[i], cantidades[i], precios[i]);
    }

    fclose(archivo);
    printf("Los productos han sido guardados en '%s'.\n", nombreArchivo);
}

void leerProductosDeArchivo(char nombres[][50], int cantidades[], float precios[], int* cantidadTipos, const char* nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }
    *cantidadTipos = 0;
    while (fscanf(archivo, "%49s %d %f\n", nombres[*cantidadTipos], &cantidades[*cantidadTipos], &precios[*cantidadTipos]) == 3) {
        (*cantidadTipos)++;
    }
    fclose(archivo);
    printf("Productos leídos del archivo.\n");
}

void gestionarProducto(char nombres[][50], int cantidades[], float precios[], int *cantidadTipos) {
    char nombreTemp[50];
    int cantidadTemp;
    float precioTemp;
    int productoExistente = -1;

    printf("Ingrese el nombre del producto que desea agregar o editar: ");
    scanf("%49s", nombreTemp);

    // Buscar si el producto ya existe
    for (int i = 0; i < *cantidadTipos; i++) {
        if (strcmp(nombres[i], nombreTemp) == 0) {
            productoExistente = i;
            break;
        }
    }

    printf("Ingrese la cantidad del producto: ");
    scanf("%d", &cantidadTemp);
    printf("Ingrese el precio del producto: ");
    scanf("%f", &precioTemp);

    if (productoExistente != -1) {
        // Producto existe, actualizar cantidad y precio
        cantidades[productoExistente] += cantidadTemp;
        precios[productoExistente] = precioTemp;
        printf("Producto actualizado con éxito.\n");
    } else {
        // Producto no existe, agregar como nuevo si hay espacio
        if (*cantidadTipos < 100) {
            strcpy(nombres[*cantidadTipos], nombreTemp);
            cantidades[*cantidadTipos] = cantidadTemp;
            precios[*cantidadTipos] = precioTemp;
            (*cantidadTipos)++;
            printf("Producto agregado con éxito. Ahora hay %d productos.\n", *cantidadTipos);
        } else {
            printf("Se ha alcanzado el número máximo de productos.\n");
        }
    }
}

void quitarProducto(char nombres[][50], int cantidades[], float precios[], int* cantidadTipos) {
    char nombreTemp[50];
    printf("Ingrese el nombre del producto que desea quitar: ");
    scanf("%49s", nombreTemp);

    int indice = -1;

    for (int i = 0; i < *cantidadTipos; i++) {
        if (strcmp(nombres[i], nombreTemp) == 0) {
            indice = i;
            break;
        }
    }

    if (indice != -1) {
        // Encontrado, quitar el producto
        for (int i = indice; i < *cantidadTipos - 1; i++) {
            strcpy(nombres[i], nombres[i + 1]);
            cantidades[i] = cantidades[i + 1];
            precios[i] = precios[i + 1];
        }
        (*cantidadTipos)--;
        printf("Producto quitado con éxito.\n");
    } else {
        printf("Producto no encontrado.\n");
    }
}