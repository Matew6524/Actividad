#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "lecturas.h"
#include "menu.h"

int main() {
    int cantidadTipos = 0;
    char nombres[100][50];
    int cantidades[100];
    float precios[100];

    // Intenta cargar los productos existentes del archivo al iniciar el programa.
    leerProductosDeArchivo(nombres, cantidades, precios, &cantidadTipos, "productos.txt");

    printf("Bienvenido al sistema de inventario de la farmacia\n");

    int opcion;
    do {
        opcion = mostrarMenu(); // Muestra el menú y espera una opción del usuario.

        switch (opcion) {
            case 1:
                gestionarProducto(nombres, cantidades, precios, &cantidadTipos);
                guardarProductosEnArchivo(nombres, cantidades, precios, cantidadTipos, "productos.txt");
                break;
            case 2:
                mostrarListaProductos("productos.txt"); // Mostrar la lista de productos
                break;
            case 3:
              editarProducto(nombres, cantidades, precios, &cantidadTipos); // Editar producto
                guardarProductosEnArchivo(nombres, cantidades, precios, cantidadTipos, "productos.txt"); // Guardar después de editar
                break;
            case 4:
                quitarProducto(nombres, cantidades, precios, &cantidadTipos); // Quitar producto
                guardarProductosEnArchivo(nombres, cantidades, precios, cantidadTipos, "productos.txt"); // Guardar después de quitar
                break;
            case 5:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción inválida. Intente nuevamente.\n");
        }
    } while (opcion != 5);

    // Guardar cualquier cambio final antes de salir del programa
    guardarProductosEnArchivo(nombres, cantidades, precios, cantidadTipos, "productos.txt");

    return 0;
}

