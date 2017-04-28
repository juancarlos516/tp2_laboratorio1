#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

/**
 * @brief se introduce estructura y tamaño del ejercicio
 * @param los datos se introducen en una variable auxiliar y se compara los datos con la informacion de la estructura
 * @param  se encuentra muestra los datos en panatalla y pregunta si quiere activarlos, si no cancela operacion
 * @param si se quiere activar se coloca en 1 el estado
 * @return retorna 1 activo o 0 que seria operacion cancelda
 */
int activarDni(EPersona lista[], int tam)
{
    int auxEnt,i, resultado=0;
    char respuesta;

    printf("Ingrese  DNI para activar: ");
    scanf("%d",&auxEnt);

    for(i=0; i<tam; i++)
    {
        if(auxEnt==lista[i].dni)
        {
            printf("estado(%d)\tDNI(%d)\tedad(%d)\tnombre(%s)\n",lista[i].estado,lista[i].dni,lista[i].edad,lista[i].nombre);
            printf("Quiere activar los datos? s/n");
            setbuf(stdin,NULL);
            respuesta=getchar();
            if(respuesta=='s')
            {
                lista[i].estado=1;
                printf("Dato activado\n");
                resultado=lista[i].estado;
            }
            else
            {
                printf("Operacion cancelada\n");
                resultado=lista[i].estado;
            }
        }
    }
    return resultado;
}

/**
 * @brief ingresar estructura y tamaño
 * @param  se hacen contadores para poder sacar el valor maximo de la grafica
 * @param una vez teniendo las cantidades de cada grupo de edad se realiza grafica con *
 * @return void
 */
void hacerGrafica(EPersona lista[], int tam)
{
    int i;

    int conta18=0;
    int conta1935=0;
    int conta35=0;

    int max=0;

    for(i=0; i<tam; i++)
    {
        if(lista[i].edad<=18)
        {
            conta18++;
        }
        if(lista[i].edad>18 && lista[i].edad<35)
        {
            conta1935++;
        }
        if(lista[i].edad>35)
        {
            conta35++;
        }
    }

    if(conta18>conta1935 && conta18>conta35)
    {
        max=conta18;
    }
    else
    {
        if(conta1935>conta18 && conta1935>conta35)
        {
            max=conta1935;
        }
        else
        {
            max=conta35;
        }
    }


    for(i=max; i>0; i--)
    {
        printf("%d",i);

        if(i<=conta18)
        {
            printf("+");
        }
        if (i<=conta1935)
        {
            printf("\t+");
        }
        if(i<=conta35)
        {
            printf("\t\t+");
        }
        printf("\n");
    }

    printf("Gráfico para una estadística de %d personas con edad menor a 18, %d personas con edades entre 19 y 35, y %d personas con edades mayores a 35 \n",conta18,conta1935,conta35);
}

/**
 * @brief se introduce la estructura y el tamaño del ejercicio
 * @param si la cantidad maxima de suarios activos y no activos es mayor a la cantidad del ejercicio, este borrara los estados inactivos para liberar espacio
 * @return 0
 */
int obtenerEspacioLibre(EPersona lista[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        if((lista[i].estado==0)+(lista[i].estado==1)>=tam)
        {
            if(lista[i].estado==0)
            {
                lista[i].dni=0;
            }
        }
    }
    return 0;
}

/**
 * @brief se ingresa estructura tamaño y auxiliar char para verificar dni
 * @param se ingresa dato dni se verifica con la funcion ingresarDni y se le da este resultado a variable llamada resultado
 * @param se valida los datos de resultado
 * @return variable resultado
 */
int buscarPorDni(EPersona lista[], int tam, char charDni[])
{
    int i;
    int resultado=0;

    resultado=ingresarDni(lista,tam);

    for(i=0; i < tam; i++)
    {
        while(lista[i].dni == resultado)
        {
            printf("dato ya ingresado. ");
            if(lista[i].estado==0)
            {
                activarDni(lista,tam);
                resultado=3;
            }
            else
            {
               resultado=ingresarDni(lista,tam);
            }
        }
    }
    return resultado;
}

/**
 * @brief se introduce la estructura y el tamaño del ejercicio
 * @param se realiza comparacion con el metoto de burbujeo
 * @param se imprime en pantalla datos ordenados por nombre
 * @return void
 */
void ordenarPorNombre(EPersona lista[], int tam)
{
    EPersona auxLista;
    int i,j;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(lista[i].nombre,lista[j].nombre)>0)
            {
                auxLista=lista[i];
                lista[i]=lista[j];
                lista[j]=auxLista;
            }
        }
    }
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado>0)
        {
            printf("estado(%d)\tDNI(%d)\tedad(%d)\tnombre(%s)\n",lista[i].estado,lista[i].dni,lista[i].edad,lista[i].nombre);
        }
    }
}

/**
 * @brief se introduce estructura y tamaño del ejercicio
 * @param los datos se introducen en una variable auxiliar y se compara los datos con la informacion de la estructura
 * @param si se encuentra muestra los datosd en panatalla y pregunta si quiere eliminarlos, si no cancela operacion
 * @param si se quiere elimar se coloca en 0 el estado, esto con el fin de si se quiere volver a ingresar este dato no toque introducir toda la informacion de nuevo
 * @return retorna 0 inactivo o 1 que seria operacion cancelda
 */
