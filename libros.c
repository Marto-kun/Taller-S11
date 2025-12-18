#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define MAX_LIBROS 10
#define MAX_NOMBRE 100
#define MAX_AUTOR 50
#define MAX_ESTADO 10
// #include "libros.h"

typedef struct
{
    int ID;
    char titulo[MAX_NOMBRE];
    char autor[MAX_AUTOR];
    int pub;
    char estado[MAX_ESTADO];
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

/**
 * @brief Funcion para verificar solo letras con espacios
 *
 * @param string
 * @return int
 */
int VerificacionCharEspacios(char string[])
{
    if (strlen(string) == 0)
    {
        return 0; // Comprobar que la cadena no este vacia
    }

    size_t len = strlen(string);

    for (int i = 0; i < len; i++)
    {
        if (!isalpha(string[i]) && string[i] != ' ')
        {
            return 0; // Si el elemento de la cadena es digito retorna 0
        }
    }
    return 1; // Si la cadena son solo caracteres o espacios entonces se retorna 1
}

/**
 * @brief Funcion para buscar libros por ID
 *
 * @param libros vector de la estructura libros
 * @param entrada busqueda del usuario
 * @return int la posicion en el vector del libro buscado
 */
int buscarProductoID(Libro libros[], int entrada)
{
    for (int i = 0; i < MAX_LIBROS; i++)
    {
        if (libros[i].ID == entrada)
        {
            return i;
        }
    }
    return -1;
}

/**
 * @brief Funcion para buscar libros por TITULO
 *
 * @param libros vector de la estructura libros
 * @param nombreBuscado Busqueda del usuario
 * @return int la posicion en el vector del libro buscado
 */
int buscarProducto(Libro libros[], char nombreBuscado[])
{
    for (int i = 0; i < MAX_LIBROS; i++)
    {
        if (strcmp(libros[i].titulo, nombreBuscado) == 0)
        {
            return i;
        }
    }
    return -1;
}

/**
 * @brief Muestra la lista completa de libros en formato de tabla.
 * @param libros vector de la estructura Libro
 * @param n cantidad actual de libros registrados
 */
void MostrarTabla(Libro libros[], int n)
{
    if (n == 0)
    {
        printf("\nLa biblioteca esta vacia. No hay libros registrados.\n");
        return;
    }

    printf("\n\n+-----+---------------------------------------------------------------------------------------------------+---------------------------------------------------+------+------------+\n");
    printf("| ID  | TITULO                                                                                              | AUTOR                                             | ANIO | ESTADO     |\n");
    printf("+-----+---------------------------------------------------------------------------------------------------+---------------------------------------------------+------+------------+\n");
    
    // Iterar solo sobre los 'n' libros registrados
    for (int i = 0; i < n; i++)
    {
        printf("| %-3d | %-99.99s | %-49.49s | %-4d | %-10s |\n",
               libros[i].ID, libros[i].titulo, libros[i].autor, libros[i].pub, libros[i].estado);
    }
    printf("+-----+---------------------------------------------------------------------------------------------------+---------------------------------------------------+------+------------+\n\n");
}

/**
 * @brief Elimina un libro del vector moviendo los elementos restantes
 * y actualizando la cantidad total de libros.
 * @param libros vector de la estructura Libro
 * @param n puntero a la cantidad actual de libros registrados
 * @param ID ID del libro a eliminar
 * @return 1 si el libro fue eliminado, 0 si no se encontro la ID
 */
int EliminarLibro(Libro libros[], int *n, int ID)
{
    int index = buscarProductoID(libros, ID); // Reutiliza la función de búsqueda por ID

    if (index == -1)
    {
        return 0; // ID no encontrada
    }

    // Mover los elementos posteriores una posición hacia adelante
    for (int i = index; i < (*n) - 1; i++)
    {
        libros[i] = libros[i + 1];
    }

    // Decrementar la cantidad de libros
    (*n)--;

    return 1; // Eliminación exitosa
}