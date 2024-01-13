// lecturas.c
#include <stdio.h>
#include "lecturas.h"

int leerEnteroPositivo(char* mensaje) {
    int valor;
    do {
        printf("%s", mensaje);
        scanf("%d", &valor);
    } while (valor <= 0);
    return valor;
}

int leerEntero(char* mensaje) {
    int valor;
    printf("%s", mensaje);
    scanf("%d", &valor);
    return valor;
}

int leerEnteroEntre(char* mensaje, int min, int max) {
    int valor;
    do {
        printf("%s", mensaje);
        scanf("%d", &valor);
    } while (valor < min || valor > max);
    return valor;
}

float leerFlotantePositivo(char* mensaje) {
    float valor;
    do {
        printf("%s", mensaje);
        scanf("%f", &valor);
    } while (valor <= 0);
    return valor;
}

float leerFlotante(char* mensaje) {
    float valor;
    printf("%s", mensaje);
    scanf("%f", &valor);
    return valor;
}

float leerFlotanteEntre(char* mensaje, int min, int max) {
    float valor;
    do {
        printf("%s", mensaje);
        scanf("%f", &valor);
    } while (valor < min || valor > max);
    return valor;
}

char leerCaracter(char* mensaje){
    char valor;
    printf("%s", mensaje);
    // Consume cualquier carácter de nueva línea que haya quedado en el buffer
    while((getchar()) != '\n');
    scanf("%c", &valor);
    return valor;
}