int eliminarPersonas(EPersona lista[], int tam)
{
    int auxEnt,i, resultado=0;
    char respuesta;

    printf("Ingrese  DNI para desactivar: ");
    scanf("%d",&auxEnt);

    for(i=0; i<tam; i++)
    {
        if(auxEnt==lista[i].dni)
        {
            printf("estado(%d)\tDNI(%d)\tedad(%d)\tnombre(%s)\n",lista[i].estado,lista[i].dni,lista[i].edad,lista[i].nombre);
            printf("Quiere eliminar los datos? s/n");
            setbuf(stdin,NULL);
            respuesta=getchar();
            if(respuesta=='s')
            {
                lista[i].estado=0;
                printf("Dato desactivado\n");
                resultado=lista[i].estado;
            }
            else
            {
                printf("Operacion cancelada\n");
                resultado=lista[i].estado;
            }
        }
    }
    return resultado;
}

/**
 * @brief se introduce estructura, tamaño y variable auxiliar necesaria para comprobar dni
 * @param se verifica que se tenga espacio entre los acgtivos y los que no. y si no lo hay se borran los inactivos
 * @param se ingresa dni, nombre y edad y se activa al usuario si este no esta ingresado anteriormente, de lo contrario solo se activa
 * @param imprime la lista de las personas
 * @return void
 */
void ingresarPersonas(EPersona lista[], int tam, char charDni[])
{
    int i;
    char auxNombre[256];

    obtenerEspacioLibre(lista, tam);

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==0)
        {
            lista[i].dni=buscarPorDni(lista,tam,charDni);

            ingresarNombre(auxNombre);
            strcpy(lista[i].nombre,auxNombre);

            lista[i].edad=ingresarEdad(lista,tam);

            lista[i].estado=1;
        }
    }

    printf("TOTAL DE PERSONAS INGRESADAS");
    for(i=0; i<tam; i++)
    {
        printf("\nestado(%d)\tDNI(%d)\tedad(%d)\tnombre(%s)\n",lista[i].estado,lista[i].dni,lista[i].edad,lista[i].nombre);
    }
}

/**
 * @brief funcion copiada de github ya que el trabajo se realizo con un pc con ubunto y atoi no funcionaba bien
 * @param
 * @param
 * @return
 */
int atoiGithub(char* c)
{
    if (!*c)
    {
        return 0;
    }
    char* tmp = c;
    int arr[12] = {0};
    int cnt = 0;
    while (*tmp && cnt < 12)
    {
        int dec = *tmp - '0';
        if (dec < 0 || dec > 9)
        {
            break;
        }
        else
        {
            arr[cnt++] = dec;
        }
        tmp++;
    }
    int r   = 0;
    int exp = cnt - 1;
    for (int i=0; i < cnt; i++)
    {
        r += arr[i] * exponent(10, exp - i);
    }
    return r;
}

/**
 * @brief necesaria para que atoiGithub funcione
 * @param
 * @param
 * @return
 */
int exponent(int base, int exp) //Necesario para el atoiGithub
{
    if (exp == 0)
    {
        return 1;
    }
    int result = base;
    for (int i=1; i < exp; i++)
    {
        result = result * base;
    }
    return result;
}

/**
 * @brief se introduce estructura y tamaño del ejercicio
 * @param se inicializa valores en 0 de la estructra
 * @return 0
 */
int inicializar(EPersona lista[], int tam)
{
    int i=0;
    for(i=0; i<tam; i++)
    {
        lista[i].nombre[0]='\0';
        lista[i].dni=0;
        lista[i].edad=0;
        lista[i].estado=0;
    }
    return 0;
}

/**
 * @brief se ingresa estructura y tamaño del ejercicio
 * @param se ingresa valo de dni se valida
 * @param valor validado se pasa de string a entero
 * @return retorna valor entero(dni)
 */
int ingresarDni (EPersona lista[], int tam)
{
    char charDni[50];
    int j=0;
    int resultado=0;

    printf("Ingrese DNI: ");
    setbuf(stdin,NULL);
    scanf("%s",charDni);

    while(charDni[j] != '\0')
    {
        if (charDni[j] <'0' || charDni[j] >'9')
        {
            printf("ERROR. Ingrese DNI: ");
            setbuf(stdin,NULL);
            scanf("%s",charDni);
            j=-1;
        }
        j++;
    }
    resultado=atoiGithub(charDni);
    return resultado ;
}

/**
 * @brief se ingresa estructura y tamaño de la estructura
 * @param se valida
 * @param se pasa de string a entero
 * @return retorna entero
 */
int ingresarEdad (EPersona lista[], int tam)
{
    char charEdad[50];
    int j=0;
    int resultado=0;

    printf("Ingrese edad ");
    setbuf(stdin,NULL);
    scanf("%s",charEdad);

    while(charEdad[j] != '\0')
    {
        if (charEdad[j] <'0' || charEdad[j] >'9')
        {
            printf("ERROR. Ingrese edad ");
            setbuf(stdin,NULL);
            scanf("%s",charEdad);
            j=-1;
        }
        j++;
    }
    resultado=atoiGithub(charEdad);
    return resultado ;
}

/**
 * @brief se carga la variable donde quedara al final el string
 * @param en una variable tipo char auxiliar se almacena los datos
 * @param se valida
 * @param se copia a la variable final
 * @return retorna 1 so solo tiene letras
 */
int ingresarNombre(char auxString[])
{
    char aux[256];
    int i=0;

    printf("Ingrese nombre: ");
    scanf ("%s", aux);

    while(aux[i] != '\0')
    {
        if((aux[i] != ' ') && (aux[i] < 'a' || aux[i] > 'z') && (aux[i] < 'A' || aux[i] > 'Z'))
        {
            printf("ERROR. Ingrese nombre: ");
            scanf ("%s", aux);
        }
        i++;
    }
    strcpy(auxString,aux);
    return 1;
}

