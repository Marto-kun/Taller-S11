#include <string.h>
#include <stdio.h>
#include <ctype.h>


#define MAX_LIBROS 10
#define MAX_NOMBRE 100
#define MAX_AUTOR 50
// #include "libros.h"

typedef struct
{
    int ID;
    char titulo[MAX_NOMBRE];
    char autor[MAX_AUTOR];
    int pub;
    char estado[10];
} Libro;

/**
 * @brief verifica si el nombre ingresado ya fue registrado
 * @param libro matriz de objetos de la estructura
 * @param nombre cadena ingresada a comprobar
 * @param n cantidad de libros a registrar
 * @return 1 si el nombre existe, 0 si no existe
 */
int existeNombre(Libro libros[], char nombre[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(libros[i].titulo, nombre) == 0)
        {
            return 1;
        }
    }
    return 0;
}

/**
 * @brief verifica si la ID ingresada ya fue registrada
 * @param libro matriz de objetos de la estructura
 * @param ID cadena ingresada a comprobar
 * @param n cantidad de libros a registrar
 * @return 1 si el nombre existe, 0 si no existe
 */
int existeID(Libro libros[], int ID, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (libros[i].ID == ID)
        {
            return 1;
        }
    }
    return 0;
}

/**
 * @brief Funcion para limpieza de buffer
 * evitar buffer overflow
 *
 */
void LimpiarBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

/**
 * @brief Funcion para verificar numeros enteros
 * @param string
 * @return int
 */
int VerificacionDigitos(char string[])
{

    if (strlen(string) == 0)
    {
        return 0; // Comprobar que la cadena no este vacia
    }

    for (int i = 0; i < strlen(string); i++)
    {
        if (!isdigit(string[i]))
        {
            return 0; // Si el elemento de la cadena no es caracter retorna 0
        }
    }
    return 1; // Si la cadena son solo digitos entonces se retorna verdadero
}

/**
 * @brief Funcion para verificar solo letras
 *
 * @param string
 * @return 1 si es verdadero, 0 si es falso
 */
int VerificacionChar(char string[])
{
    if (strlen(string) == 0)
    {
        return 0; // Comprobar que la cadena no este vacia
    }

    size_t len = strlen(string);

    for (int i = 0; i < len; i++)
    {
        if (!isalpha(string[i]))
        {
            return 0; // Si el elemento de la cadena es digito retorna 0
        }
    }
    return 1; // Si la cadena son solo caracteres entonces se retorna 1
}

void ActualEstado(Libro *libros[], char string[]){

}
