#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define cant 2

int main()
{
    EPersona lista[cant];
    char seguir='s';
    char charDni[50];
    int opcion=0;

    inicializar (lista, cant);//para inicializar los datos desde 0

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            ingresarPersonas(lista, cant,charDni);
            break;
        case 2:
            eliminarPersonas(lista, cant);
            break;
        case 3:
            ordenarPorNombre(lista, cant);
            break;
        case 4:
            hacerGrafica(lista,cant);
            break;
        case 5:
            activarDni(lista,cant);
            break;
        case 6:
            seguir = 'n';
            break;
        default:
            printf("Ingrese una opcion correcta\n");
            break;
        }
    }
}
