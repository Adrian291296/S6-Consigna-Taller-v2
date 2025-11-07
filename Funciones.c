// funciones.c
#include <stdio.h>
#include <string.h>
#include "Funciones.h"

void ingresarDatos(char nombres[][30], float precios[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Ingrese el nombre del producto %d: ", i + 1);
        scanf("%s", nombres[i]);

        printf("Ingrese el precio de %s: ", nombres[i]);
        scanf("%f", &precios[i]);
    }
}

float calcularTotal(float precios[], int n) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += precios[i];
    }
    return total;
}

float calcularPromedio(float precios[], int n) {
    return calcularTotal(precios, n) / n;
}

void productoMayorMenor(char nombres[][30], float precios[], int n) {
    int i_mayor = 0, i_menor = 0;
    for (int i = 1; i < n; i++) {
        if (precios[i] > precios[i_mayor]) i_mayor = i;
        if (precios[i] < precios[i_menor]) i_menor = i;
    }
    printf("\nProducto mas caro: %s (%.2f)\n", nombres[i_mayor], precios[i_mayor]);
    printf("Producto mas barato: %s (%.2f)\n", nombres[i_menor], precios[i_menor]);
}

void buscarProducto(char nombres[][30], float precios[], int n) {
    char buscar[30];
    int encontrado = 0;

    printf("\nIngrese el nombre del producto a buscar: ");
    scanf("%s", buscar);

    for (int i = 0; i < n; i++) {
        if (strcmp(nombres[i], buscar) == 0) {
            printf("El producto %s cuesta %.2f\n", nombres[i], precios[i]);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Producto no encontrado.\n");
    }
}
