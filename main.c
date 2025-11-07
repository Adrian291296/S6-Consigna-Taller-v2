// main.c
#include <stdio.h>
#include "Funciones.h"

int main() {
    char nombres[10][30];
    float precios[10];
    int n;

    printf("--------------- Ingrese la cantidad de productos (maximo 10): ------------------\n");
    scanf("%d", &n);

    if (n > 10 || n <= 0) {
        printf("Cantidad invalida.\n");
        return 0;
    }

    ingresarDatos(nombres, precios, n);

    int opcion;
    do {
        printf("\n:) -------- MENU DE OPCIONES --------- :p\n");
        printf("1. Mostrar precio total del inventario\n");
        printf("2. Mostrar precio promedio\n");
        printf("3. Mostrar producto mas caro y mas barato\n");
        printf("4. Buscar un producto por nombre\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Precio total del inventario: %.2f\n", calcularTotal(precios, n));
                break;
            case 2:
                printf("Precio promedio: %.2f\n", calcularPromedio(precios, n));
                break;
            case 3:
                productoMayorMenor(nombres, precios, n);
                break;
            case 4:
                buscarProducto(nombres, precios, n);
                break;
            case 5:
                printf("Programa Finalizado\n");
                break;
            default:
                printf("Opcion no valida.\n");
        }

    } while (opcion != 5);

    return 0;
}
