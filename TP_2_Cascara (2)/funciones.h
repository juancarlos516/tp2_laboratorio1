#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    char nombre[50];
    int edad;
    int estado;
    int dni;

} EPersona;

int inicializar(EPersona lista[], int tam);//iniciar desde cero

int obtenerEspacioLibre(EPersona lista[], int tam);//obtener espacio cuando este lleno el array

int buscarPorDni(EPersona lista[], int tam, char charDni[]);//ingresar por dni y buscar por este
int ingresarDni (EPersona lista[], int tam);//necesario para buscarPorDni
int ingresarEdad (EPersona lista[], int tam);//ingresar edad esta validado
int ingresarNombre(char auxString[]);//ingrsar nombre y validarlo
void ingresarPersonas(EPersona lista[], int tam, char charDni[]);//funcion que intrega otras funciones para introducir personas

int eliminarPersonas(EPersona lista[], int tam);
void ordenarPorNombre(EPersona lista[], int tam);

void validarPalabras(char introducirMensaje[],char textoCargado[]);//necesaria para ingresar nombre

void hacerGrafica(EPersona lista[], int tam);
int activarDni(EPersona lista[], int tam);

int atoiGithub(char* c);// se realizo el trabajo en ubunto por lo que atoi no me funciono bien y se copio esta funcion
int exponent(int base, int exp);//necesaria para que funcione atoigithub

#endif // FUNCIONES_H_INCLUDED
